#include "AFMotor.h"

#define motorTurningSpeed 65
#define motorSpeed 160

AF_DCMotor motorR (2);
AF_DCMotor motorL (1);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  moveF();
  turnL();
  turnR();
  stopM();
}

void moveF() {
  motorR.setSpeed(MotorSpeed);
  motorL.setSpeed(MotorSpeed);
  motorR.run(FORWARD);
  motorL.run(FORWARD);
}

void turnL() {
  motorR.setSpeed(motorTurningSpeed + 20);
  motorL.setSpeed(motorTurningSpeededlr);
  motorR.run(FORWARD);
  motorL.run(BACKWARD);
}

void turnR() {
  motorR.setSpeed(motorTurningSpeed);
  motorL.setSpeed(motorTurningSpeed + 20);
  motorR.run(BACKWARD);
  motorL.run(FORWARD);
}

void stopM() {
  motorR.setSpeed(0);
  motorL.setSpeed(0);
  motorR.run(RELEASE);
  motorL.run(RELEASE);
}
