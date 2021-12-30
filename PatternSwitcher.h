#include "Arduino.h"

class PatternSwitcher {
  public:
    PatternSwitcher(){
      // Blank constructor  
    };
    void runPattern();
  private:
};

void PatternSwitcher::runPattern() {
int8_t patternCounter = 0;
switch (patternCounter) {

    case 0:
      MovingDot();
      break;
    case 1:
      RainbowBeat();
      break;
    case 2:
      RedWhiteBlue();
      break;
    case 3:
      RainbowMarch();
      break;
  }

  EVERY_N_SECONDS(5) {
  isRunning = true;  
  patternCounter = (patternCounter + 1) % 4;          // Change the number after the % to the number of patterns you have
}

  btn.tick();
  FastLED.show();
}
