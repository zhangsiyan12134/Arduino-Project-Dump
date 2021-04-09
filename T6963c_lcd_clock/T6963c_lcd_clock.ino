/* Demonstration of Rtc_Pcf8563 Clock on LCD. 
 *
 * I used a RBBB with Arduino IDE, the pins are mapped a 
 * bit differently.  Change for your hw.
 * SCK - A5, SDA - A4, INT - D3/INT1
 *
 * This sketch connects a lcd to display the clock output.
 * 
 * setup:  see Pcf8563 data sheet.
 *         1x 10Kohm pullup on Pin3 INT
 *         No pullups on Pin5 or Pin6 (I2C internals used)
 *         1x 0.1pf on power
 *         1x 32khz chrystal
 *         1x h44780 LCD
 *
 * Joe Robertson, jmr
 * orbitalair@bellsouth.net
 */

#include <Wire.h>
#include <Rtc_Pcf8563.h>
/* add the lcd support */ 
#include "U8glib.h"

//init the real time clock
Rtc_Pcf8563 rtc;

/* 日期变量缓存 */
char buf[50];
char day[10];
/* 串口数据缓存 */
String comdata = "";
int numdata[8] ={0}, j = 0, mark = 0;

/* initialize the library objects */
U8GLIB_T6963_240X128 u8g(2, 3, 4, 5, 6, 7, 8, 9, A2, A3, A0, A1); // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7, cs=14, a0=15, wr=17, rd=18, reset=16

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 22,"Time:");
  u8g.drawStr( 45, 22, rtc.formatTime());
  u8g.drawStr( 0, 44,"Date:");
  u8g.drawStr( 45, 44, rtc.formatDate());
}

void setup()
{
  Serial.begin(9600);
  // set up the LCD's number of rows and columns: 
  // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  //clear out all the registers
  rtc.initClock();

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
    /*Year, Month, Weekday, Day, Hours, Minutes, Seconds*/
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
        rtc.setTime(numdata[4],numdata[5], numdata[6]);     // Set the time to 12:00:00 (24hr format)
        rtc.setDate(numdata[3], numdata[2], numdata[1], 0, numdata[0]);   //day, weekday, month, century, year
        mark = 0;j=0;
        /* 清空 comdata 变量，以便等待下一次输入 */
        comdata = String("");
        /* 清空 numdata */
        for(int i = 0; i < 7 ; i++) numdata[i]=0;
    }
  
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(1000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
    
}




