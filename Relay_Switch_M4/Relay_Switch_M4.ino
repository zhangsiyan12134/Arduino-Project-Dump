#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define BUTTON_A 9
#define BUTTON_B 6
#define BUTTON_C 5
#define LED      13
#define RELY_1_SET 10
#define RELY_1_UNSET 11
#define RELY_2_SET 12
#define RELY_2_UNSET 13

boolean RELAY_1 = false;
boolean RELAY_2 = false;
boolean RELAY_1_PRE = false;
boolean RELAY_2_PRE = false;

Adafruit_SSD1306 oled = Adafruit_SSD1306();

void setup() {
  // Initialize OLED display
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  oled.display();
  delay(500);
  oled.clearDisplay();
  oled.display();

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(RELY_1_SET, OUTPUT);
  pinMode(RELY_1_UNSET, OUTPUT);
  pinMode(RELY_2_SET, OUTPUT);
  pinMode(RELY_2_UNSET, OUTPUT);
  
  pinMode(LED, OUTPUT);
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);  
}

void loop() {
  if(digitalRead(BUTTON_A) == 0) 
  {
    RELAY_1_PRE = RELAY_1;
    RELAY_1 = !RELAY_1;
  }
  if(digitalRead(BUTTON_B) == 0) 
  {
    RELAY_2_PRE = RELAY_2;
    RELAY_2 = !RELAY_2;
  }
  if(RELAY_1_PRE != RELAY_1)
  {
    if(RELAY_1 == true)
    {
      digitalWrite(RELY_1_UNSET, LOW);
      digitalWrite(RELY_1_SET, HIGH);
      delay(10);
      digitalWrite(RELY_1_SET, LOW);
    } else
    {
      digitalWrite(RELY_1_SET, LOW);
      digitalWrite(RELY_1_UNSET, HIGH);
      delay(10);
      digitalWrite(RELY_1_UNSET, LOW);
    }
    RELAY_1_PRE = RELAY_1;
  }
  if(RELAY_2_PRE != RELAY_2)
  {
    if(RELAY_2 == true)
    {
      digitalWrite(RELY_2_UNSET, LOW);
      digitalWrite(RELY_2_SET, HIGH);
      delay(10);
      digitalWrite(RELY_2_SET, LOW);
    } else
    {
      digitalWrite(RELY_2_SET, LOW);
      digitalWrite(RELY_2_UNSET, HIGH);
      delay(10);
      digitalWrite(RELY_2_UNSET, LOW);
    }
    RELAY_2_PRE = RELAY_2;
  }
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.print("RELAY 1: ");
  oled.println((int)RELAY_1);
  oled.print("RELAY 2: ");
  oled.print((int)RELAY_2);
  oled.display();
  delay(500);
}
