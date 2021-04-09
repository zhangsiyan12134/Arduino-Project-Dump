void setup()
{
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)
  {
    for(int i=0; i<=13; i++)
    {
      Serial.print(Serial.read());
    }
    Serial.println();
  }
}


