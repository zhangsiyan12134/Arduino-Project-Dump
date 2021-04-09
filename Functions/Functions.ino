//*************************************************************
//    This program is the pratices of Functions
//            By Siyan Zhang @ George Brown College
//                        ID 100757256
//                      Data 2012-11-2
//*************************************************************


#define btnM 8 //Button for menu selection
#define btnS 9 //button for inside selection

int menu = 0; //Button counter
int select = 0;

int zone = 0;  // Data recorder
int duration = 0;
int time = 0;

int mBtn1 = 1;  //Button state recorder
int mBtn2 = 1;
int sBtn1 = 1;
int sBtn2 = 1;

void setup()
{
  pinMode(btnM,INPUT);  //Setup pins mode and serial port
  pinMode(btnS,INPUT);
  Serial.begin(9600);
}

void loop()
{
  mBtn1 = digitalRead(btnM);  //Record the button state twice to avoid the button shaking
  delay(300);
  mBtn2 = digitalRead(btnM);
  if (mBtn1 == LOW and mBtn2 == LOW and menu < 4)  //Count the first 3 menu number
  {
    menu++;
    Serial.print("Menu ");
    Serial.println(menu);
    select = 0;
  }
  if (mBtn1 == LOW and mBtn2 == LOW and menu == 4) //Print the No.4 menu
  {
    Serial.print("You have selected Zone ");
    Serial.print(zone);
    Serial.print(", Duration ");
    Serial.print(duration);
    Serial.print(", Time ");
    Serial.println(time);
    menu = 0;
    zone = 0;
    duration = 0;
    time = 0;
  }
  sBtn1 = digitalRead(btnS);  //Record the button state twice to avoid the button shaking
  delay(300);
  sBtn2 = digitalRead(btnS);
  if (sBtn1 == LOW and sBtn2 == LOW)  //Inside options counter
  {
    select++;
    mDisplay(menu, select);
  }  
}

void mDisplay(int mNO, int sNO)  //Function for display the inside options
{
  switch(mNO)
  {
  case 1:
    if (sNO<=7)
    {
      zone = sNO;
      Serial.print("      Zone ");
      Serial.println(zone);
      if (sNO = 7) {
        select = 0;
      }
    }
    break;
  case 2:
    if (sNO<=10)
    {
      duration = sNO;
      Serial.print("      Duration ");
      Serial.println(duration);
      if (sNO = 10) {
        select = 0;
      }
    }
    break;
  case 3:
    if (sNO<=12)
    {
      time = sNO;
      Serial.print("      Time ");
      Serial.println(time);
      if (sNO = 12) {
        select = 0;
      }
    }
    break;
  }
}















