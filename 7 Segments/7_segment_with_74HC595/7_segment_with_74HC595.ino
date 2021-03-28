/********************************************************************
  Engineer : Omar Elsobkey
  Version  : 2.0
  Date     : 28/3/2021
********************************************************************/
// now it works with 2 7segments

#define L_DATA_PIN 2
#define L_LATCH_PIN 3
#define L_CLOCK_PIN 4

#define R_DATA_PIN 5
#define R_LATCH_PIN 6
#define R_CLOCK_PIN 7

byte numbers[] = {B11111100,  //0
                  B01100000,  //1
                  B11011010,  //2
                  B11110010,  //3
                  B01100110,  //4
                  B10110110,  //5
                  B10111110,  //6
                  B11100000,  //7
                  B11111110,  //8
                  B11110110
                 }; //9

void setup() {
  pinMode(L_DATA_PIN, OUTPUT);
  pinMode(L_LATCH_PIN, OUTPUT);
  pinMode(L_CLOCK_PIN, OUTPUT);

  pinMode(R_DATA_PIN, OUTPUT);
  pinMode(R_LATCH_PIN, OUTPUT);
  pinMode(R_CLOCK_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 100; i++) {
    display_number(i);
    delay(300);
  }
}

void display_number(byte n) {
  byte left, right;
  right = n % 10;
  left = n / 10;
  digitalWrite(L_LATCH_PIN, LOW);
  digitalWrite(R_LATCH_PIN, LOW);
  shiftOut(L_DATA_PIN, L_CLOCK_PIN, LSBFIRST, numbers[left]);
  shiftOut(R_DATA_PIN, R_CLOCK_PIN, LSBFIRST, numbers[right]);
  digitalWrite(L_LATCH_PIN, HIGH);
  digitalWrite(R_LATCH_PIN, HIGH);

}
