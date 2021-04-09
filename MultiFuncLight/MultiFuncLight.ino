int Button = 12;
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int Mode = 0; // 0=always on; 1=Flashing; 2=PWM
boolean State1 = 0;
boolean State2 = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT); 
  pinMode(Button,INPUT) ;
}

void loop() {
  State1 = digitalRead(Button);
  delay(100);
  State2 = digitalRead(Button);
  if (State1 == HIGH&&State2 == HIGH) 
  {
    Mode++;
  }
  if (Mode == 0)
  {
    digitalWrite(ledPin,HIGH);
  } else
  if (Mode == 1)
  {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);    
    // turn the ledPin on
    digitalWrite(ledPin, HIGH);  
    // stop the program for <sensorValue> milliseconds:
    delay(sensorValue);          
    // turn the ledPin off:        
    digitalWrite(ledPin, LOW);   
    // stop the program for for <sensorValue> milliseconds:
    delay(sensorValue);  
  } else
  if (Mode == 2)
  {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    analogWrite(ledPin,sensorValue/4);
  } else
  if (Mode >= 3)
  {
  Mode == 0;
  }  
}






