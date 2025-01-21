#!/bin/sh
rm log/*

qmk config set user.qmk_home=/Users/chris/dev/Keyboard/qmk/qmk_keychron
qmk compile --parallel 0 -kb keychron/q60_max/ansi -km chrisgve >>log/q60_max.log 2>&1

qmk config set user.qmk_home=/Users/chris/dev/Keyboard/qmk/qmk_firmware
qmk compile --parallel 0 -kb bemeier/bmek/rev3 -km chrisgve >>log/bmek.log 2>&1
qmk compile --parallel 0 -kb cannonkeys/adelie -km chrisgve >>log/adelie.log 2>&1
qmk compile --parallel 0 -kb cannonkeys/instant60 -km chrisgve >>log/instant60.log 2>&1
qmk compile --parallel 0 -kb cannonkeys/savage65 -km chrisgve >>log/savage65.log 2>&1
qmk compile --parallel 0 -kb dz60 -km chrisgve >>log/dz60.log 2>&1
qmk compile --parallel 0 -kb dztech/dz60rgb_wkl/v2_1 -km chrisgve >>log/dz60rgb_wkl.log 2>&1
qmk compile --parallel 0 -kb dztech/dz65rgb/v3 -km chrisgve >>log/dz65rgb.log 2>&1
qmk compile --parallel 0 -kb emery65 -km chrisgve >>log/emery65.log 2>&1
qmk compile --parallel 0 -kb hineybush/h60 -km chrisgve >>log/h60.log 2>&1
qmk compile --parallel 0 -kb kbdfans/baguette66/rgb -km chrisgve >>log/baguette66.log 2>&1
qmk compile --parallel 0 -kb kbdfans/kbd67/rev2 -km chrisgve >>log/kbd67.log 2>&1
qmk compile --parallel 0 -kb kbdfans/kbdpad/mk2 -km chrisgve >>log/kbdpad.log 2>&1
qmk compile --parallel 0 -kb kbdfans/odin/soldered -km chrisgve >>log/odin.log 2>&1
qmk compile --parallel 0 -kb keebsforall/freebirdnp/pro -km chrisgve >>log/freebirdnp.log 2>&1
qmk compile --parallel 0 -kb keebsforall/freebirdtkl -km chrisgve >>log/freebirdtkl.log 2>&1
qmk compile --parallel 0 -kb kopibeng/mnk65_stm32 -km chrisgve >>log/mnk65.log 2>&1
qmk compile --parallel 0 -kb mechlovin/adelais/standard_led/arm/rev4/apm32f103 -km chrisgve >>log/adelais_apm32f103_chrisgve.log 2>&1
qmk compile --parallel 0 -kb mechlovin/adelais/standard_led/arm/rev4/apm32f103 -km chrisgve_hhkb >>log/adelais_apm32f103_chrisgve_hhkb.log 2>&1
qmk compile --parallel 0 -kb mechlovin/adelais/standard_led/arm/rev4/stm32f303 -km chrisgve_hhkb >>log/adelais_stm32f303_chrisgve_hhkb.log 2>&1
qmk compile --parallel 0 -kb mechlovin/zed60 -km chrisgve_hhkb >>log/zed60.log 2>&1
qmk compile --parallel 0 -kb mode/m65s -km chrisgve >>log/m65s.log 2>&1
qmk compile --parallel 0 -kb quarkeys/z60/solder -km chrisgve >>log/z60.log 2>&1
qmk compile --parallel 0 -kb windstudio/wind_x/r1 -km chrisgve >>log/wind_x.log 2>&1
qmk compile --parallel 0 -kb zlant_xl -km chrisgve >>log/zlant_xl.log 2>&1

rg -i error log
