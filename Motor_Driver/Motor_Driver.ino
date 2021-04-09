#define ENA 7
#define IN1 6
#define IN2 5

void setup()
{
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    while (Serial.available() > 0)
    {
      int state = Serial.read();
      switch (state)
      {
         case 'Z':
           digitalWrite(ENA,HIGH);
           digitalWrite(IN1,HIGH);
           digitalWrite(IN2,LOW);
           break;
         case 'F':
           digitalWrite(ENA,HIGH);
           digitalWrite(IN1,LOW);
           digitalWrite(IN2,HIGH);
           break;
      }
    }
}
