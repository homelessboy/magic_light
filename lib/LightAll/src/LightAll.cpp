#include "LightAll.h"


LightAll::LightAll(CRGB *led,CRGB color,CRGB blank){
  this->led=led;
  this->color=color;
  this->blank=blank;
  for(int i=0;i<54;i++){
    cell[i]=false;
  }
}

void LightAll::light(byte index){
  int getNum=0;
  cell[index]=!cell[index];
  for(int i=0;i<6;i++){
    for(int j=0;j<12;j++){
      if(CIRCLE[i][j].getIndex()==index){
        getNum++;
        cell[CIRCLE[i][(j+11)%12].getIndex()]=!cell[CIRCLE[i][(j+11)%12].getIndex()];
        cell[CIRCLE[i][(j+13)%12].getIndex()]=!cell[CIRCLE[i][(j+13)%12].getIndex()];
        // Serial.println("inC");
        // Serial.println(i);
        // Serial.println(j);
        if(getNum==2) return;
      }
    }
  }

  for(int i=0;i<3;i++){
    for(int j=0;j<12;j++){
      if(MIDDLE[i][j].getIndex()==index){
        getNum++;
        cell[MIDDLE[i][(j+11)%12].getIndex()]=!cell[MIDDLE[i][(j+11)%12].getIndex()];
        cell[MIDDLE[i][(j+13)%12].getIndex()]=!cell[MIDDLE[i][(j+13)%12].getIndex()];
        if(getNum==2)
          return;
      }
    }
  }
}

void LightAll::getLed(){
  for(int i=0;i<54;i++){
    led[i] = cell[i]? color:blank;

  }
}
