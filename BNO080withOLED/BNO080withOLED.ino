#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BNO08x.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define BNO08X_RESET 5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/* Set the delay between fresh samples */
Adafruit_BNO08x  bno08x(BNO08X_RESET);
sh2_SensorValue_t sensorValue;

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
    display.setTextSize(1);
  display.setTextColor(WHITE);

  Serial.println("Orientation Sensor Test"); Serial.println("");

  
  // Try to initialize!
  if (!bno08x.begin_I2C(0x4B)) {
  //if (!bno08x.begin_UART(&Serial1)) {  // Requires a device with > 300 byte UART buffer!
  //if (!bno08x.begin_SPI(BNO08X_CS, BNO08X_INT)) {
    Serial.println("Failed to find BNO08x chip");
    while (1) { delay(10); }
  }
  Serial.println("BNO08x Found!");

  for (int n = 0; n < bno08x.prodIds.numEntries; n++) {
    Serial.print("Part ");
    Serial.print(bno08x.prodIds.entry[n].swPartNumber);
    Serial.print(": Version :");
    Serial.print(bno08x.prodIds.entry[n].swVersionMajor);
    Serial.print(".");
    Serial.print(bno08x.prodIds.entry[n].swVersionMinor);
    Serial.print(".");
    Serial.print(bno08x.prodIds.entry[n].swVersionPatch);
    Serial.print(" Build ");
    Serial.println(bno08x.prodIds.entry[n].swBuildNumber);
  }

  setReports();

  Serial.println("Reading events");
  delay(100);
}

// Here is where you define the sensor outputs you want to receive
void setReports(void) {
  Serial.println("Setting desired reports");
  if (! bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
    Serial.println("Could not enable game vector");
  }
}

void loop() {
  delay(10);

  if (bno08x.wasReset()) {
    Serial.print("sensor was reset ");
    setReports();
  }
  
  if (! bno08x.getSensorEvent(&sensorValue)) {
    return;
  }
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("R: ");
  display.println(sensorValue.un.gameRotationVector.real, 4);
  display.print("i: ");
  display.println(sensorValue.un.gameRotationVector.i, 4);
  display.print("j: ");
  display.println(sensorValue.un.gameRotationVector.j, 4);
  display.print("k: ");
  display.println(sensorValue.un.gameRotationVector.k, 4);
  display.display();
  
  /* Display the floating point data */
  //Serial.print("X: ");
  //Serial.print(event.orientation.x, 4);
  //Serial.print("\tY: ");
  //Serial.print(event.orientation.y, 4);
  //Serial.print("\tZ: ");
  //Serial.print(event.orientation.z, 4);

  

}
