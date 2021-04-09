// DS1302_LCD (C)2010 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// A quick demo of how to use my DS1302-library to make a quick
// clock using a DS1302 and a 16x2 LCD.
//
// I assume you know how to connect the DS1302 and LCD.
// DS1302:  CE pin    -> Arduino Digital 2
//          I/O pin   -> Arduino Digital 3
//          SCLK pin  -> Arduino Digital 4
// LCD:     DB7       -> Arduino Digital 6
//          DB6       -> Arduino Digital 7
//          DB5       -> Arduino Digital 8
//          DB4       -> Arduino Digital 9
//          E         -> Arduino Digital 10
//          RS        -> Arduino Digital 11

#include <LiquidCrystal_I2C.h>
#include <DS1302.h>
#include <Wire.h>
// Init the DS1302
DS1302 rtc(5, 6, 7);

// Init the LCD
LiquidCrystal_I2C lcd(0x38,16,2);

/* 日期变量缓存 */
char buf[50];
char day[10];
/* 串口数据缓存 */
String comdata = "";
int numdata[7] ={0}, j = 0, mark = 0;


void setup()
{
  Serial.begin(9600);
  // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);
  
  lcd.init();                      // initialize the lcd 
 
  // Print a message to the LCD.
  lcd.backlight();

}

void loop()
{
      /* 当串口有数据的时候，将数据拼接到变量comdata */
    while (Serial.available() > 0)
    {
        comdata += char(Serial.read());
        delay(2);
        mark = 1;
    }
    /* 以逗号分隔分解comdata的字符串，分解结果变成转换成数字到numdata[]数组 */
    if(mark == 1)
    {
        Serial.print("You inputed : ");
        Serial.println(comdata);
        for(int i = 0; i < comdata.length() ; i++)
        {
            if(comdata[i] == ',' || comdata[i] == 0x10 || comdata[i] == 0x13)
            {
                j++;
            }
            else
            {
                numdata[j] = numdata[j] * 10 + (comdata[i] - '0');
            }
        }
        /* 将转换好的numdata凑成时间格式，写入DS1302 */
        
        // The following lines can be commented out to use the values already stored in the DS1302
        rtc.setDOW(numdata[6]);        // Set Day-of-Week to FRIDAY
        rtc.setTime(numdata[3],numdata[4], numdata[5]);     // Set the time to 12:00:00 (24hr format)
        rtc.setDate(numdata[2], numdata[1], numdata[0]);   // Set the date to August 6th, 2010
        mark = 0;j=0;
        /* 清空 comdata 变量，以便等待下一次输入 */
        comdata = String("");
        /* 清空 numdata */
        for(int i = 0; i < 7 ; i++) numdata[i]=0;
    }
    
  // Display time centered on the upper line
  lcd.setCursor(4, 0);
  lcd.print(rtc.getTimeStr());
  
  // Display abbreviated Day-of-Week in the lower left corner
  lcd.setCursor(0, 1);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  
  // Display date in the lower right corner
  lcd.setCursor(6, 1);
  lcd.print(rtc.getDateStr());

  // Wait one second before repeating :)
  delay (1000);
}
