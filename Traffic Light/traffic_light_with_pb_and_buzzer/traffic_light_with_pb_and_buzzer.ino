/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 12/1/2021
********************************************************************/

#define pb 8
#define r_led 3
#define g_led 5
#define b_led 6
#define buzzer 12

bool pb_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(pb, INPUT_PULLUP);
  pinMode(r_led, OUTPUT);
  pinMode(g_led, OUTPUT);
  pinMode(b_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pb_state = digitalRead(pb);
  if (pb_state) {
    led(255, 0, 0);
    led(255, 255, 0);
    digitalWrite(buzzer, HIGH);
    led(0, 255, 0);
    digitalWrite(buzzer, LOW);
  }
  else {
    led(0, 0, 0);
  }
}

void led(int red, int green, int blue) {
  analogWrite(r_led, red);
  analogWrite(g_led, green);
  analogWrite(b_led, blue);
  delay(1000);
}
