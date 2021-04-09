#define LED 10
void setup()
{
  pinMode(LED,OUTPUT);
}
void loop()
{
  for (int i=0; i<255; i++)
  {
    analogWrite(LED,i);
    delay(10);
  }
  for (int i=254; i>0; i--)
  {
    analogWrite(LED,i);
    delay(10);
  }
}
