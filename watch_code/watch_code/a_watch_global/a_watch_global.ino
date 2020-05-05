#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Wire.h>
#include<avr/sleep.h>
#include "RTClib.h"
#define interruptPin 2
 int seconds,minutes,hours,days,months,years;
 int flag; 
 int i;
 int h=1;
  int m=1;
   int p=1;
   bool st=0;
   int back=0;
   int led;
   int c_level=60;
   int b_level=20;
   int alarm=0;
   int lock[5][5];
bool inv=1;
bool pinv;
int un[5];
// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
RTC_DS1307 rtc;

int rotatetext = 1;

char mode[][14]={"STOP WATCH","COUNT DOWN","BRIGHTNESS","ALARM","SNAKE","ADVNCD SETTING"};
char avd[][14]={"NODES","INFRARED","RADIO","NRF","WALKIE-TALKIE","LOG"};
