#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x38,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
int potPin = 2;                     //设置模拟口4为LM35的信号输入端口float temperature = 0;                //设置temperature为浮点变量long val=0;   
float temperature = 0;                //设置temperature为浮点变量
long val=0;                       //设置val为长整数变量

void setup()
{
  lcd.init();                      // initialize the lcd 
 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("LM35 Thermometer");  //使屏幕显示文字LM35 Thermometer
  delay(1000); //延时1000ms
}

void loop()
{
  val = analogRead(potPin);             //val变量为从LM35信号口读取到的数值temperature = (val*0.0048828125*1000);         //把读取到的val转换为温度数值的10倍lcd.clear(); //清屏lcd.print("LM35 Thermometer"); //使屏幕显示文字LM35 Thermometerlcd.setCursor(0, 1) ; //设置光标位置为第二行第一个位置lcd.print((long)temperature / 10);   //显示温度整数位lcd.print(".");    //显示小数点lcd.print( (long)temperature % 10); //显示温度小数点后一位lcd.print((char)223); //显示o符号lcd.print("C"); //显示字母C delay(2000);                     //延时2秒，这里也就是刷新速度。
  temperature = (val*0.0048828125*1000);         //把读取到的val转换为温度数值的10倍
  lcd.clear();
  lcd.print("LM35 Thermometer"); //使屏幕显示文字LM35 Thermometer
  lcd.setCursor(0, 1) ; //设置光标位置为第二行第一个位置
  lcd.print((long)temperature / 10);   //显示温度整数位
  lcd.print(".");    //显示小数点
  lcd.print( (long)temperature % 10); //显示温度小数点后一位
  lcd.print((char)223); //显示o符号
  lcd.print("C"); //显示字母C
  delay(1000);
}
