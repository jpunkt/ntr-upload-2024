#include <Arduino.h>

void setup() {
  
}

void loop() {
  tone(15, 440);
  delay(500);
  noTone(15);
  delay(500);
}
