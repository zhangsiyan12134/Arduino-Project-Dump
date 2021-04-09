#include "Wire.h" 
#include <LiquidCrystal_I2C.h>
#include "MirfHardwareSpiDriver.h"
LiquidCrystal_I2C lcd(0x38,16,2);

#include "SPI.h"
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"

int n=0;
void setup(){
  lcd.init();
  lcd.backlight();
  delay(20); 
  Mirf.spi = &MirfHardwareSpi; 
  Mirf.init();
  Mirf.setRADDR((byte *)"serv1");
  Mirf.payload = 32; 
  Mirf.config(); 
}

void loop(){
  if(Mirf.dataReady()){

    byte n[Mirf.payload];
    Mirf.getData(n);
    lcd.clear(); //清屏
    lcd.setCursor(0, 0);
    lcd.print(n[Mirf.payload]);  
    delay(50); 
  }     

}

