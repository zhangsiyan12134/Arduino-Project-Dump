//***************************************************************
//    This program is use to show how to use Swich Case Statment
//            By Siyan Zhang @ George Brown College
//                        ID 100757256
//                      Data 2012-10-04
//***************************************************************

#define GLED 2  //Define pins for all components
#define YLED 3
#define RLED 4
#define Button 8

int Counter=0;  //Set variables to record the data
boolean State=1;
boolean State2=1;

void setup()
{
  Serial.begin(9600);  //Start the Serial and set the pinmode
  pinMode(GLED,OUTPUT);
  pinMode(RLED,OUTPUT);
  pinMode(YLED,OUTPUT);
  pinMode(Button,INPUT);
}

void loop()
{
  State=digitalRead(Button);  //To reduce the button jitter and continuous contact
  delay(100);
  State2=digitalRead(Button);  
  if(State==LOW&&State2==LOW) //If the button is keep pressed longer than 100ms, then consider it as Pushed State.
  {
    Counter++;  //Count the number of the button is pressed
    if(Counter>=6)  //If button pressed more than 5 times, reset it to 0;
    {
      Counter=0;
    } 
    else {
      Serial.println(Counter);  //Print the number of the button is pressed
    }
  } 
  switch(Counter)  //Set the statement of three LEDs in 5 different condition.
  {
  case 1:
    digitalWrite(RLED,HIGH);
    digitalWrite(YLED,LOW);
    digitalWrite(GLED,LOW);
    break;
  case 2:
    digitalWrite(RLED,LOW);
    digitalWrite(YLED,HIGH);
    digitalWrite(GLED,LOW);
    break;
  case 3:
    digitalWrite(RLED,LOW);
    digitalWrite(YLED,LOW);
    digitalWrite(GLED,HIGH);
    break;
  case 4:
    digitalWrite(RLED,HIGH);
    digitalWrite(YLED,HIGH);
    digitalWrite(GLED,HIGH);
    break;
  case 5:
    digitalWrite(RLED,LOW);
    digitalWrite(YLED,LOW);
    digitalWrite(GLED,LOW);
    break;
  }
}






