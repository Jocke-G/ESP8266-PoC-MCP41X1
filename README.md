# ESP - Proof of Concept - MCP41X1 Digital Potentiometer

A proof of Concept for connecting a MCP41X1 digital potentiometer to a ESP32 and ESP8266.

## Lessons Learned

Data sheet specifies 2.7V to 5.5V, but resistance seems to be more accurate on 5v than 3.3v.

Measure your pots wiper resistance and max resistance. They varies by temerature, and probably between chips. And remember, the curve is not perfectly linear. You can use this sketch to test it out.

## How to connect

|  MCP41X1 Pin  |  ESP8266 Pin  |  ESP32 Pin  |  Serial Peripheral Interface  |  Comment                        |
|---------------|---------------|-------------|-------------------------------|---------------------------------|
|  1 - CS       |  15/D8        |  5          |  Chip Select/Slave Select     |  Configurable, any digital pin  |
|  2 - SCLK     |  14/D5        |  18         |  Serial Clock                 |                                 |
|  3 - MOSI     |  13/D7        |  23         |  Master Output                |                                 |
|  4 - VSS      |  GND          |  GND        |                               |                                 |
|  5 - PA0      |  -            |  -          |                               |                                 |
|  6 - PW0      |  -            |  -          |                               |  To + on multimeter             |
|  7 - PB0      |  -            |  -          |                               |  To - on multimeter             |
|  8 - VDD      |  5v           |  5v         |                               |                                 |

## MCP41X1

For this poc, a MCP4151-502E/P was used.

[Datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/22060b.pdf)

MCP: Multi-chip package

4: ???

1: Digital Potentiometer

5: 8-bit (255 wiper steps), 0-255

1: Single pot

502: 5kΩ

E: -40°C to +125°C (Extended)
P: Plastic Dual In-line (PDIP)

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
    2/SCLK --+         +-- 7/PB0 (One terminal of the potentiometer)
             |         |
    3/MOSI --+         +-- 6/PW0 (Wiper terminal of the potentiometer)
             |         |
    4/GND  --+         +-- 5/PA0 (One terminal of the potentiometer)
             +---------+

## ESP

For this poc, two different ESP:s was used.

[Wemos D1 Mini (ESP8266)](https://www.wemos.cc/en/latest/d1/d1_mini.html#pin)

[ESP32-DevKitC V4](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html#pin-layout)

## Libraries

https://www.arduino.cc/reference/en/language/functions/communication/spi/

### Considered - Not used

https://github.com/ArduinoMax/MCP41xxx

https://github.com/jmalloc/arduino-mcp4xxx

## References

http://www.learningaboutelectronics.com/Articles/MCP4131-digital-potentiometer-circuit.php
