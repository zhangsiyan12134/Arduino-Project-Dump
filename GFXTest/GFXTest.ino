// You can use any (4 or) 5 pins 
#define sclk 2
#define mosi 3
#define dc   4
#define cs   5
#define rst  6

// Color definitions
#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, rst);

float p = 3.1415926;

void fillpixelbypixel(uint16_t color) {
  for (uint8_t x=0; x < tft.width(); x++) {
    for (uint8_t y=0; y < tft.height(); y++) {
      tft.drawPixel(x, y, color);
    }
  }
  delay(100);
}

void setup() {
  // put your setup code here, to run once:
  tft.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  tft.fillScreen(BLACK);
  tft.setCursor(0, 5);
  tft.setTextColor(RED);  
  tft.setTextSize(1);
  tft.println("Hello World!");

  delay(500);

  tft.fillScreen(BLACK);

}
