// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo servoX;
Servo servoY;  // create servo object to control a servo 
 
int X = 0;  // analog pin used to connect the potentiometer
int Y = 1;
int Button = 2;
int val_X;    // variable to read the value from the analog pin 
int val_Y;  
 
void setup() 
{ 
  servoX.attach(9);  // attaches the servo on pin 9 to the servo object 
  servoY.attach(10);
} 
 
void loop() 
{ 
  val_X= analogRead(X);            // reads the value of the potentiometer (value between 0 and 1023) 
  val_Y= analogRead(Y);
  val_X= map(val_X, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  val_Y= map(val_Y, 0, 1023, 0, 179);
  servoX.write(val_X);                  // sets the servo position according to the scaled value 
  servoY.write(val_Y);
  delay(15);                           // waits for the servo to get there 
} 
