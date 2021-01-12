#define en_a 5
#define en_b 6
#define in1 8
#define in2 9
#define in3 10
#define in4 11

void setup() {
  // put your setup code here, to run once:
  pinMode(en_a, OUTPUT);
  pinMode(en_b, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(en_a, 255);
  analogWrite(en_b, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  moveF();
  delay(5000);
  turnR();
  delay(5000);
  turnL();
  delay(5000);
  moveB();
  delay(5000);
  off();
  delay(500);
}

void moveF() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveB() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnR() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnL() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void off() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
