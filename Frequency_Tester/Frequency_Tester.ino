//*************************************************************
//          This program is the pratices of Functions
//            By Siyan Zhang @ George Brown College
//                        ID 100757256
//                      Data 2012-11-10
//*************************************************************

#define button 7  //Define the pins number
#define buzzer 5

int btn;  //Temporary store the button state
int State;  //Record if button is pressed
float F;  //Record the Frequency
float per;  //Record the converted period

void setup()
{
  pinMode(button,INPUT);  //Set pins' mode
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);  //Start the serial communication
}

void loop()
{
  btn = digitalRead(button);
  if (btn == LOW)  //If button is pressed, increase the frequency.
  { 
    State = 1;
    F = F + 1;
    per = 1/F*1000000;
    playTone((int) per,5);  //Convert period to integer to avoid weird problems
  }
  if (btn == HIGH && State == 1)
  {
    State = 0;
    Serial.print("You can hear the sound that up to");  //If button is released,print and reset the frequency.
    Serial.print(F);
    Serial.println("Hz");
    F = 0;
  }
}

void playTone(int period, int duration)  //Function to generate the sounds with required freguency and length.
{
  for(int i=0; i<=duration; i++)
  {
    digitalWrite(buzzer,HIGH);
    delayMicroseconds(period/2);
    digitalWrite(buzzer,LOW);
    delayMicroseconds(period/2);
  }
}


