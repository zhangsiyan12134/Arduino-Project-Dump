#include "T6963.h"
T6963 LCD(128, 128, 8, 8);

void setup(){
  Serial.begin(9600);
  Serial.print("TH: ");
  Serial.println(LCD.getTH());
  Serial.print("GH: ");
  Serial.println(LCD.getGH());
  Serial.print("TextRows: ");
  Serial.println((int)LCD.getTextRows());
  Serial.print("TextCols: ");
  Serial.println((int)LCD.getTextCols());
  
  LCD.Initialize();
  
  Serial.println("Initialized");
  
  LCD.TextGoTo(0, 0);
  LCD.WriteString("Hello World!");  
  
  Serial.print("Check status: ");
  Serial.println((int)LCD.checkStatus());
  
  pinMode(13, OUTPUT); // Blink LED13 to check if program is running
}

void loop(){
  digitalWrite(13, HIGH);

  Serial.print("Check status before: ");
  Serial.println((int)LCD.checkStatus());
  
  LCD.clearGraphic();
  LCD.writePixel(20, 20, 1);
  LCD.writePixel(21, 20, 1);
  
  LCD.setPixel(5, 10);
  LCD.setPixel(6, 10);
  LCD.setPixel(7, 10);
  
  Serial.print("Check status after: ");
  Serial.println((int)LCD.checkStatus());
  
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
} 

