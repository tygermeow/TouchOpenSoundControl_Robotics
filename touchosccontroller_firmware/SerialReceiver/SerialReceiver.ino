#include <Servo.h>

#include <stdio.h>
#include "comm.h"
#include "motion.h"
#include "pins.h"
#include <Servo.h>
#include "Arduino.h"

Servo rudder;


char buf[255];
char ctrl_sig;
float pos;

//This was supposed to be a part of motion.cpp but the servo functions did not work
void do_motion(char ctrl_sig,float pos);

void setup() {
  rudder.attach(RUDDER);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  Serial.begin(38400);
  while(!Serial)
  {
    
  }

}


void loop() 
{
  get_serial_buffer(buf);
  //Serial.println(buf);
  //Process which control is being sent
  ctrl_sig = process_signal_buf(buf);
  //Serial.println(ctrl_sig);
  pos = get_pos(buf);
  //Serial.println(pos);
  do_motion(ctrl_sig,pos);
   // print_result:
 //   Serial.println(buf);
//    pos = atof(buf);
//    Serial.println(pos);
    Serial.read();
    delay(20);

}

void do_motion(char ctrl_sig,float pos)
{
  switch(ctrl_sig)
  {
    case 'r':
    rudder.write((int)pos);
    #ifdef DEBUG
      Serial.print("Rudder:");
      Serial.println((int)pos);
    #endif
    break;
    case 'x':
    analogWrite(MOTOR1,(int)pos);
    #ifdef DEBUG
      Serial.print("Motor 1:");
      Serial.println((int)pos);
    #endif
    break;
    case 'y':
    analogWrite(MOTOR2,(int)pos);
    #ifdef DEBUG
      Serial.print("Motor2:");
      Serial.println((int)pos);
    #endif
    break;
  }
}
