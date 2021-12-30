#include <FastLED.h>
#include <OneButton.h>

#define NUM_LEDS  350
#define LED_PIN   2
#define BTN_PIN   10

CRGB leds[NUM_LEDS];
uint8_t patternCounter = 0;
bool isRunning = false;

// Push button connected between pin 7 and GND (no resistor required)
OneButton btn = OneButton(BTN_PIN, true, true);

#include "MovingDot.h"
#include "RainbowBeat.h"
#include "RedWhiteBlue.h"
#include "RainbowMarch.h"
#include "PatternSwitcher.h"

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(57600);

  btn.attachClick(nextPattern);
}

void loop() {
  
  switch (patternCounter) {
    case 0:
      runMovingDot();
      break;
    case 1:
      runRainbowBeat();
      break;
    case 2:
      runRedWhiteBlue();
      break;
    case 3:
      runRainbowMarch();
      break;
    case 4:
      runPatternSwitcher();
      break;
  }
  
}

void nextPattern() {
  isRunning = false;
  patternCounter = (patternCounter + 1) % 5;
}

void runMovingDot(){
  isRunning = true;
  MovingDot movingDot = MovingDot();
  while(isRunning) movingDot.runPattern();
}

void runRainbowBeat(){
  isRunning = true;
  RainbowBeat rainbowBeat = RainbowBeat();
  while(isRunning) rainbowBeat.runPattern();
}

void runRedWhiteBlue(){
  isRunning = true;
  RedWhiteBlue redWhiteBlue = RedWhiteBlue();
  while(isRunning) redWhiteBlue.runPattern();
}

void runRainbowMarch(){
   isRunning = true;
   RainbowMarch rainbowmarch = RainbowMarch();
   while(isRunning) rainbowmarch.runPattern();
}

void runPatternSwitcher(){
   isRunning = true;
   PatternSwitcher patternswitcher = PatternSwitcher();
   while(isRunning) patternswitcher.runPattern();
}
