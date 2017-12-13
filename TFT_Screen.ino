void screenMap() {
  TFTscreen.background(0, 0, 0);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(1);
  TFTscreen.line(0,28,160,28);
  TFTscreen.line(0,44,160,44);
  TFTscreen.line(0,60,160,60);
}
//---------------------------------------------------------------------------------------------------------------
void printData(char data[], int flag, int Hor, int Vert) {
  TFTscreen.stroke(255, 255, 255);
  if (flag==1){ TFTscreen.stroke(0, 0, 0);}
  TFTscreen.text(data, Hor, Vert);  // print the sensor value
}
//---------------------------------------------------------------------------------------------------------------
int vertPX(int line){    
  int x=tftMarTop+(cHeight*(line-1));
  return x;
}
//---------------------------------------------------------------------------------------------------------------
int horizPX(String data,String just){ 
  int y=0;
  if(just=="l"){ y=tftMarLeft; }
  if(just=="r"){ y=tftWidth-((data.length())*cWidth); }
  if(just=="c"){ y=(tftWidth-((data.length()-1)*cWidth))/2;}
  return y;
}
//---------------------------------------------------------------------------------------------------------------
String updateData(String oldData, String newData, String Just, int line, char chArray[], int ln){
  if(not (oldData == newData)){    
    hp=horizPX(newData,Just);
    vp=vertPX(line);
    printData(chArray,1,hp,vp);
    newData.toCharArray(chArray,ln);
    printData(chArray,0,hp,vp);
  } 
  return chArray;
}
//---------------------------------------------------------------------------------------------------------------
void writeLED() {
  oldLed=ledBrightness;
  ledBrightness = "Led Brightness: " + String(brightness);
  ledString=updateData(oldLed, ledBrightness, "l", 7, ledOutVal, 20);
  ledString.toCharArray(ledOutVal,20);
}
void writeTime(){
  oldTime=rtcTime;
  oldDay=rtcDay;
  oldDate=rtcDate;
  getTime();
  timeString=updateData(oldTime, rtcTime, "c", 3, timeText, 9);
  timeString.toCharArray(timeText,10);  
  dayString=updateData(oldDay, rtcDay, "l", 1, dayText, 10);
  dayString.toCharArray(dayText,10);
  dateString=updateData(oldDate, rtcDate, "r", 1, dateText, 11);
  dateString.toCharArray(dateText,11);
}
void writeTankTemp(){
  oldSenseStr=sensorVal;
  sensors.requestTemperatures();
  temp=String(sensors.getTempCByIndex(0));
  sensorVal = "Tank Temp: " + temp.substring(0,4) + char(248) + "C";
  sensorString=updateData(oldSenseStr, sensorVal, "l", 5, sensorPrintout, 20);
  sensorString.toCharArray(sensorPrintout,20);
}


