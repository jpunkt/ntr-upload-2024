#include <Arduino.h>

const uint8_t BUTTON = 15;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  digitalWrite(LED_BUILTIN, digitalRead(BUTTON));
}