#! /bin/bash

set -x

cd "$( dirname "${BASH_SOURCE[0]}" )"

qmk compile -km hrm -kb handwired/dactyl_manuform/5x6_dart

echo "reset it"

sleep 5

while true; do
    dev=$(find /dev -maxdepth 1 -name 'cu.usbmodem*' | grep 142101)
    if [ -n "$dev" ]; then
        /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude \
            -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v \
            -patmega32u4 -cavr109 -P$dev -b57600 -D \
            -Uflash:w:/Users/jonathan.dart/repo/qmk_firmware/handwired_dactyl_manuform_5x6_dart_hrm.hex:i
        exit
    fi
    sleep 1
done
