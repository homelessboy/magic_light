// #include <Arduino.h>
#include <FastLED.h>
#include "Keypad.h"
#include "LightAll.h"

#define LED_PIN     2
#define COLOR_ORDER RGB
#define CHIPSET     WS2811
#define NUM_LEDS    54

CRGB leds[NUM_LEDS];

const byte ROWS = 6;
const byte COLS = 9;
char keys[6][9] = {
  {1, 2, 3, 4, 5, 6, 7, 8, 9},
  {10, 11, 12, 13, 14, 15, 16, 17,18},
  {19, 20, 21, 22, 23, 24, 25, 26,27},
  {28, 29, 30, 31, 32, 33, 34, 35,36},
  {37, 38, 39, 40, 41, 42, 43, 44,45},
  {46, 47, 48, 49, 50, 51, 52, 53,54},
};
byte rowPins[ROWS] = {32, 33, 34, 35, 36, 37}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {22, 23, 24, 25, 26, 27, 28, 29, 30}; //connect to the column pinouts of the kpd
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LightAll lightAll=LightAll(leds,CRGB(0,10,30));
unsigned long startTimeF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<CHIPSET,LED_PIN,COLOR_ORDER>(leds,NUM_LEDS).setCorrection(TypicalLEDStrip);
  // lightAll.light(3);
  lightAll.getLed();
  FastLED.show();
  startTimeF=millis();
}

void loop() {
  if(kpd.getKeys()){
    for(int i=0;i<LIST_MAX;i++){
      if(kpd.key[i].kstate==PRESSED){
        if(kpd.key[i].stateChanged){
          lightAll.light(kpd.key[i].kcode);
        }
      }
    }
  }
  if((millis()-startTimeF)>1000/60){
    lightAll.getLed();
    FastLED.show();
    startTimeF=millis();
  }
}
