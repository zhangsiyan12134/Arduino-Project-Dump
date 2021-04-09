 int a=7;
 int b=6; 
 int c=5; 
 int d=4; 
 int e=3; 
 int f=8; 
 int g=9; 
 int dp=10;
  
//显示数字1 
 void digital_1(void)
 {
   digitalWrite(c,LOW);
   digitalWrite(b,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   digitalWrite(dp,HIGH);
   digitalWrite(a,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(d,HIGH);
 }

 //显示数字2
 void digital_2(void)
 {
   digitalWrite(c,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,LOW);
   digitalWrite(dp,HIGH);
   digitalWrite(a,LOW);
   digitalWrite(e,LOW);
   digitalWrite(d,LOW);
}

//显示数字3
 void digital_3(void)
 {
   digitalWrite(c,LOW);
   digitalWrite(b,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,LOW);
   digitalWrite(dp,HIGH);
   digitalWrite(a,LOW);
   digitalWrite(e,HIGH);
   digitalWrite(d,LOW);
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
   digitalWrite(c,LOW);
   digitalWrite(b,HIGH);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   digitalWrite(dp,HIGH);
   digitalWrite(a,LOW);
   digitalWrite(e,HIGH);
   digitalWrite(d,LOW);
  } 

//显示数字6
 void digital_6(void)
 {
   digitalWrite(c,LOW);
   digitalWrite(b,HIGH);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   digitalWrite(dp,HIGH);
   digitalWrite(a,LOW);
   digitalWrite(e,LOW);
   digitalWrite(d,LOW);
  } 

//显示数字7
 void digital_7(void)
 {
   digitalWrite(c,LOW);
   digitalWrite(b,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   digitalWrite(dp,HIGH);
   digitalWrite(a,LOW);
   digitalWrite(e,HIGH);
   digitalWrite(d,HIGH);
 } 

//显示数字8
 void digital_8(void)
 {
   digitalWrite(c,LOW);
   digitalWrite(b,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   digitalWrite(dp,HIGH);
   digitalWrite(a,LOW);
   digitalWrite(e,LOW);
   digitalWrite(d,LOW);
 }

//显示数字9
 void digital_9(void)
 {
   digitalWrite(c,LOW);
   digitalWrite(b,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   digitalWrite(dp,HIGH);
   digitalWrite(a,LOW);
   digitalWrite(e,HIGH);
   digitalWrite(d,LOW);
 }

//显示数字0
 void digital_0(void)
 {
   digitalWrite(c,LOW);
   digitalWrite(b,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,HIGH);
   digitalWrite(dp,HIGH);
   digitalWrite(a,LOW);
   digitalWrite(e,LOW);
   digitalWrite(d,LOW);
 }

 void setup()
 {
   int i;//定义发量
   for(i=3;i<=10;i++)
     pinMode(i,OUTPUT);//设置3～10 引脚为辒出模式
 }
 void loop()
 {
     while(1)
   {
     digital_1();//数字1
       while(analogRead(0)>512);//如果读到模拟0口癿值为0则说明有按键按下
     delay(200);//延时2s
     digital_2();
       while(analogRead(0)>512);
     delay(200);
     digital_3();
       while(analogRead(0)>512);
     delay(200);
     digital_4();
       while(analogRead(0)>512);
     delay(200);
     digital_5();
       while(analogRead(0)>512);
     delay(200);
     digital_6();
       while(analogRead(0)>512);
     delay(200);
     digital_7();
       while(analogRead(0)>512);
     delay(200);
     digital_8();
       while(analogRead(0)>512);
     delay(200);
     digital_9();
       while(analogRead(0)>512);
     delay(200);
     digital_0();
       while(analogRead(0)>512);
     delay(200);
      }   
}
