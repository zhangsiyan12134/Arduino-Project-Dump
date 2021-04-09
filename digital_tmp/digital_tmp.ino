/*
例子 2.1 - 数字温度计
创建于 14/04/2010 ---  作者 John Boxall --- http://tronixstuff.wordpress.com ---  CC by-sa v3.0
使用 Analog Devices 出品的 TMP36 来测量温度并通过串口返回测量结果
TMP36 引脚1连接到 Arduino 5V 电源插孔
TMP36 引脚2连接到 Arduino 模拟端口0
TMP36 引脚3连接到 Arduino GND 插孔
*/
void setup()
{
Serial.begin(9600);   // 激活串口输入输出
}
float voltage = 0; // 设置一些变量
float sensor = 0;
float celsius = 0;
float fahrenheit = 0;
void loop()
{              // 开始测量
sensor = analogRead(1);
voltage = (sensor*5000)/1024; // 将回传值转化成电压值（毫伏）
voltage = voltage-500;        // 去除偏移电压
celsius = voltage/10;         // 转化电压值为摄氏度
fahrenheit = ((celsius * 1.8)+32); // 转化摄氏度到华氏度
Serial.print("Temperature: ");
Serial.print(celsius,2);
Serial.println(" degrees C");
Serial.print("Temperature: ");
Serial.print(fahrenheit,2);
Serial.println(" degrees F");
Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
delay (1000); // 等待一秒，否则串口观察窗口刷新太快难以阅读
}

