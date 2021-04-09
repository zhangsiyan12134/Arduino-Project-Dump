#include <PCF8574.h>
#include <Wire.h>

PCF8574 Positive(0x20);  // switches to High  (used as Sink)
PCF8574 Negative(0x21);  // add leds to Low   (used as Source)

void setup()
{
  Serial.begin(9600);
  Positive.write8(0);  //To control pins in each group.
  Negative.write8(255);  //To control groups(1-8,9-16,17-24,25-32,33-40,41-48,59-50).
}

void loop()
{
  for (int i=0; i<8; i++)
  {
    Negative.write(i, 0);
    for (int j=0; j<8; j--)
    {
      Positive.write(j, 1);
      delay(1000);
    }
  }
}
