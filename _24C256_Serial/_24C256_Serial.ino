 /* 
  *  Use the I2C bus with EEPROM 24LC64 
  *  Sketch:    eeprom.pde
  *  
  *  Author: hkhijhe
  *  Date: 01/10/2010
  * 
  *   
  */

  #include <Wire.h> //I2C library



  void i2c_eeprom_write_byte( int deviceaddress, unsigned int eeaddress, byte data ) {
    int rdata = data;
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.write(rdata);
    Wire.endTransmission();
  }

  // WARNING: address is a page address, 6-bit end will wrap around
  // also, data can be maximum of about 30 bytes, because the Wire library has a buffer of 32 bytes
  void i2c_eeprom_write_page( int deviceaddress, unsigned int eeaddresspage, byte* data, byte length ) {
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddresspage >> 8)); // MSB
    Wire.write((int)(eeaddresspage & 0xFF)); // LSB
    byte c;
    for ( c = 0; c < length; c++)
      Wire.write(data[c]);
    Wire.endTransmission();
  }

  byte i2c_eeprom_read_byte( int deviceaddress, unsigned int eeaddress ) {
    byte rdata = 0xFF;
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(deviceaddress,1);
    if (Wire.available()) rdata = Wire.read();
    return rdata;
  }

  // maybe let's not read more than 30 or 32 bytes at a time!
  void i2c_eeprom_read_buffer( int deviceaddress, unsigned int eeaddress, byte *buffer, int length ) {
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(deviceaddress,length);
    int c = 0;
    for ( c = 0; c < length; c++ )
      if (Wire.available()) buffer[c] = Wire.read();
  }

  int Add = 0;
  int OP = 0;
  char Data;

  void setup() 
  {
    Wire.begin(); // initialise the connection
    Serial.begin(9600);
      Serial.println( 'Please select a operation you want:' );
      Serial.println( '1--Write' );
      Serial.println( '2--Read' );
      OP = Serial.read();
      delay(5000);
      Serial.println( 'Please input a address you want:' );    
      Add = Serial.read();
      delay(5000);
      Serial.println( 'Please input the Data you want:' );    
      Data = Serial.read(); 
      delay(5000);  
  }

  void loop() 
  {  
    if ( OP == 1 )
    {
      i2c_eeprom_write_page(0x50, Add, (byte *)Data, sizeof(Data)); // write to EEPROM 
      delay(10); //add a small delay 
    }
    if ( OP == 2 )
    {
    //int addr=0; //first address
      byte b = i2c_eeprom_read_byte(0x50, 0); // access the first address from the memory

      while (b!=0) 
      {
        Serial.print((char)b); //print content to serial port
        Add++; //increase address
        b = i2c_eeprom_read_byte(0x50, Add); //access an address from the memory
      }
    }  
    Serial.println(" ");
    delay(2000);
    }

 

