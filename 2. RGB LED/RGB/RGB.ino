const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
//const int redPin=11,greenPin=10,bluePin=9;
int d = 2000;
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  setColor(255, 0, 0); // red
  delay(d);
  setColor(0, 255, 0); // green
  delay(d);
  setColor(0, 0, 255); // blue
  delay(d);
  setColor(255, 255, 0); // yellow
  delay(d);
  setColor(80, 0, 80); // purple
  delay(d);
  setColor(0, 255, 255); // aqua
  delay(d);
}
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
