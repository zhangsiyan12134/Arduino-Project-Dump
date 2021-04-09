int Latch = 12; // connect to pin 12 on the '595
int Clock = 11; // connect to pin 11 on the '595
int Data = 13; // connect to pin 14 on the '595

void setup()
{
 pinMode(Clock,OUTPUT);
 pinMode(Latch,OUTPUT);
 pinMode(Data,OUTPUT);
}

void loop()
{
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,1);
    digitalWrite(Latch, HIGH);    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,254);
    digitalWrite(Latch, HIGH);
    delay(200);    
    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,2);
    digitalWrite(Latch, HIGH);    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,253);
    digitalWrite(Latch, HIGH); 
    delay(200);
    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,4);
    digitalWrite(Latch, HIGH);    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,251);
    digitalWrite(Latch, HIGH);
    delay(200);
    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,8);
    digitalWrite(Latch, HIGH);    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,247);
    digitalWrite(Latch, HIGH);
    delay(200);
    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,16);
    digitalWrite(Latch, HIGH);    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,239);
    digitalWrite(Latch, HIGH);
    delay(200);
    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,32);
    digitalWrite(Latch, HIGH);    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,223);
    digitalWrite(Latch, HIGH);
    delay(200);
    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,64);
    digitalWrite(Latch, HIGH);    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,191);
    digitalWrite(Latch, HIGH);
    delay(200);
    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,128);
    digitalWrite(Latch, HIGH);    
    digitalWrite(Latch, LOW);
    shiftOut(Data, Clock, MSBFIRST,127);
    digitalWrite(Latch, HIGH);
    delay(200);
}

