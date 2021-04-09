#include <IRremote.h>

int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;


 int a=7;
 int b=6; 
 int c=5; 
 int d=11; 
 int e=10; 
 int f=8; 
 int g=9; 
 int dp=4;
  
//显示数字1 
 void digital_1(void)
 {
   unsigned char j;
   digitalWrite(c,LOW);//给数字5引脚低电平，点亮c段
   digitalWrite(b,LOW);//点亮b段
   for(j=7;j<=11;j++)//熄灭其余段
     digitalWrite(j,HIGH);
     digitalWrite(dp,HIGH);//熄灭小数点DP 段
 }

 //显示数字2
 void digital_2(void)
 {
   unsigned char j;
   digitalWrite(b,LOW);
   digitalWrite(a,LOW);
   for(j=9;j<=11;j++)
     digitalWrite(j,LOW);
     digitalWrite(dp,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(f,HIGH); 
}

//显示数字3
 void digital_3(void)
 {
   unsigned char j;
   digitalWrite(g,LOW);
   digitalWrite(d,LOW);
   for(j=5;j<=7;j++)
     digitalWrite(j,LOW);
     digitalWrite(dp,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(e,HIGH);
 } 

//显示数字4
 void digital_4(void)
 {
   digitalWrite(c,LOW);
   digitalWrite(b,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   digitalWrite(dp,HIGH);
   digitalWrite(a,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(d,HIGH);
    }

//显示数字5
 void digital_5(void)
 {
   unsigned char j;
   for(j=7;j<=9;j++)
     digitalWrite(j,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     digitalWrite(dp,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(e,HIGH);
  } 

//显示数字6
 void digital_6(void)
 {
   unsigned char j;
   for(j=7;j<=11;j++)
     digitalWrite(j,LOW);
     digitalWrite(c,LOW);
     digitalWrite(dp,HIGH);
     digitalWrite(b,HIGH);
  } 

//显示数字7
 void digital_7(void)
 {
   unsigned char j;
   for(j=5;j<=7;j++)
     digitalWrite(j,LOW);
     digitalWrite(dp,HIGH);
   for(j=8;j<=11;j++)
     digitalWrite(j,HIGH);
 } 

//显示数字8
 void digital_8(void)
 {
   unsigned char j;
   for(j=5;j<=11;j++)
     digitalWrite(j,LOW);
     digitalWrite(dp,HIGH);
 }
 
 void setup()
 {
   Serial.begin(9600);
   irrecv.enableIRIn(); // Start the receiver
   int i;//定义发量
   for(i=4;i<=11;i++)
     {
     pinMode(i,OUTPUT);//设置4～11 引脚为辒出模式
     digitalWrite(i,HIGH);
     }
 }
 
 void loop()
 {
     while(irrecv.decode(&results))
   {
     Serial.println(results.value);
     switch (results.value)
     {
       case 1:
         digital_1();//数字1
       break;
       case 2:
         digital_2();
       break;
       case 3:
         digital_3();
       break;
       case 4:
         digital_4();
       break;
       case 5:
         digital_5();
       break;
       case 6:
         digital_6();
       break;
       case 7:
         digital_7();
       break;
       case 8:
         digital_8();
       break;
     }
     irrecv.resume(); // Receive the next value
   }   
}
