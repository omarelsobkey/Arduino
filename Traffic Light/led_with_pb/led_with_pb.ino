/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 12/1/2021
********************************************************************/

#define pb 8
#define led 13
bool pb_state = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pb, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pb_state = digitalRead(pb);
  if (pb_state == 0) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
}
