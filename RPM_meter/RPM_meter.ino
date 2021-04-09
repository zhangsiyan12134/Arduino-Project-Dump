#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// digital pin 2 is the hall pin
int sensorPin = A0;
// set number of hall trips for RPM reading (higher improves accuracy)
float hall_thresh = 800.0;
int ledPin = 13;      // select the pin for the LED

void setup() {
  // initialize serial communication at 9600 bits per second:
  //Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.print("Pass");
  display.display();
  //Serial.println("Orientation Sensor Test"); Serial.println("");

  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  delay(100);
}

// the loop routine runs over and over again forever:
void loop() {
  // preallocate values for tach
  float hall_count = 1.0;
  float start = micros();
  bool on_state = false;
  // counting number of times the hall sensor is tripped
  // but without double counting during the same trip
  while(true){
    if (analogRead(sensorPin) <= 800){
      digitalWrite(ledPin, HIGH);
      if (on_state==false){
        on_state = true;
        hall_count+=1.0;
      }
    } else{
      on_state = false;
    }
    
    if (hall_count>=hall_thresh){
      break;
    }
    digitalWrite(ledPin, LOW);
  }
  
  // print information about Time and RPM
  float end_time = micros();
  float time_passed = ((end_time-start)/1000000.0);
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Time Passed: ");
  //Serial.print("Time Passed: ");
  display.print(time_passed);
  //Serial.print(time_passed);
  display.println("s");
  //Serial.println("s");
  float rpm_val = (hall_count/time_passed)*60.0;
  display.print(rpm_val);
  //Serial.print(rpm_val);
  display.println(" RPM");
  //Serial.println(" RPM");
  display.display();
  delay(1);        // delay in between reads for stability
}
