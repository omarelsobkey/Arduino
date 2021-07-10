/********************************************************************
  Engineer : Omar Elsobkey
  Version  : 1.0
  Date     : 16/1/2021
********************************************************************/

// servo motor
#include <Servo.h>
Servo myservo;
#define servo_motor 7                        // servo motor pin

// h-bridge
#define en_a 5                               // speed control of motor 1
#define en_b 6                               // speed control of motor 2
#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define speed1 120                            // motor normal speed
#define speed2 120                            // motor turning speed

#define delay_time 500                       // turning time

// ultrasonic
#define trigger 12                            // sends HIGH signal and measure the time by echo lens
#define echo 13                               // reads the time the signal took to return
int distance, duration;                       // used by ultrasnic function
int midDistance, rightDistance, leftDistance; // compare between the distances to choose the direction

void setup() {
  // put your setup code here, to run once:
  myservo.attach(servo_motor);
  myservo.write(90); // attach the used pin with servo

  pinMode(en_a, OUTPUT);
  pinMode(en_b, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  midDistance = ultrasonic(); // take ultrasonic distance value
  if (midDistance > 30) {
    moveF();
  }
  else
  {
    if (midDistance <= 10)
      moveB(); // if close to object reverse to get more space to change orientation
    off();                             // stop robot
    myservo.write(45);                 // turn servo Right
    delay(300);
    rightDistance = ultrasonic();          // get right distance
    myservo.write(135);                // turn servo Left
    delay(300);
    leftDistance = ultrasonic();          // get left distance
    myservo.write(90);                 // return to center pos
    delay(300);

    if (rightDistance > 30 || leftDistance > 30) {
      if (rightDistance >= leftDistance) turnR();
      else turnL();
    }
    else moveB();

    off();                             // stop after execute Comparison function action
    delay(150);
  }
}

// reads the distance of the nearest obstacle
int ultrasonic() {
  distance = 0;
  digitalWrite(trigger, LOW);      // make sure that u will start now
  delayMicroseconds(2);            // to make sure that there is no collected signals by the trigger
  digitalWrite(trigger, HIGH);     // will be kept for 10us to initialize measurement by sending US wave.
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);      // stop recieving signals

  duration = pulseIn(echo, HIGH);  // returns the sound wave travel time in microseconds since the start of emitting signals until the echo reads HIGH (recieves signals)
  distance = duration * 0.034 / 2; // Calculating the distance in cm
  return distance;
}

// the 2 motors move forward
void moveF() {
  analogWrite(en_a, speed1);
  analogWrite(en_b, speed1);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// the 2 motors move backward
void moveB() {
  analogWrite(en_a, speed1);
  analogWrite(en_b, speed1);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(250);
}

// the right motor move forward and the left motor moves backward
void turnR() {
  analogWrite(en_a, speed2);
  analogWrite(en_b, speed2);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(delay_time);
}

// the right motor move backward and the left motor moves forward
void turnL() {
  analogWrite(en_a, speed2);
  analogWrite(en_b, speed2);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(delay_time);
}

// turns off the 2 motors
void off() {
  analogWrite(en_a, 0);
  analogWrite(en_b, 0);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
