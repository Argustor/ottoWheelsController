#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial HC05(11, 12);
Servo rodaDir;
Servo rodaEsq;

int servoLimiteMin = 1500;
int servoLimiteMax = 2500;

void setup(){
  Serial.begin(9600);
  HC05.begin(9600);
  rodaDir.attach(3);
  rodaEsq.attach(2);
  rodaDir.writeMicroseconds(servoLimiteMin);
  rodaEsq.writeMicroseconds(servoLimiteMax);
}

void loop(){
  if (HC05.available() > 0) {
    char data = HC05.read();
    executeAction(data);
  }
}

void executeAction(char action) {
  switch (action) {
    case 'f':
      moveForward();
      break;
    case 'b':
      moveBackward();
      break;
    default:
      stopMotion();
      break;
  }
}

void moveForward() {
  unsigned long startMillis = millis();
  int increment = 5;
  while (millis() - startMillis < 1000) {
    for (int i = servoLimiteMin; i < servoLimiteMax; i += increment) {
      rodaDir.writeMicroseconds(400 - i);
      rodaEsq.writeMicroseconds(400 + i);
      delay(5);
    }
  }
  stopMotion();
}

void moveBackward() {
  unsigned long startMillis = millis();
  int decrement = 5;
  while (millis() - startMillis < 1000) {
    for (int i = servoLimiteMax; i > servoLimiteMin; i -= decrement) {
      rodaEsq.writeMicroseconds(400 - i);
      rodaDir.writeMicroseconds(400 + i);
      delay(5);
    }
  }
  stopMotion();
}

void stopMotion() {
  rodaDir.writeMicroseconds(servoLimiteMin);
  rodaEsq.writeMicroseconds(servoLimiteMax);
}

