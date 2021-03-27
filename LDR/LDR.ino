/********************************************************************
Engineer : Omar Elsobkey
Version  : 1.0
Date     : 12/1/2021
********************************************************************/

#define ldr A0
#define led 8
int light;
void setup()
{
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  light = analogRead(ldr);
  Serial.println(light);
  if (light < 50) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
}
