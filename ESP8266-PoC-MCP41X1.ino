#include <Arduino.h>

#include "MCP41X1.h"

#define CS_PIN 17
#define POT_STEPS 256
#define MAX_OHMS 5090
#define WIPER_RESISTANCE 103
#define SERIAL_BAUDRATE 115200

MCP41X1 digiPot = MCP41X1(CS_PIN, MAX_OHMS, WIPER_RESISTANCE, POT_STEPS);

bool throwNext = false;
bool insertResistance = false;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  while (!Serial) {}
  Serial.println("\n\r=== setup() ===");

  Serial.println("== SPI Pins");
  Serial.printf("MOSI\t\t\t%d\n\r", MOSI);
  Serial.printf("MISO\t\t\t%d\n\r", MISO);
  Serial.printf("SCK\t\t\t%d\n\r", SCK);
  Serial.printf("Default CS/SS\t\t%d\n\r", SS);
  Serial.printf("Selected CS/SS\t\t%d\n\r", CS_PIN);

  Serial.println("== Pot characteristics");
  Serial.printf("Steps\t\t\t%d\n\r", POT_STEPS);
  Serial.printf("Max Ohms\t\t%d\n\r", MAX_OHMS);
  Serial.printf("Wiper Resistance\t%d\n\r", WIPER_RESISTANCE);
  float perStep = digiPot.getResistancePerStep();
  Serial.printf("Per Step\t\t%f\n\r", perStep);

  digiPot.init();
  Serial.println("Setup Completed");
}

void loop() {
  if (!throwNext) {
    if (insertResistance) {
      Serial.println("Insert Resistance mode. Type -1 to switch mode.");
    } else {
      Serial.println("Insert Step mode. Type -1 to switch mode.");
    }
  }

  while (Serial.available() == 0) {}
  int value = Serial.parseInt();
  if (throwNext) {
    throwNext = false;
    return;
  }

  throwNext = true;

  if (value == -1) {
    insertResistance = !insertResistance;
    return;
  }

  Serial.println("=== New value received from Serial ===");

  int step = value;

  if (insertResistance) {
    Serial.printf("Resistance\t\t%d\n\r", value);
    step = digiPot.calculateSteps(value);
  }

  Serial.printf("Step\t\t\t%d\n\r", step);

  float assumedResistance = digiPot.calculateAssumedResistance(step);
  Serial.printf("Assumed resistance\t%f\n\r", assumedResistance);

  digiPot.writeSteps(step);
}
