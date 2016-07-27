#ifndef LIGHTALL_H
#define LIGHTALL_H

#include "P.h"
#include "FastLED.h"

class LightAll{
private:
  CRGB color;
  CRGB blank;
  CRGB *led;
  bool cell[54];
public:
  LightAll(CRGB *led,CRGB color=CRGB(0,10,0),CRGB blank=CRGB(0,0,0));
  void light(byte index);
  void getLed();
};

#endif //LIGHTALL_H
