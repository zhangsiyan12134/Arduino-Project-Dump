/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(7, OUTPUT); 
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);  
}

void loop() {
  digitalWrite(7, HIGH);   // set the LED on
  digitalWrite(4, LOW);    // set the LED off
  delay(27);              // wait for a second  
  digitalWrite(7, LOW);   // set the LED on
  digitalWrite(4, HIGH);    // set the LED off
  delay(500);              // wait for a second  
  
  digitalWrite(5, LOW);   // set the LED on
  digitalWrite(6, HIGH);    // set the LED off
  delay(15);              // wait for a second  
  digitalWrite(5, HIGH);   // set the LED on
  digitalWrite(6, LOW);    // set the LED off
  delay(500);              // wait for a second   
  
}
