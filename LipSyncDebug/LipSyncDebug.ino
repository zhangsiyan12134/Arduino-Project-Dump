/*
 * LipSync Direction Button Test Program
 * Siyan Zhang
 */

#define X_DIR_HIGH A0                             // X Direction High (Cartesian positive x : right) - analog input pin A0
#define X_DIR_LOW A1                              // X Direction Low (Cartesian negative x : left) - digital output pin A1
#define Y_DIR_HIGH A2                             // Y Direction High (Cartesian positive y : up) - analog input pin A2
#define Y_DIR_LOW A10                             // Y Direction Low (Cartesian negative y : down) - analog input pin A10

int xh, yh, xl, yl;                               // xh: x-high, yh: y-high, xl: x-low, yl: y-low

void setup() {
  Serial.begin(9600);   
  pinMode(X_DIR_HIGH, INPUT);                     // redefine the pins when all has been finalized
  pinMode(X_DIR_LOW, INPUT);                      // ditto above
  pinMode(Y_DIR_HIGH, INPUT);                     // ditto above
  pinMode(Y_DIR_LOW, INPUT);                      // ditto above

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
   
}

void loop() {
  xh = analogRead(X_DIR_HIGH);
  xl = analogRead(X_DIR_LOW);
  yh = analogRead(Y_DIR_HIGH);
  yl = analogRead(Y_DIR_LOW);

  if (xh > 0) {
  Serial.print(xh);
  Serial.println(" X-H Pressed");
  }

  if (xl > 0) {
  Serial.print(xl);
  Serial.println(" X-L Pressed");
  }
  
  if (yh > 0) {
  Serial.print(yh);
  Serial.println(" Y-H Pressed");
  }
  
  if (yl > 0) {
  Serial.print(yl);
  Serial.println(" Y-L Pressed");
  }
  delay(500);
}
