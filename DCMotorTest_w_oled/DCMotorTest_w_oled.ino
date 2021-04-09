/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MotorShield.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x60); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(150);
  myMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  uint8_t i;
  
  display.setCursor(0,0);
  display.print("Direction:");
  myMotor->run(FORWARD);
  display.print("CW");
  display.setCursor(0,8);
  display.print("Speed:");
  
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);
    display.setCursor(0,16);
    display.print(i);
    display.display();  
    delay(100);
  }
  for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);
    display.setCursor(0,16);
    display.print(i);
    display.display();  
    delay(100);
  }
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Direction:");
  myMotor->run(BACKWARD);
  display.print("CCW");
  display.setCursor(0,8);
  display.print("Speed:");
  
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);
    display.setCursor(0,16);
    display.print(i);
    display.display();   
    delay(100);
  }
  for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);
    display.setCursor(0,16);  
    display.print(i);
    display.display(); 
    delay(100);
  }

  myMotor->run(RELEASE);
  delay(1000);
}
