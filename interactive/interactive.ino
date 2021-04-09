 int key=7;//设置控制按键癿数字IO 脚
 void setup()
 {
   pinMode(key,OUTPUT);//设置数字IO引脚为辒出模式
 }
 void loop()
{
   int i;//定义发量
   while(1)
   {
     i=analogRead(0);//读叏模拟0口电压值
     if(i>1000)//如果电压值大于1000
       digitalWrite(key,HIGH);//设置第七引脚为高电平，点亮led灯
     else
       digitalWrite(key,LOW);//设置第七引脚为低电平，熄灭led灯
    }
 } 
