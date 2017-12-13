void controlBrightness(){
  oldInc=inc;
  inc=fadeamount*1*dir;
  brightness=brightness+inc;
  if(brightness<=(minLed-1)) {brightness=minLed;}
  if(brightness>=(maxLed+10)) {brightness=maxLed;}
  if((brightness>=(minLed+fadeamount)) && (brightness<=(maxLed-fadeamount))) { 
   analogWrite(led,brightness); 
    }
}
//---------------------------------------------------------------------------------------------------------------

