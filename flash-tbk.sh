#! /bin/bash

set -x

cd "$( dirname "${BASH_SOURCE[0]}" )"

qmk compile -km default -kb bastardkb/tbkmini


echo "reset it"

sleep 5

while true; do
    dev=$(find /dev -maxdepth 1 -name 'cu.usbmodem*')
    if [ -n "$dev" ]; then
        /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude \
            -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v \
            -patmega32u4 -cavr109 -P$dev -b57600 -D \
            -Uflash:w:/Users/jonathan.dart/repo/qmk_firmware/bastardkb_tbkmini_default.hex:i
        exit
    fi
done

# while true; do
#     # Find the Arduino port
#     ARDUINO_UPLOAD_PORT="$(find /dev/cu.usbmodem* | grep -v 142101 | head -n 1)"
#     if [ -n "$dev" ]; then
#         stty -f "${ARDUINO_UPLOAD_PORT}" 1200
#         sleep 0.5


#     fi
# done


# Reset the Arduino
