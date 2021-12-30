class RainbowMarch {
  public:
    RainbowMarch(){};
    void runPattern();
  private:
};

void RainbowMarch::runPattern() {



//void rainbowmarch(uint8_t thisdelay, uint8_t deltahue) {     // The fill_rainbow call doesn't support brightness levels.
uint8_t thisdelay = 40;                                       // A delay value for the sequence(s)
uint8_t thishue = 0; 
uint8_t deltahue = 1; 
// Starting hue value.
  thishue = beat8(50);                                       // This uses a FastLED sawtooth generator. Again, the '50' should not change on the fly.
  thishue = beatsin8(50,0,255);                              // This can change speeds on the fly. You can also add these to each other.
  
  fill_rainbow(leds, NUM_LEDS, thishue, deltahue);            // Use FastLED's fill_rainbow routine.
  thishue = millis()*(255-thisdelay)/120;             // To change the rate, add a beat or something to the result. 'thisdelay' must be a fixed value.

 btn.tick();
 FastLED.show();
}
