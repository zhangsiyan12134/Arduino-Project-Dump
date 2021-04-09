#include "SPI.h"
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"
void setup(){

  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
    Mirf.setRADDR((byte *)"clie1");
  Mirf.payload = 32;
  Mirf.config();
}
void loop()
{
  int n = analogRead(A4);
  Mirf.setTADDR((byte *)"serv1");
Mirf.send((byte *)n);
delay(100);
} 
