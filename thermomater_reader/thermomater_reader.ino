#include <Wire.h>   //use I2C library
#include <LiquidCrystal_I2C.h>  //use I2C LCD Library
#define inputPin 2
int Data;
float Temperature;

LiquidCrystal_I2C lcd(0x38,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  lcd.init();  // initialize the lcd 
  lcd.backlight();  // backlight on
}

void loop()
{
  Data = analogRead(inputPin);
  Serial.println(Data);
  Display(Data);
}

void Display(int val)  //function for LCD display format
{
  lcd.clear();
  lcd.print("Temperature");
  lcd.print(" ");
  lcd.print(val);
  lcd.setCursor(0, 1);
  lcd.print(" "); 
  delay(1000);
}
