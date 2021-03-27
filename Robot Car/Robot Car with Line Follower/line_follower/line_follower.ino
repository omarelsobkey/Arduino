/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 12/1/2021
********************************************************************/

#define Black LOW
#define White HIGH

int sensorL = A0;
int sensorM = A1;
int sensorR = A2;

int readingL;
int readingM;
int readingR;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorL, INPUT);
  pinMode(sensorM, INPUT);
  pinMode(sensorR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readingM = digitalRead(sensorM);
  readingL = digitalRead(sensorL);
  readingR = digitalRead(sensorR);
}
