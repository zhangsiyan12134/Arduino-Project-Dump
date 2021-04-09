#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_LSM6DS33.h>
#include <Adafruit_LIS3MDL.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_LSM6DS33 sox;
Adafruit_LIS3MDL lis3mdl;

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  Serial.println("Adafruit LSM6DSOX test!");
  Serial.println("Adafruit LIS3MDL test!");

  display.setRotation(3);
  display.clearDisplay();
  
  if ((!sox.begin_I2C()) || (!lis3mdl.begin_I2C())) {
    Serial.println("Failed to find LSM6DSOX chip");
    Serial.println("Failed to find LIS3MDL chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("LSM6DSOX Found!");
  Serial.println("LIS3MDL Found!");

  lis3mdl.setPerformanceMode(LIS3MDL_MEDIUMMODE);
  lis3mdl.setOperationMode(LIS3MDL_CONTINUOUSMODE);
  lis3mdl.setDataRate(LIS3MDL_DATARATE_155_HZ);
  lis3mdl.setRange(LIS3MDL_RANGE_4_GAUSS);
  lis3mdl.setIntThreshold(500);
  lis3mdl.configInterrupt(false, false, true, // enable z axis
                          true, // polarity
                          false, // don't latch
                          true); // enabled!
}

void loop() {
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  sensors_event_t event; 
  
  sox.getEvent(&accel, &gyro, &temp);
  lis3mdl.getEvent(&event);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.print("Accel:");
  display.setCursor(0,8);
  display.print("X: ");
  display.print(accel.acceleration.x);
  display.setCursor(0,16);
  display.print("Y: ");
  display.print(accel.acceleration.y);
  display.setCursor(0,24);
  display.print("Z: ");
  display.print(accel.acceleration.z);

  display.setCursor(0,32);
  display.print("Gyro:");
  display.setCursor(0,40);
  display.print("X: "); 
  display.print(gyro.gyro.x);
  display.setCursor(0,48);
  display.print("Y: ");
  display.print(gyro.gyro.y);
  display.setCursor(0,56);
  display.print("Z: ");
  display.print(gyro.gyro.z);

  display.setCursor(0,64);
  display.print("Meg:");
  display.setCursor(0,72);
  display.print("X: "); 
  display.print(event.magnetic.x);
  display.setCursor(0,80);
  display.print("Y: ");
  display.print(event.magnetic.y);
  display.setCursor(0,88);
  display.print("Z: ");
  display.print(event.magnetic.z);
  
  display.display();
  delay(100);
}
