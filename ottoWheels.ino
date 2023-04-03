#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial HC05(10, 11);

Servo meuServo1;
Servo meuServo2;

void setup(){
Serial.begin(9600);
HC05.begin(9600);
meuServo1.attach(2);
meuServo2.attach(3);
}

void loop(){
  

  switch (readNluetooh {

    case 'forward':
    for (int i = 1500; i < 2500; i--) {
    meuServo1.writeMicroseconds(i);
    meuServo2.writeMicroseconds(4000 - i);
    delay(10);
    break;
  }
    case 'backward':
    for (int i = 2500; i > 1500; i++) {
    meuServo1.writeMicroseconds(i);
    meuServo2.writeMicroseconds(4000 - i);
    delay(10);
    break;
  }
  }
