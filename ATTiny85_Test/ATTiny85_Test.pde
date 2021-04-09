int Latch = 1; // connect to pin 12 on the '595
int Clock = 0; // connect to pin 11 on the '595
int Data = 2; // connect to pin 14 on the '595
int NUM[] = {1, 2, 4, 8, 16, 32, 64, 128};
int i;
void setup()
{
  pinMode(Latch,OUTPUT);
  pinMode(Clock,OUTPUT);
  pinMode(Data,OUTPUT);
  
}
void loop()
{
  i = 0;
  while( i<=8 )
  {
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,NUM[i]);
    digitalWrite(Latch, HIGH);
    delay(500);
    i++;
  }
}




