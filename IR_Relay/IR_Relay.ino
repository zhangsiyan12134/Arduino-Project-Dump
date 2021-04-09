#include <IRremote.h>

int RECV_PIN = 2;
int Relay = 9;
int Power = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  irrecv.enableIRIn(); //初始化红外遥控
  pinMode(Relay,OUTPUT);
  pinMode(RECV_PIN,INPUT);
  pinMode(Power,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(Power,HIGH);
  if (irrecv.decode(&results)) 
  {
    if(results.value==551504565)         //确认接收到的第一排按键1的编码，此码是预先读出来的按键编码。
    {
      digitalWrite(Relay,HIGH);                
      digitalWrite(13,HIGH);            //点亮LED
    }
    else if(results.value==551537205)   //确认接收到的第一排按键2的编码
    {
      digitalWrite(Relay,LOW);            
      digitalWrite(13,LOW);            //熄灭LED
    }
    irrecv.resume(); // 接收下一个值
  }
}

