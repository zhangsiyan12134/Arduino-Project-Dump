#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define thumb A0
#define index A1
#define middle A2
#define ring A3
#define pinky A4

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SH110X display(SCREEN_HEIGHT, SCREEN_WIDTH, &Wire);

int thumbValue, indexValue, middleValue, ringValue, pinkyValue;

void setup()
{
  Serial.begin(115200);

  analogReadResolution(12); //Change the ADC resolution to 12 bits
  
  display.begin(0x3C, true);// Address 0x3D for 128x64
  display.setRotation(1);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
}

void loop()
{
  thumbValue = analogRead(thumb);
  indexValue = analogRead(index);
  middleValue = analogRead(middle);
  ringValue = analogRead(ring);
  pinkyValue = analogRead(pinky);
  
  display.clearDisplay();
  
  display.setCursor(0,0);
  display.print("thumb:");
  display.setCursor(40,0);
  display.print(thumbValue);

  display.setCursor(0,10);
  display.print("imdex:");
  display.setCursor(40,10);
  display.print(indexValue);

  display.setCursor(0,20);
  display.print("middle:");
  display.setCursor(40,20);
  display.print(middleValue);

  display.setCursor(0,30);
  display.print("ring:");
  display.setCursor(40,30);
  display.print(ringValue);

  display.setCursor(0,40);
  display.print("pinky:");
  display.setCursor(40,40);
  display.print(pinkyValue);
  
  display.display();
  delay(100);
}
