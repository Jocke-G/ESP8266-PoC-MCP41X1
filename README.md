# ESP8266 - Proof of Concept - MCP41X1 Digital Potentiometer

A proof of Concept for connecting a MCP41X1 digital potentiometer to a ESP8266.

## IMPORTANT

I havent got it working yet.

Currently, when writing 35, which I thought would mean 665Ω, my multimeter shows 1920Ω. Than, when writing 36, my multimeter just says 1.

So far, I have tried both manual way from learningaboutelectronics.com, and jmalloc's labrary. Links to both can be found in the bottom.

## How to connect

|  MCP41X1 pin  |  ESP8266 Pin                        |  Comment             |
|---------------|-------------------------------------|----------------------|
|  1 - CS       |  D8 (Configurable, any digital pin) |                      |
|  2 - SCLK     |  D5 - SCLK                          |                      |
|  3 - MOSI     |  D7 - MOSI                          |                      |
|  4 - GND      |  GND                                |                      |
|  5 - PA0      |  3v3                                |                      |
|  6 - P0W      |  -                                  |  To + on multimeter  |
|  7 - P0B      |  GND                                |                      |
|  8 - VDD      |  3v3                                |                      |
|  -            |  GND                                |  To - on multimeter  |

## MCP41X1

For this poc, I used a MCP4151-502E/P

MCP: Multi-chip package

4: ???

1: Digital Potentiometer

5: 8-bit (255 wiper steps), 0-255

1: Single pot

502: 5kΩ

E/P: Form factor

### Model description

    MCP 4 X Y Z
          │ │ │
          │ │ └── (Z) Wiper Configuration
          │ │         1 = Potentiometer, 2 = Rheostat
          │ │
          │ └──── (Y) Memory Type / Resolution
          │           3 = 7-bit RAM, 4 = 7-bit EEPROM, 5 = 8-bit RAM, 6 = 8-bit EEPROM
          │
          └────── (X) Number of pots
                      1 or 2

### Pinout

             +----U----+
    1/CS   --+ O       +-- 8/VDD
             |         |
    2/SCLK --+         +-- 7/P0B (One terminal of the potentiometer)
             |         |
    3/MOSI --+         +-- 6/P0W (Wiper terminal of the potentiometer)
             |         |
    4/GND  --+         +-- 5/PA0 (One terminal of the potentiometer)
             +---------+

## Wemos D1

Pinout:
https://www.wemos.cc/en/latest/d1/d1_mini.html#pin

## Libraries

https://www.arduino.cc/reference/en/language/functions/communication/spi/

### Considered - Not used

https://github.com/ArduinoMax/MCP41xxx

https://github.com/jmalloc/arduino-mcp4xxx

## References

http://www.learningaboutelectronics.com/Articles/MCP4131-digital-potentiometer-circuit.php
