//*************************************************************
//    This program is use to show the steps of Traffic Light.
//            By Siyan Zhang @ George Brown College
//                        ID 100757256
//                      Data 2012-09-21
//*************************************************************

#define RLEDNS 13  //Define the North-Sourth Red Light
#define YLEDNS 12
#define GLEDNS 11

#define RLEDEW 7
#define YLEDEW 6
#define GLEDEW 5

int RT = 5000;  //Define time of Red Light
int GT = 3500;
int YT = 1500;

void setup()
{
  pinMode(RLEDNS,OUTPUT);  //Config pins mode
  pinMode(YLEDNS,OUTPUT);
  pinMode(GLEDNS,OUTPUT);

  pinMode(RLEDEW,OUTPUT);
  pinMode(YLEDEW,OUTPUT);
  pinMode(GLEDEW,OUTPUT);
}

void loop()
{
  digitalWrite(RLEDNS,HIGH);
  delay(300);  //This delay means the length of two Red Light lit at same time.
  digitalWrite(RLEDEW,LOW);  //To make a perfect cycle, I need to tern off East-West Red Lightwhich was turn on in previous cycle.
  digitalWrite(GLEDEW,HIGH);
  delay(GT);
  digitalWrite(GLEDEW,LOW);
  digitalWrite(YLEDEW,HIGH);
  delay(YT);
  digitalWrite(YLEDEW,LOW);
  digitalWrite(RLEDEW,HIGH);
  delay(300);  //This delay also means the length of two Red Light lit at same time.

  digitalWrite(RLEDNS,LOW);
  for (int i=1; i<=4; i++ )  //This loop is use to make Green Light Flashing.
  {
    digitalWrite(GLEDNS,HIGH);
    delay(200);
    digitalWrite(GLEDNS,LOW);
    delay(200);
  }
  digitalWrite(GLEDNS,HIGH);
  delay(GT);
  digitalWrite(GLEDNS,LOW);
  digitalWrite(YLEDNS,HIGH);
  delay(YT);
  digitalWrite(YLEDNS,LOW);
}


