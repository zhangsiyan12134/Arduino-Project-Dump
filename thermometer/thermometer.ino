////#include <Wire.h>   //use I2C library
////#include <LiquidCrystal_I2C.h>  //use I2C LCD Library
#define sensor 2  //set sensor pins
#define button 7
#define outputPin 3
int State;  //record the switch state
float Fahrenheit;  //record converted temperature
int Value;  //record the value read from analog pin
float Temperature;  //record the orignal temperature

////LiquidCrystal_I2C lcd(0x38,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

void setup()
{
////  lcd.init();  // initialize the lcd 
////  lcd.backlight();  // backlight on
  Serial.begin(9600);  //Start serial port          
  analogReference(EXTERNAL);  // use outside Analog Reference
  pinMode(button,INPUT);
}

void loop()
{
  Value = analogRead(sensor);  //read sensor's value
  State = digitalRead(button);  //read button state
  if(300 < Value and Value <= 316)  //temperature calculations for different sections
  {
    Temperature = -0.15 * Value + 48.7;
  }
  if(279 < Value and Value <= 300)
  {
    Temperature = -0.0905 * Value + 30.843;
  }
  if(233 < Value and Value <= 279)
  {
    Temperature = -0.087 * Value + 29.861;
  }
  if(194 < Value and Value <= 233)
  {
    Temperature = -0.1231 * Value + 38.277;
  }
  if(157 < Value and Value <= 194)
  {
    Temperature = -0.1108 * Value + 35.897;
  }
  if(138 < Value and Value <= 157)
  {
    Temperature = -0.1263 * Value + 38.332;
  }
  if(100 < Value and Value <= 138)
  {
    Temperature = -0.1868 * Value + 46.684;
  }
  if(65 < Value and Value <= 100)
  {
    Temperature = -0.22 * Value + 50;
  }
  if(48 < Value and Value <= 65)
  {
    Temperature = -0.2706 * Value + 53.288;
  }
  if(22 < Value and Value <= 48)
  {
    Temperature = -0.5423 * Value + 66.331;
  }
  if(19 < Value and Value <= 22)
  {
    Temperature = -1.3667 * Value + 84.467;
  }
  if(10 < Value and Value <= 19)
  {
    Temperature = -1.2444 * Value + 82.144;
  }
  if(6 < Value and Value <= 10)
  {
    Temperature = -1.5 * Value + 84.7;
  }
  if(4 < Value and Value <= 6)
  {
    Temperature = -3.5 * Value + 96.7;
  }
  if(2 < Value and Value <= 4)
  {
    Temperature = -3.85 * Value + 98.1;
  }
  analogWrite(outputPin, int(Value/4));
  if(State == LOW)  //decide how to display the temperature
  {
    ////Display(Temperature, Value, 0);
    Serial.print(Temperature);
    Serial.println(" C");
    Serial.println(Value);
  } 
  else
  {
    Fahrenheit = (Temperature*9/5) + 32;
    ////Display(Fahrenheit, Value, 1);
    Serial.print(Fahrenheit);
    Serial.println(" F");
  }
}

/*void Display(float Temp, int val, boolean FC)  //function for LCD display format
{
  lcd.clear();
  lcd.print("Temperature");
  lcd.print(" ");
  lcd.print(val);
  lcd.setCursor(0, 1);
  lcd.print(Temp); 
  lcd.print((char)223); //显示o符号
  if (FC == 0)
  {
    lcd.print("C"); //显示字母C
  } 
  else
  {
    lcd.print("F"); //显示字母C
  }
  delay(1000);
}
*/


