/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 6/1/2021
********************************************************************/

// 2155849815  up
// 2155866135  right
// 2155817175  left
// 2155833495  down

#include <IRremote.h>
#define ir 8
IRrecv irrecv(ir);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);   // show the code in HEXADECIMAL form you shold convert it into DEC (decimal) to use it in the reciver code 
    irrecv.resume(); // Receive the next value
  }
  delay(500);
}
