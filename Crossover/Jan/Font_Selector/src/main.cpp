#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "nkr.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 10

// Pin for analog input (potentiometer)
#define POTI 15

// Analog steps per image
#define STEP (1024 / 5)

// Max is 255, 32 is a conservative value to not overload
// a USB power supply (500mA) for 12x12 pixels.
#define BRIGHTNESS 96

// Define matrix width and height.
#define mw 8
#define mh 8

// Define tile width and height
#define tw 3
#define th 1

#define LED_BLACK		0

#define LED_RED_VERYLOW 	(3 <<  11)
#define LED_RED_LOW 		(7 <<  11)
#define LED_RED_MEDIUM 		(15 << 11)
#define LED_RED_HIGH 		(31 << 11)

#define LED_GREEN_VERYLOW	(1 <<  5)   
#define LED_GREEN_LOW 		(15 << 5)  
#define LED_GREEN_MEDIUM 	(31 << 5)  
#define LED_GREEN_HIGH 		(63 << 5)  

#define LED_BLUE_VERYLOW	3
#define LED_BLUE_LOW 		7
#define LED_BLUE_MEDIUM 	15
#define LED_BLUE_HIGH 		31



Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh, tw, th, PIN, 
  NEO_MATRIX_BOTTOM  + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);
    

void setup() {
  Serial.begin(115200);

  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(BRIGHTNESS);

  matrix->fillScreen(LED_RED_LOW);
  matrix->show();
  delay(500);
  matrix->fillScreen(LED_GREEN_LOW);
  matrix->show();
  delay(500);
  matrix->fillScreen(LED_BLUE_LOW);
  matrix->show();
  delay(500);
  matrix->clear();
  matrix->show();
}

void loop() {
  uint16_t i = analogRead(POTI) / STEP;
  i = i > 4 ? 4 : i;
  
  matrix->drawRGBBitmap(0, 0, n[i], 8, 8);
  matrix->drawRGBBitmap(8, 0, k[i], 8, 8);
  matrix->drawRGBBitmap(16, 0, r[i], 8, 8);
  matrix->show();
  delay(10);
  matrix->clear();
}
