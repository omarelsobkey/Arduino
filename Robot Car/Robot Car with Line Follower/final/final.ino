// motor shield
#include "AFMotor.h"
#define motorTurningSpeed 65
#define motorSpeed 160
AF_DCMotor motorR (2);
AF_DCMotor motorL (1);

// line follower
#define Black LOW
#define White HIGH
int sensorL = A0;
int sensorM = A1;
int sensorR = A2;
int readingL;
int readingM;
int readingR;

bool stopfinal = 0;

void setup() {
  pinMode(sensorL, INPUT);
  pinMode(sensorM, INPUT);
  pinMode(sensorR, INPUT);
}

void loop() {

  if (!stopfinal) {
    readingM = digitalRead(sensorM);
    readingL = digitalRead(sensorL);
    readingR = digitalRead(sensorR);

    // move forward
    if ((readingL == White && readingM == Black && readingR == White ) ||
        (readingL == White && readingM == White && readingR == White ))
      moveF();

    // finish line
    else if (readingL == Black && readingM == Black && readingR == Black )
    {
      moveF();
      delay(500);
      stopM();
      stopfinal = 1;
    }

    // turn left
    else if ((readingL == Black && readingM == White && readingR == White ) ||
             (readingL == Black && readingM == Black && readingR == White ))
      turnL();

    // turn right
    else if ((readingL == White && readingM == White && readingR == Black ) ||
             (readingL == White && readingM == Black && readingR == Black ))
      turnR();

    // turn off because wrong reading
    else
      stopM();
  }
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
