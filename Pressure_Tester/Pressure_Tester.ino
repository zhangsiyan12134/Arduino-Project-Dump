//*************************************************************
//    This program use 2 button to simulate a pressure tester
//            By Siyan Zhang @ George Brown College
//                        ID 100757256
//                      Data 2012-09-27
//*************************************************************

#define RLED 9  //Define the pins that used in this program
#define YLED 8
#define Pressure 7
#define Reset 6

boolean PBState=1;  //Use to save real-time data of Pressure Button
boolean RBState=1;  //Use to save real-time data of Reset Button
boolean StateSave=1;  //To record if pressure button is pressed after cycle started

void setup()
{
  pinMode(RLED,OUTPUT);  //Set pins mode
  pinMode(YLED,OUTPUT);
  pinMode(Pressure,INPUT);
  pinMode(Reset,INPUT);
}

void loop()
{
  PBState=digitalRead(Pressure);  //Read the state of two button
  RBState=digitalRead(Reset);
  if(PBState==LOW)  //Determine if Pressure Button is pressed in this cycle
  {
    digitalWrite(RLED,HIGH);
    digitalWrite(YLED,HIGH);
    StateSave = LOW;  
  }  //If Pressure Button is pressed, turn on both LEDs and record the state for next cycle
  if(PBState==HIGH&&StateSave==LOW&&RBState==HIGH)  //Determine if Pressure Button was pressed at last cycleand but released now, and Reset Button is not pressed.
  {
    digitalWrite(RLED,LOW);
    digitalWrite(YLED,HIGH);
  } //Turn on Yellow LED and turn off Red LED
  if(RBState==LOW)  //Determine if Reset Button is pressed in this cycle
  {
    digitalWrite(RLED,LOW);
    digitalWrite(YLED,LOW);
    StateSave = HIGH;
  }  //Reset state and turn off two LEDs
}




