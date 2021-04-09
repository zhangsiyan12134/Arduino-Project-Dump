#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Ultrasonic.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

Ultrasonic ultrasonic(36,38); // (Trig PIN,Echo PIN)

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(ultrasonic.Ranging(CM)); // CM or INC
  display.println(" cm");
  display.display();
  delay(100);
}
