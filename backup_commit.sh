#!/usr/bin/env zsh

# Update git repo with these changes
cd ~/dev/keyboard/Backup_bin_firmwares/ || exit
git add ~/dev/keyboard/Backup_bin_firmwares/*
git commit -am "chore(qmk): automatic update of the qmk firmwares"
git push
