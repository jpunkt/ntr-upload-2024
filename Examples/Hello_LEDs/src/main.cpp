#include <Arduino.h>

const uint8_t LED_RED = 10;
const uint8_t LED_YELLOW = 9;
const uint8_t LED_GREEN = 8;

uint8_t which_LED = 0;

// void turnLEDonOff(uint8_t led, uint32_t on_millis, uint32_t off_millis);

void setup() {
 
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

}

void loop() {
  if (which_LED == 0) {
    digitalWrite(LED_RED, HIGH);
    delay(500);
    digitalWrite(LED_RED, LOW);
    delay(500);
    which_LED++;
  } else if (which_LED == 1) {
    digitalWrite(LED_YELLOW, HIGH);
    delay(500);
    digitalWrite(LED_YELLOW, LOW);
    delay(500);
    which_LED++;
  } else if (which_LED == 2) {
    digitalWrite(LED_GREEN, HIGH);
    delay(500);
    digitalWrite(LED_GREEN, LOW);
    delay(500);
    which_LED++;
  } else {
    which_LED = 0;
  }
}

void turnLEDonOff(uint8_t led, uint32_t on_millis, uint32_t off_millis) {
  digitalWrite(led, HIGH);
  delay(on_millis);
  digitalWrite(led, LOW);
  delay(off_millis);
}