int EnA = 9;
int In1 = 10;
int In2 = 11;
int VRx = 1;
int X = 0;

void setup()
{
  pinMode(EnA,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
}
void loop()
{
  X = analogRead(VRx);
  if ( (X > 0) and (X < 100) ) 
  {
    digitalWrite(EnA,HIGH);
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
  }
  
    if ( (X > 900) and (X < 1023) ) 
  {
    digitalWrite(EnA,HIGH);
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
  }
}


