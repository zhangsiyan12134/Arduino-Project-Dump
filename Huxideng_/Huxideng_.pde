#define GLED 0
#define RLED 1
void setup()
{
  pinMode(GLED,OUTPUT);
  pinMode(RLED,OUTPUT);
}
void loop()
{
  for (int i=0; i<255; i++)
  {
    analogWrite(GLED,i);
    analogWrite(RLED,(255-i));
    delay(10);
  }
  for (int i=254; i>0; i--)
  {
    analogWrite(GLED,i);
    analogWrite(RLED,(255-i));
    delay(10);
  }
}
