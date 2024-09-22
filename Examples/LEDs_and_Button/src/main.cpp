#include <Arduino.h>

const uint8_t LED_RED = 10;
const uint8_t LED_YELLOW = 9;
const uint8_t LED_GREEN = 8;

const uint8_t BUTTON = 15;

uint8_t current_led;
uint8_t button_state;

void turnLEDonOff(uint8_t led);

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  current_led = LED_GREEN;
  button_state = HIGH;

  // Serial.begin(9600);
}

void loop() {
  turnLEDonOff(current_led);
  
  uint8_t newstate = digitalRead(BUTTON);

  if ((newstate == LOW) and (button_state == HIGH)) {
    if (current_led < LED_RED) {
      current_led++;
    } else {
      current_led = LED_GREEN;
    }
  }

  button_state = newstate;

  // Serial.print(button_state);
  // Serial.print("\t");
  // Serial.println(current_led);

  delay(100);
}

void turnLEDonOff(uint8_t led) {
  for (uint8_t i = LED_GREEN; i <= LED_RED; i++) {
    digitalWrite(i, (i == led ? HIGH : LOW));
  }
}