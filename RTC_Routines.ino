//Real time clock subroutines
//---------------------------------------------------------------------------------------------------------------
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val) {return( (val/10*16) + (val%10) );}
//---------------------------------------------------------------------------------------------------------------
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val) {return( (val/16*10) + (val%16) );}
//---------------------------------------------------------------------------------------------------------------
void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year){
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}
//---------------------------------------------------------------------------------------------------------------
void readDS3231time(byte *second, byte *minute, byte *hour, byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year){
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}
//---------------------------------------------------------------------------------------------------------------
String checkLen(byte data) {
  String val;
  if(data<10){val="0" + String(data);} else {val=String(data);}
  return val;
}
//---------------------------------------------------------------------------------------------------------------
String checkDay(byte data) {
  String val;
  switch(data){
  case 1:
    val=("Sunday ");
    break;
  case 2:
    val=("Monday ");
    break;
  case 3:
    val=("Tuesday ");
    break;
  case 4:
    val=("Wednesday ");
    break;
  case 5:
    val=("Thursday ");
    break;
  case 6:
    val=("Friday ");
    break;
  case 7:
    val=("Saturday ");
    break;
  } 
  return val;
}
//---------------------------------------------------------------------------------------------------------------
String checkMonth(byte data) {
  String val;
  switch(data){
  case 1:
    val=("Jan ");
    break;
  case 2:
    val=("Feb ");
    break;
  case 3:
    val=("Mar ");
    break;
  case 4:
    val=("Apr ");
    break;
  case 5:
    val=("May ");
    break;
  case 6:
    val=("Jun ");
    break;
  case 7:
    val=("Jul ");
    break;
  case 8:
    val=("Aug ");
    break;
  case 9:
    val=("Sep ");
    break;
  case 10:
    val=("Oct ");
    break;
  case 11:
    val=("Nov ");
    break;
  case 12:
    val=("Dec ");
    break;
  } 
  return val;
}
 //---------------------------------------------------------------------------------------------------------------
void getTime() {  
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,  &year);
  rtcTime=(checkLen(hour) + ":");
  rtcTime=rtcTime + (checkLen(minute)); //+ ":");
  //rtcTime=rtcTime + (checkLen(second) +" ");
  rtcSec=second; 
  rtcDay=(checkDay(dayOfWeek) +" ");
  rtcDate=(checkLen(dayOfMonth) +" ");
  rtcDate=rtcDate + checkMonth(month);
  rtcDate=rtcDate + year;
}
