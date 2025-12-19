#!/usr/bin/env zsh
# keymap_rename.sh
# Apply many literal string replacements across files named keymap.c.
#
# Mapping file format (one mapping per line):
#   "FROM" => "TO"
#
# Examples:
#   "KC_MS_L," => "MS_LEFT,"
#   "KC_MS_U"  => "MS_UP,  "
#   "KC_ACL0"  => "MS_ACCEL0"
#   "KC_WH_U"  => "MS_WHEEL_UP"
#   "KC_BTN1"  => "MS_BTN1"
#
# Notes:
# - Both sides are quoted so there is no ambiguity.
# - FROM/TO may include commas and spaces (use them to preserve formatting).
# - Replacements are literal substring replacements (not regex, no token boundaries).
# - Mappings are applied longest-FROM-first to reduce overlap issues.

set -euo pipefail

usage() {
  cat <<'EOF'
Usage:
  keymap_rename.sh -m mappings.txt [--apply|--dry-run] [--root PATH]

Options:
  -m, --map FILE    Mapping file with lines like: "FROM" => "TO"
  --root PATH       Root directory to search (default: .)
  --dry-run         Show which keymap.c files would change (default)
  --apply           Modify files in place
EOF
}

MAP=""
ROOT="."
MODE="dry"

while (( $# )); do
  case "$1" in
    -m|--map) MAP="$2"; shift 2;;
    --root) ROOT="$2"; shift 2;;
    --dry-run) MODE="dry"; shift;;
    --apply) MODE="apply"; shift;;
    -h|--help) usage; exit 0;;
    *) print -u2 "Unknown arg: $1"; usage; exit 2;;
  esac
done

if [[ -z "$MAP" || ! -f "$MAP" ]]; then
  print -u2 "Missing or unreadable mapping file: $MAP"
  usage
  exit 2
fi

# Only operate on files named keymap.c (under ROOT). Robust to spaces in paths.
files=( )
while IFS= read -r -d '' f; do
  files+=("$f")
done < <(rg -l0 --glob 'keymap.c' '.' "$ROOT" 2>/dev/null || true)

if (( ${#files[@]} == 0 )); then
  print "No keymap.c files found under: $ROOT"
  exit 0
fi

# Perl program (heredoc avoids zsh $'..' quoting pitfalls).
perl_prog=$(cat <<'PERL'
use strict;
use warnings;

my $mapfile = $ENV{MAPFILE} or die "MAPFILE not set\n";
open my $fh, "<", $mapfile or die "open $mapfile: $!\n";
local $/ = undef;
my $all = <$fh>;
close $fh;

$all =~ s/\r\n/\n/g;
$all =~ s/\r/\n/g;

my @pairs;
for my $line (split /\n/, $all) {
  $line =~ s/^\s+|\s+$//g;
  next if $line eq q{} || $line =~ /^#/;

  if ($line =~ /^"((?:[^"\\]|\\.)*)"\s*=>\s*"((?:[^"\\]|\\.)*)"\s*$/) {
    my ($from, $to) = ($1, $2);
    for ($from, $to) {
      s/\\"/"/g;
      s/\\n/\n/g;
      s/\\t/\t/g;
    }
    push @pairs, [$from, $to];
  } else {
    die "Bad mapping line: $line\n";
  }
}
close $fh;

# Longest FROM first to reduce overlap issues (e.g., KC_BTN10 vs KC_BTN1)
@pairs = sort { length($b->[0]) <=> length($a->[0]) } @pairs;

for my $p (@pairs) {
  my ($from, $to) = @$p;
  next if $from eq $to;
  s/\Q$from\E/$to/g;
}
PERL
)

changed=0
export MAPFILE="$MAP"

if [[ "$MODE" == "dry" ]]; then
  for f in "${files[@]}"; do
    tmp="$(mktemp)"
    cp -- "$f" "$tmp"

    perl -0777 -pe "$perl_prog" -- "$tmp" > "${tmp}.out"

    if ! cmp -s -- "$tmp" "${tmp}.out"; then
      print "$f"
      changed=1
    fi

    rm -f -- "$tmp" "${tmp}.out"
  done

  if (( changed == 0 )); then
    print "No changes would be made."
  else
    print "(dry-run) Files listed above would change. Re-run with --apply to modify in place."
  fi
else
  for f in "${files[@]}"; do
    tmp="$(mktemp)"
    cp -- "$f" "$tmp"

    perl -0777 -pe "$perl_prog" -- "$tmp" > "${tmp}.out"

    if ! cmp -s -- "$tmp" "${tmp}.out"; then
      cat -- "${tmp}.out" > "$f"
      print "updated: $f"
      changed=1
    fi

    rm -f -- "$tmp" "${tmp}.out"
  done

  if (( changed == 0 )); then
    print "No files needed updating."
  fi
fi

