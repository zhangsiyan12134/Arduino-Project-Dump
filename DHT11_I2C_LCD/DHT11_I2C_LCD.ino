// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

byte smiley[8] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
};

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x38,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.print("DHTxx test!");
  
  lcd.createChar(1, smiley);
 
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  lcd.setCursor(0, 0);
  if (isnan(t) || isnan(h)) {
    lcd.print("Failed to read from DHT");
  } else {
    lcd.print("Humi:"); 
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp:"); 
    lcd.print(t);
    lcd.write(1);
    lcd.println("C    ");
  }
}
