#include <MicroView.h>
int req = 5; //mic REQ line goes to pin 5 through q1 (arduino high pulls request line low)
int dat = 2; //mic Data line goes to pin 2
int clk = 3; //mic Clock line goes to pin 3
int i = 0; int j = 0; int k = 0;
int signCh = 8;
int sign = 0;
int decimal;
int output;
int units;
int v1;
int v2;
int v3;
int v4;
int v5;
int v6;
// char u;
byte mydata[14];

void setup()
{
  //Serial.begin(19200);
  uView.begin();        // start MicroView
  uView.clear(PAGE);      // clear page
  
  pinMode(req, OUTPUT);
  pinMode(clk, INPUT);
  pinMode(dat, INPUT);
  digitalWrite(clk, HIGH); // enable internal pull ups
  digitalWrite(dat, HIGH); // enable internal pull ups
  digitalWrite(req,LOW); // set request at high
}



void loop()
{   digitalWrite(req, HIGH); // generate set request
    for( i = 0; i < 13; i++ ) {
      k = 0;
      for (j = 0; j < 4; j++) {
      while( digitalRead(clk) == LOW) { } // hold until clock is high
      while( digitalRead(clk) == HIGH) { } // hold until clock is low
        bitWrite(k, j, (digitalRead(dat) & 0x1)); // edit post, added a )
      }

      mydata[i] = k;
      sign = mydata[4]; 
      v1= mydata[5]; 
      v2= mydata[6];
      v3= mydata[7];
      v4= mydata[8];
      v5= mydata[9];
      v6= mydata[10];  
      decimal = mydata[11];
      units = mydata[12];          
    }
    //Serial.print(sign);
    //Serial.print(" ");
    //Serial.print(v1);
    //Serial.print(v2);
    //Serial.print(v3);
    //Serial.print(v4);
    //Serial.print(v5);
    //Serial.print(v6);
    //Serial.print(" ");
    //Serial.print(decimal);
    //Serial.print(" ");
    //Serial.println(units);
    
    uView.clear(PAGE);
    uView.setCursor(0,0);
    
    if(units == 0)
    {
      output = v4+v3*10+v2*100+v1*1000;
      if(sign == 8) {uView.print("-");}
      uView.print(output);
      uView.print(".");
      uView.print(v5);
      uView.println(v6);
      uView.print(" mm");
    }
    if(units == 1)
    {
      output = v2+v1*10;
      if(sign == 8) {uView.print("-");}
      uView.print(output);
      uView.print(".");
      uView.print(v3);
      uView.print(v4);
      uView.print(v5);
      uView.println(v6);
      uView.print(" in");
    }
    uView.display();
    digitalWrite(req,LOW);
    delay(100); 
}
