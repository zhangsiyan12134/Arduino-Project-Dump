#include <EtherCard.h>
#include <IRremote.h>

static byte mymac[] = {0x74,0x69,0x69,0x2D,0x30,0x31};
static byte myip[] = {192,168,1,10};
byte Ethernet::buffer[700];

boolean ledStatus;

char* on = "ON";
char* off = "OFF";
char* statusLabel;
char* buttonLabel;

IRsend irsend;

void setup () {
 
  Serial.begin(57600);
  Serial.println("WebLed Demo");
 
  if (!ether.begin(sizeof Ethernet::buffer, mymac, 10))
    Serial.println( "Failed to access Ethernet controller");
 else
   Serial.println("Ethernet controller initialized");
 
  if (!ether.staticSetup(myip))
    Serial.println("Failed to set IP address");

  pinMode(3,OUTPUT);
  Serial.println();
  ledStatus = false;
}
  
void loop() {
 
  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);
  
  if(pos) {
    
    if(strstr((char *)Ethernet::buffer + pos, "GET /?status=ON") != 0) {
      Serial.println("Received ON command");
      ledStatus = true;
    }

    if(strstr((char *)Ethernet::buffer + pos, "GET /?status=OFF") != 0) {
      Serial.println("Received OFF command");
      ledStatus = false;
    }
    
    if(ledStatus) {
      SendSignal(0x20DF4AB5);
      statusLabel = on;
      buttonLabel = off;
    } else {
      SendSignal(0x20DFCA35);
      statusLabel = off;
      buttonLabel = on;
    }
      
    BufferFiller bfill = ether.tcpOffset();
    bfill.emit_p(PSTR("HTTP/1.0 200 OK\r\n"
      "Content-Type: text/html\r\nPragma: no-cache\r\n\r\n"
      "<html><head><title>WebLed</title></head>"
      "<body>LED Status: $S "
      "<a href=\"/?status=$S\"><input type=\"button\" value=\"$S\"></a>"
      "</body></html>"      
      ), statusLabel, buttonLabel, buttonLabel);
    ether.httpServerReply(bfill.position());
  }
}

void SendSignal(int tmp) {
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(tmp, 32); // Sony TV power code
    delay(40);
  }
}
