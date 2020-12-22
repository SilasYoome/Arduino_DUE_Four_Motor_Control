#include <Arduino.h>
#include "ArduinoDUEtest.h"
#include "Encoder.h"
#include "config.h"
#include "GY85.h"
#include <Wire.h>

ArduinoDUEtest en;
GY_85 GY85_1;
int flag;


void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial2.begin(9600);
  GY85_1.init();
}

void loop() {
  if(Serial2.available()){
      flag = Serial2.read();
  }
  switch(flag){
      case 'w': 
              en.Fwd(200);
              break;
      case 'x': 
              en.Back(200);
              break;
      case 'a': 
              en.Left(200);
              break;
      case 'd': 
              en.Right(200);
              break;
      case 'q': 
              en.LeftFwd(200);
              break;
      case 'e': 
              en.RightFwd(200);
              break;
      case 'z': 
              en.LeftBack(200);
              break;
      case 'c': 
              en.RightBack(200);
              break;
      case 'v': 
              en.TurnLeft(200);
              break;
      case 'b': 
              en.TurnRight(200);
              break;
      default:
              en.brake();
  }
  Serial.println(flag);
  //en.Fwd(120);
  //en.PrintEncoder();
}