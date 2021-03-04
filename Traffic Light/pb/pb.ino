#define pb 8
bool pb_state = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pb, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pb_state = digitalRead(pb);
  Serial.println(pb_state);
}
