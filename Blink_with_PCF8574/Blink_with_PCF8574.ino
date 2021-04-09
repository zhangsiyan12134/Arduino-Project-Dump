#include <Wire.h>

#define expander B00111000  //expander address
#define time 1000

byte ledStatus = B11111111; //all off
byte led1 = 0;              //led 1 connected to port 0 of expander
byte led2 = 1;              //led 2 connected to port 7 of expander
byte led3 = 2;
byte led4 = 3;
byte led5 = 4;
byte led6 = 5;
byte led7 = 6;
byte led8 = 7;

void setup() {
  Wire.begin();
}

void loop() {
  changeLedStatusAlloff(); //switch all led's off to be sure
  delay(time);
  changeLedStatusOn(led1);  //switch on only led 1
  delay(time);
  changeLedStatusOn(led2);  //switch on led 2 (and don't touch other led's)
  delay(time);
  changeLedStatusOn(led3);
  delay(time);
  changeLedStatusOn(led4);
  delay(time);
  changeLedStatusOn(led5);
  delay(time);
  changeLedStatusOn(led6);
  delay(time);
  changeLedStatusOn(led7);
  delay(time); 
  changeLedStatusOn(led8);  //switch on led 8. now all led's are on
  delay(time);
  changeLedStatusOff(led1);  //switch off led 1. now led 1 is off and 2 to 8 are on
  delay(time);
  changeLedStatusOff(led2);  //switch off led 2. now led's 1 and 2 are off and 3 to 8 are on.
  delay(time);
  changeLedStatusOff(led3);
  delay(time);
  changeLedStatusOff(led4);
  delay(time);
  changeLedStatusOff(led5);
  delay(time);
  changeLedStatusOff(led6);
  delay(time);
  changeLedStatusOff(led7);
  delay(time);
  changeLedStatusOff(led8);  //switch off led 8. now all led's are off.
  delay(time);
  changeLedStatusAllon();     //switch on all led's
  delay(time);
  changeLedStatusAlloff();    //switch off all led's
  delay(time);
}

void changeLedStatusAllon (){
  ledStatus = B00000000;
  expanderWrite(ledStatus); 
}

void changeLedStatusAlloff (){
  ledStatus = B11111111;
  expanderWrite(ledStatus); 
}

void changeLedStatusOn(byte ledNumber){
  ledStatus &= ~(1 << ledNumber);
  expanderWrite(ledStatus); 
}

void changeLedStatusOff(byte ledNumber){
  ledStatus |= (1 << ledNumber); 
  expanderWrite(ledStatus); 
}

void expanderWrite(byte _data ) {
  Wire.beginTransmission(expander);
  Wire.write(_data);
  Wire.endTransmission();
}

