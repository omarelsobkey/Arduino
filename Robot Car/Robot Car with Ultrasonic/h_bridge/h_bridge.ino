/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 16/1/2021
********************************************************************/

#define en_a 5
#define en_b 6
#define in1 8
#define in2 9
#define in3 10
#define in4 11

#define speed1 150 // motor normal speed
#define speed2 100 // motor turning speed

void setup() {
  // put your setup code here, to run once:
  pinMode(en_a, OUTPUT);
  pinMode(en_b, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  moveF();
  turnR();
  turnL();
  moveB();
  off();
  delay(500);
}

// the 2 motors move forward
void moveF() {
  analogWrite(en_a, speed1);
  analogWrite(en_b, speed1);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(500);
}

// the 2 motors move backward
void moveB() {
  analogWrite(en_a, speed1);
  analogWrite(en_b, speed1);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(500);
}

// the right motor move forward and the left motor moves backward
void turnR() {
  analogWrite(en_a, speed2);
  analogWrite(en_b, speed2);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(1000);
}

// the right motor move backward and the left motor moves forward
void turnL() {
  analogWrite(en_a, speed2);
  analogWrite(en_b, speed2);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(1000);
}

// turns off the 2 motors
void off() {
  analogWrite(en_a, 0);
  analogWrite(en_b, 0);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
