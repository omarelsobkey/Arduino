/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 12/2/2021
********************************************************************/

#define pb1 7
#define pb2 8
#define pb3 9

void setup() {
  // put your setup code here, to run once:
  pinMode(pb1, INPUT);
  pinMode(pb2, INPUT);
  pinMode(pb3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int counter = 0;
  for (int i = 0; i < 3; i++) {
    digitalRead(pb1);
    digitalRead(pb2);
    digitalRead(pb3);

    if (pb2 && counter == 0) counter++;
    else if (pb3 && counter == 1) counter++;
    else if (pb1 && counter == 2) counter++;
    else break;
  }
  if (counter == 3) Serial.println("Correct Pattern");
  else Serial.println("Wrong Pattern");
}
