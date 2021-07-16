#include <Servo.h>

Servo servo1;
Servo servo2;

const int trigPin = 9;
const int echoPin = 10;
const int laser = 11;

long duration;
int distance;
int sum = 0;
int count = 0;
int numOfLoops = 300;
int maxDistance = 60; // for 60 cm windows
int servoVal;

void setup() {
  servo1.attach(3);
  servo2.attach(4);

  pinMode(laser, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(laser, LOW); // turn off laser

  /* detecting object and calculating the distance */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  distance = distance + (distance / 15);

  /* calculating the average of the distance and printing the results */
  if (count < numOfLoops) {
    if (distance < 200 && distance > 0) {
      sum += distance;
      count++;
    }
  } else {
    if ((sum / numOfLoops) < maxDistance) { //checking if a new object is arrived
      Serial.println(sum / numOfLoops);
      startExpelling();
    }
    count = 0;
    sum = 0;
  }
}


void startExpelling() {
  digitalWrite(laser, HIGH); //laser ON
  int j = 170;

  //up and down movment
  while (j > 70) {
    servo2.write(j);
    delay(20);
    j--;
  }
  moveLeftToright();
  moveLeftToright();
  moveLeftToright();

  delay(100);
}


//left to right movment
void moveLeftToright() {
  int i = 90;

  while (i < 100) {
    servo1.write(i);
    delay(20);
    i++;
  }
  while (i > 80) {
    servo1.write(i);
    delay(20);
    i--;
  }


  while (i < 90) {
    servo1.write(i);
    delay(20);
    i++;
  }
}
