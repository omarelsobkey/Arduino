/********************************************************************
  Engineer : Omar Elsobkey
  Version  : 1.0
  Date     : 9/1/2021
********************************************************************/

#define trigger 10
#define echo 11
int distance, duration;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);  // returns duration in microseconds
  distance = duration * 0.034 / 2; // ( duration * 10^-3 ) * speed of waves (340m/s) / 2
                                   // 2 is (half of the time that wave traveled from trigger to obstacle then again to echo)
  Serial.println(distance);
}
