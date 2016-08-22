#include <Arduino.h>
#include "pins.h"

float get_pos(char buf[])
{
  char pos_str[255];
  int i;
  float pos;
//  for(i=0;i<256;i++)
//  {
//    pos_str[i]=NULL;
//  }
  for(i=0;i<256;i++)
  //while(buf[i]!=59)
  {
    pos_str[i]=buf[i+3];
  }
  pos = atof(pos_str);
  return pos;  
}

