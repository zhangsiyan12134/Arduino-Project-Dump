/*
This example shows how to take simple range measurements with the VL53L1X. The
range readings are in units of mm.
*/

#include <Wire.h>
#include <VL53L1X.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
  // Required for Serial on Zero based boards
  #define Serial SERIAL_PORT_USBVIRTUAL
#endif

#define sensor1_reset 5
#define sensor2_reset 6
#define sensor3_reset 9

VL53L1X sensor1;
VL53L1X sensor2;
VL53L1X sensor3;

void setup()
{
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Serial Initialized");
   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
    
  delay(500);
  pinMode(sensor1_reset, OUTPUT);
  pinMode(sensor2_reset, OUTPUT);
  pinMode(sensor3_reset, OUTPUT);

  digitalWrite(sensor1_reset, LOW);
  digitalWrite(sensor2_reset, LOW);
  digitalWrite(sensor3_reset, LOW);
  
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  sensor1.setTimeout(500);
  sensor2.setTimeout(500);
  sensor3.setTimeout(500);
  
  digitalWrite(sensor1_reset,HIGH);
  delay(150);
  sensor1.init();
  Serial.println("Sensor 1 initialized!");
  delay(100);
  sensor1.setAddress(0x33);
  Serial.println("Sensor 1 address set!");
  
  digitalWrite(sensor2_reset,HIGH);
  delay(150);
  sensor2.init();
  Serial.println("Sensor 2 initialized!");
  delay(100);
  sensor2.setAddress(0x34);
  Serial.println("Sensor 2 address set!");

  digitalWrite(sensor3_reset,HIGH);
  delay(150);
  sensor3.init();
  Serial.println("Sensor 3 initialized!");
  delay(100);
  sensor2.setAddress(0x35);
  Serial.println("Sensor 3 address set!");
  
  // Use long distance mode and allow up to 50000 us (50 ms) for a measurement.
  // You can change these settings to adjust the performance of the sensor, but
  // the minimum timing budget is 20 ms for short distance mode and 33 ms for
  // medium and long distance modes. See the VL53L1X datasheet for more
  // information on range and timing limits.
  sensor1.setDistanceMode(VL53L1X::Long);
  sensor1.setMeasurementTimingBudget(50000);
  sensor2.setDistanceMode(VL53L1X::Long);
  sensor2.setMeasurementTimingBudget(50000);
  sensor3.setDistanceMode(VL53L1X::Long);
  sensor3.setMeasurementTimingBudget(50000);
  // Start continuous readings at a rate of one measurement every 50 ms (the
  // inter-measurement period). This period should be at least as long as the
  // timing budget.
  sensor1.startContinuous(50);
  sensor2.startContinuous(50);
  sensor3.startContinuous(50);
}

void loop()
{
  display.clearDisplay();
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Sensor1: ");
  display.println((long)sensor1.read());
  display.print("Sensor2: ");
  display.println((long)sensor2.read());
  display.print("Sensor3: ");
  display.println((long)sensor3.read());
  display.display();      // Show initial text
  
  /*Serial.print("Sensor1: ");
  Serial.println((long)sensor1.read());
  if (sensor1.timeoutOccurred()) { Serial.print("Sensor 1 TIMEOUT"); }
  Serial.print("Sensor2: ");
  Serial.println((long)sensor2.read());
  if (sensor2.timeoutOccurred()) { Serial.print("Sensor 2 TIMEOUT"); }
  */
}
