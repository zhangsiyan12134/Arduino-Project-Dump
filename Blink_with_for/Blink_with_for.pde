/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
int time = 200;
void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  for (int i = 1; i<=7; i++)
  {
  pinMode(i, OUTPUT);
  }  
}

void loop() 
{
  for (int i = 1; i<=7; i++)
  {
   digitalWrite(i, HIGH);   // set the LED on
   delay(time);              // wait for a second
   digitalWrite(i, LOW);    // set the LED off
   delay(time);              // wait for a second
  }
  
  for (int i = 7; i>=1; i--)
  {
   digitalWrite(i, HIGH);   // set the LED on
   delay(time);              // wait for a second
   digitalWrite(i, LOW);    // set the LED off
   delay(time);              // wait for a second
  }
   
}
