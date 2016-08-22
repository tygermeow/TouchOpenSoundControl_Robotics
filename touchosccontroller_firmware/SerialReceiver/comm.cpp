#include <Arduino.h>
void get_serial_buffer(char buf[])
{
  int i=0;
  char incomingByte;
  int incoming = 0;
  // put your main code here, to run repeatedly:
  while(incoming!=59)
  {
    incoming=0;
    if (Serial.available() > 0) 
    {
        // read the incoming byte:
        incomingByte = Serial.read();
        incoming = incomingByte;
        #ifdef DEBUG
          Serial.print(incomingByte);
          Serial.print("   ");
          Serial.println(incoming);
        #endif
        buf[i]=incomingByte;
        i++;
    }
  }
}
char process_signal_buf(char buf[])
{
  if(buf[0]=='R')
  {
    return 'r';
  }
  if(buf[0]=='M'&&buf[1]=='1')
  {
    return 'x';
  }
  
  if(buf[0]=='M'&&buf[1]=='2')
  {
    return 'y';
  }
}


