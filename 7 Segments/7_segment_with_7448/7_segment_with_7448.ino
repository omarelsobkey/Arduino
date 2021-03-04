#define pb 13
#define a 12
#define b 11
#define c 10
#define d 9

int pb_state;

int number[] = {0, 0, 0, 0};
int show = 0, help;

void setup() {
  // put your setup code here, to run once:
  pinMode(pb, INPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);

  segment();
}

void loop() {
  // put your main code here, to run repeatedly:
  pb_state = digitalRead(pb);
  delay(500);
  if (pb_state == HIGH) {
    increment();
    segment();
  }
}

void segment() {
  digitalWrite(a, number[0]);
  digitalWrite(b, number[1]);
  digitalWrite(c, number[2]);
  digitalWrite(d, number[3]);
}

void increment() {
  show++;
  show %= 10;

  help = show;

  for (int i = 0; i < 4; i++) {
    number[i] = help % 2;
    help /= 2;
  }
}
