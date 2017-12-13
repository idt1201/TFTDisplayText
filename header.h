#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68
#define ONE_WIRE_BUS 2
#define cs   10
#define dc   9
#define rst  8

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
TFT TFTscreen = TFT(cs, dc, rst);

//Sensor Variables
char sensorPrintout[10];
char oldSensor[10];
String sensorVal;
String oldSenseStr;
String sensorString;
String temp;

//Time Variables
char timeText[30];
char dayText[30];
char dateText[30];
int rtcSec;
String rtcTime;
String rtcDay;
String rtcDate;
String oldTime;
String oldDay;
String oldDate;
String timeString;
String dayString;
String dateString;

//Display Variables
char ledOutVal[20];
int tftWidth=132;
int tftMarLeft=3;
int tftMarTop=2;
int cWidth=6;
int cHeight=8;
int line;
int linepx;
int lgt;
int strtpx;
int hp;
int vp;

//Lighting Variables
String ledBrightness;
String oldLed;
String ledString;
int led=3;
int fadeamount=10;
int inc;
int dir;
int oldInc;
int minLed=-1;
int maxLed=100;
int brightness=minLed;

//User Interface Variables
char rx_byte = 0;
String rx_str = "";
String menu[15];

//Switch Variables
int Lup=6;
int Ldn=7;
int oldLupSts;
int LupSts;
int oldLdnSts;
int LdnSts;

//counter variables
long count;
long oldSec;
long oldTim;
long oldSense;
long sec;
long fadeDelay=1;//20;
long timeDelay=1;//60;
long senseDelay=1;
int first=0;

//relay variables
int Htr=4;
int Pmp=5;
