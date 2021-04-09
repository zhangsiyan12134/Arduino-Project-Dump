 int a=13;
 int b=12; 
 int c=11; 
 int d=10; 
 int e=9; 
 int f=8; 
 int g=7; 
 int dp=6;
  
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
   for(i=3;i<=13;i++)
     pinMode(i,OUTPUT);//设置3～10 引脚为辒出模式
 }
 void loop()
 {
     while(1)
   {
     digital_0();
       while((analogRead(5)>=0) and (analogRead(5)<102));
     digital_1();
       while((analogRead(5)>=102) and (analogRead(5)<204));
     digital_2();//数字1
       while((analogRead(5)>=204) and (analogRead(5)<306));//如果读到模拟0口癿值为0则说明有按键按下
     digital_3();
       while((analogRead(5)>=306) and (analogRead(5)<408));
     digital_4();
       while((analogRead(5)>=408) and (analogRead(5)<510));
     digital_5();
       while((analogRead(5)>=510) and (analogRead(5)<612));
     digital_6();
       while((analogRead(5)>=612) and (analogRead(5)<714));
     digital_7();
       while((analogRead(5)>=714) and (analogRead(5)<816));
     digital_8();
       while((analogRead(5)>=816) and (analogRead(5)<918));
     digital_9();
       while(analogRead(5)>=918);
      }   
}
