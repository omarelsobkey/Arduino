/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 9/2/2021
********************************************************************/

#define up 13
#define upperL 12
#define lowerL 11
#define down 10
#define lowerR 9
#define upperR 8
#define mid 7

void setup() {
  // put your setup code here, to run once:
  pinMode(up, OUTPUT);
  pinMode(upperL, OUTPUT);
  pinMode(lowerL, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(lowerR, OUTPUT);
  pinMode(upperR, OUTPUT);
  pinMode(mid, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 1
  segment(0, 1, 1, 0, 0, 0, 0);
  // 2
  segment(1, 1, 0, 1, 1, 0, 1);
  // 3
  segment(1, 1, 1, 1, 0, 0, 1);
  // 4
  segment(0, 1, 1, 0, 0, 1, 1);
  // 5
  segment(1, 0, 1, 1, 0, 1, 1);
  // 6
  segment(1, 0, 1, 1, 1, 1, 1);
  // 7
  segment(1, 1, 1, 0, 0, 0, 0);
  // 8
  segment(1, 1, 1, 1, 1, 1, 1);
  // 9
  segment(1, 1, 1, 1, 0, 1, 1);
}

void segment(int s1, int s2, int s3, int s4, int s5, int s6, int s7) {
  digitalWrite(up, s1);
  digitalWrite(upperL, s2);
  digitalWrite(lowerL, s3);
  digitalWrite(down, s4);
  digitalWrite(lowerR, s5);
  digitalWrite(upperR, s6);
  digitalWrite(mid, s7);
  delay(1000);
}
