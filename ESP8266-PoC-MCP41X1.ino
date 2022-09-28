#include <SPI.h>

byte address = 0x00;

#define CS_PIN D8 // Chip Select pin
#define POT_STEPS 256
#define MAX_OHMS 5000 // For logging only
#define DELAY 200
#define SERIAL_BAUDRATE 115200

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println("");
  Serial.println("Setup...");

  pinMode(CS_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Begin SPI");
  SPI.begin();
  Serial.println("Setup Completed");
}

void loop() {
  Serial.println("loop()");
  digitalWrite(LED_BUILTIN, LOW);
  for (int i = 0; i < POT_STEPS; i++) {
    digitalPotWrite(i);
    delay(DELAY);
  }
  Serial.println("Reached max");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY * 3);
  for (int i = POT_STEPS - 1; i >= 0; i--) {
    digitalPotWrite(i);
    delay(DELAY);
  }
  Serial.println("Reached min ");
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY * 3);
}

void digitalPotWrite(int value) {
  Serial.print("Writing to SPI:");
  Serial.println(value);
  Serial.print("Assumed resistance:");
  Serial.println((MAX_OHMS/(POT_STEPS-1))*value);
  
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS_PIN, HIGH);
}
