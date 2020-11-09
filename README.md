# BadUSB

Sample BadUSB with Digispark ATTiny85

## Installation

1. ติดตั้ง **Arduino IDE**
2. เปิด **Arduino IDE** ขึ้นมา แล้วไปที่ **File >> Preferences** ในช่อง Additional Board Manager URLs: ให้ copy link นี้ไปวาง >> [http://digistump.com/package_digistump_index.json](http://digistump.com/package_digistump_index.json) แล้วก็กด OK
3. เข้าไปที่ **Tools >> Board >> Boards Manager** แล้วให้ ติดตั้ง **Digistump AVR Boards by Digistump**
4. ไปที่ **Tools >> Board** แล้วเลือก**บอร์ด DigiSpark (Default – 16.5 MHz)**

- **[MacOS - Complied Fix]** avr-g++: bad CPU type in executable Error compiling for board Digispark

  ```Bash
  cd ~/Library/Arduino15/packages/arduino/tools/avr-gcc
  mv 4.8.1-arduino5 orig.4.8.1
  ln -s /Applications/Arduino.app/Contents/Java/hardware/tools/avr 4.8.1-arduino5
  ```
