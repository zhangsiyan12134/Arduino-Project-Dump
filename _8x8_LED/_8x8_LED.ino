int Latch = 12; // connect to pin 12 on the '595
int Clock = 11; // connect to pin 11 on the '595
int Data = 13; // connect to pin 14 on the '595
int VRx = 3;
int VRy = 2;
int X = 1;
int Y = 1;
int table[] = {0,1,2,4,8,16,32,64,128};
int dX = 0;
int dY = 255;

void setup()
{
 pinMode(Clock,OUTPUT);
 pinMode(Latch,OUTPUT);
 pinMode(Data,OUTPUT);
}

void loop()
{
  if (analogRead(VRx) > 600)
  {
    if (Y < 8)
    {
      Y += 1;
    } else
    {
      Y = 1;
    }
  }
  if (analogRead(VRx) < 400) 
  {
    if (Y > 1)
    {
      Y -= 1;
    } else
    {
      Y = 8;
    }
  }
  if (analogRead(VRy) < 400) 
  {
    if (X < 8)
    {
      X += 1;
    } else
    {
      X = 1;
    }
  }
  if (analogRead(VRy) > 600) 
  {
    if (X > 1)
    {
      X -= 1;
    } else
    {
      X = 8;
    }
  }
  dX = table[X];
  dY = 255 - table[Y];
  digitalWrite(Latch, LOW);
  shiftOut(Data, Clock, MSBFIRST,dX);
  digitalWrite(Latch, HIGH);    
  digitalWrite(Latch, LOW);
  shiftOut(Data, Clock, MSBFIRST,dY);
  digitalWrite(Latch, HIGH);   
  delay(80);
}

