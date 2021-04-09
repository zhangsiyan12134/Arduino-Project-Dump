#define LED 7
#define Button 13

int state = 0;
int record = 0;
int oldstate = 0;

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(Button,INPUT);
}

void loop()
{
  state = digitalRead(Button);
  if ((state == HIGH) and (oldstate == LOW))
  {
    record = 1 - record;
    delay(10);
  }
  oldstate = record;
  if (record == 1)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  } 
}

