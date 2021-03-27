/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 9/1/2021
********************************************************************/

#include <Servo.h>
Servo myServo;
#define servo 9
void setup() {
  // put your setup code here, to run once:
  myServo.attach(servo);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 180; i++) {
    myServo.write(i);
    delay(1000);
  }
  for (int i = 180; i > 0; i--) {
    myServo.write(i);
    delay(1000);
  }
}
