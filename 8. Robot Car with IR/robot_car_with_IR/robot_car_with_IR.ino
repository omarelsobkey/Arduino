// 2155849815  up
// 2155866135  right
// 2155817175  left
// 2155833495  down

#include <IRremote.h>
#define ir 12
IRrecv irrecv(ir);
decode_results results;

#define en_a 5
#define en_b 6
#define in1 8
#define in2 9
#define in3 10
#define in4 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinMode(en_a, OUTPUT);
  pinMode(en_b, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(en_a, 255);
  analogWrite(en_b, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    switch(results.value) {
    case 2155849815:
      moveF();
      break;
    case 2155866135:
      turnR();
      break;
    case 2155817175:
      turnL();
      break;
    case 2155833495:
      moveB();
      break;
    default:
      off();
      break;
    }

    irrecv.resume(); // Receive the next value
  }
  delay(500);
}

void moveF() {
  analogWrite(en_a, 255);
  analogWrite(en_b, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveB() {
  analogWrite(en_a, 255);
  analogWrite(en_b, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnR() {
  analogWrite(en_a, 255);
  analogWrite(en_b, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnL() {
  analogWrite(en_a, 255);
  analogWrite(en_b, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void off() {
  analogWrite(en_a, 0);
  analogWrite(en_b, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
