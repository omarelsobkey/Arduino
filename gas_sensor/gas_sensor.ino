#define gasSensor A0
#define redLed 7
#define greenLed 8

float gas;

void setup() {
  // put your setup code here, to run once:
  pinMode(gasSensor, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  gas = map(analogRead(gasSensor), 0.0, 5.0, 200.0, 10000.0);
  if (gas > 1000) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  }
}
