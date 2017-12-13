#include "header.h"

void setup(){
  Wire.begin();
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(Htr, OUTPUT);
  pinMode(Pmp, OUTPUT);
  pinMode(Lup, INPUT);
  pinMode(Ldn, INPUT);
  setDS3231time(00,57,22,2,12,12,17);
  TFTscreen.begin();
  sensors.begin();
  screenMap();
}
void loop() {
  sec=millis()/1000;
  /*
  if(first==0){
    writeTankTemp();
    writeTime(); 
    writeLED();
    first=1;
  }
   if(sec>(senseDelay+oldSense)) {
    writeTankTemp();
    oldSense=sec;
  }
  if(sec>(timeDelay+oldTim)) {
    writeTime();   
    oldTim=sec;
  }
  if(sec>(fadeDelay+oldSec)) {
    controlBrightness();
    writeLED();
    oldSec=sec;
  }
  */
  doSwitch();
  delay(1);
}

