#!/bin/zsh
QMK_ROOT="$HOME/dev/keyboard/qmk"
QMK_USERSPACE="$QMK_ROOT/qmk_userspace"
QMK_USERSPACE_LOG="$QMK_USERSPACE/log"
QMK_OG="$QMK_ROOT/qmk_firmware"
QMK_KEYCHRON="$QMK_ROOT/qmk_keychron"
QMK_NEO="$QMK_ROOT/qmk_neo"
QMK_YDKB="$QMK_ROOT/qmk_ydkb"
BRANCH_OG="dev"
BRANCH_KEYCHRON="wireless_playground_apple"

# Reset the logs
if [[ -d "$QMK_USERSPACE_LOG" ]]; then
    rm -rf "$QMK_USERSPACE_LOG"
else
    mkdir -p "$QMK_USERSPACE_LOG"
fi

cd "$QMK_KEYCHRON"
git checkout "$BRANCH_KEYCHRON"
cd "$QMK_USERSPACE"
qmk config set user.qmk_home=/Users/chris/dev/Keyboard/qmk/qmk_keychron
qmk compile --parallel 0 -kb keychron/q60_max/ansi -km chrisgve >>"$QMK_USERSPACE_LOG/q60_max.log" 2>&1

cd "$QMK_OG"
git checkout "$BRANCH_OG"
cd "$QMK_USERSPACE"
qmk config set user.qmk_home=/Users/chris/dev/Keyboard/qmk/qmk_firmware
qmk compile --parallel 0 -kb bemeier/bmek/rev3 -km chrisgve >>"$QMK_USERSPACE_LOG/bmek.log" 2>&1
qmk compile --parallel 0 -kb cannonkeys/adelie -km chrisgve >>"$QMK_USERSPACE_LOG/adelie.log" 2>&1
qmk compile --parallel 0 -kb cannonkeys/instant60 -km chrisgve >>"$QMK_USERSPACE_LOG/instant60.log" 2>&1
qmk compile --parallel 0 -kb cannonkeys/savage65 -km chrisgve >>"$QMK_USERSPACE_LOG/savage65.log" 2>&1
qmk compile --parallel 0 -kb dz60 -km chrisgve >>"$QMK_USERSPACE_LOG/dz60.log" 2>&1
qmk compile --parallel 0 -kb dztech/dz60rgb_wkl/v2_1 -km chrisgve >>"$QMK_USERSPACE_LOG/dz60rgb_wkl.log" 2>&1
qmk compile --parallel 0 -kb dztech/dz65rgb/v3 -km chrisgve >>"$QMK_USERSPACE_LOG/dz65rgb.log" 2>&1
qmk compile --parallel 0 -kb dztech/tofu60 -km chrisgve >>"$QMK_USERSPACE_LOG/tofu60.log" 2>&1
qmk compile --parallel 0 -kb emery65 -km chrisgve >>"$QMK_USERSPACE_LOG/emery65.log" 2>&1
qmk compile --parallel 0 -kb hineybush/h60 -km chrisgve >>"$QMK_USERSPACE_LOG/h60.log" 2>&1
qmk compile --parallel 0 -kb kbdfans/baguette66/rgb -km chrisgve >>"$QMK_USERSPACE_LOG/baguette66.log" 2>&1
qmk compile --parallel 0 -kb kbdfans/kbd67/rev2 -km chrisgve >>"$QMK_USERSPACE_LOG/kbd67.log" 2>&1
qmk compile --parallel 0 -kb kbdfans/kbdpad/mk2 -km chrisgve >>"$QMK_USERSPACE_LOG/kbdpad.log" 2>&1
qmk compile --parallel 0 -kb kbdfans/odin/soldered -km chrisgve >>"$QMK_USERSPACE_LOG/odin.log" 2>&1
qmk compile --parallel 0 -kb keebsforall/freebirdnp/pro -km chrisgve >>"$QMK_USERSPACE_LOG/freebirdnp.log" 2>&1
qmk compile --parallel 0 -kb keebsforall/freebirdtkl -km chrisgve >>"$QMK_USERSPACE_LOG/freebirdtkl.log" 2>&1
qmk compile --parallel 0 -kb keycult/keycult_zero -km chrisgve >>"$QMK_USERSPACE_LOG/keycult_zero.log" 2>&1
qmk compile --parallel 0 -kb kopibeng/mnk65_stm32 -km chrisgve >>"$QMK_USERSPACE_LOG/mnk65.log" 2>&1
qmk compile --parallel 0 -kb mechlovin/adelais/standard_led/arm/rev4/apm32f103 -km chrisgve >>"$QMK_USERSPACE_LOG/adelais_apm32f103_chrisgve.log" 2>&1
qmk compile --parallel 0 -kb mechlovin/adelais/standard_led/arm/rev4/apm32f103 -km chrisgve_hhkb >>"$QMK_USERSPACE_LOG/adelais_apm32f103_chrisgve_hhkb.log" 2>&1
qmk compile --parallel 0 -kb mechlovin/adelais/standard_led/arm/rev4/stm32f303 -km chrisgve_hhkb >>"$QMK_USERSPACE_LOG/adelais_stm32f303_chrisgve_hhkb.log" 2>&1
qmk compile --parallel 0 -kb mechlovin/zed60 -km chrisgve >>"$QMK_USERSPACE_LOG/zed60.log" 2>&1
qmk compile --parallel 0 -kb mode/m65s -km chrisgve >>"$QMK_USERSPACE_LOG/m65s.log" 2>&1
qmk compile --parallel 0 -kb quarkeys/z60/solder -km chrisgve >>"$QMK_USERSPACE_LOG/z60.log" 2>&1
qmk compile --parallel 0 -kb windstudio/wind_x/r1 -km chrisgve >>"$QMK_USERSPACE_LOG/wind_x.log" 2>&1
qmk compile --parallel 0 -kb ymdk/oni_hhkb -km chrisgve >> "$QMK_USERSPACE_LOG/oni_hhkb.log" 2>&1
qmk compile --parallel 0 -kb zlant_xl -km chrisgve >>"$QMK_USERSPACE_LOG/zlant_xl.log" 2>&1

rg -i error log
