#include <Arduino.h>

const uint8_t LED_RED = 10;
const uint8_t LED_YELLOW = 9;
const uint8_t LED_GREEN = 8;

const uint32_t ON_MILLIS = 500;
const uint32_t OFF_MILLIS = 500;

void turnLEDonOff(uint8_t led, uint32_t on_millis, uint32_t off_millis);

void setup() {
 
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

}

void loop() {
  for (uint8_t led = 8; led <= 10; led++) {
    turnLEDonOff(led, ON_MILLIS, OFF_MILLIS);
  }
}

void turnLEDonOff(uint8_t led, uint32_t on_millis, uint32_t off_millis) {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
}