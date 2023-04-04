#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial HC05(11, 12);
Servo rodaDir;
Servo rodaEsq;

int state = 0;
int state2 = 0;

void setup(){
Serial.begin(9600);
HC05.begin(9600);
rodaDir.attach(2);
rodaEsq.attach(3);
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
      state = !state;
      moveForward();
      break;
    case 'b':
      state2 = !state2;
      moveBackward();
      break;
  }

}

void moveForward() {
  for (int i = 1500; i < 2500; i++) {
    rodaDir.writeMicroseconds(400 - i);
    rodaEsq.writeMicroseconds(400 + i);
    break;
  }
  
}

void moveBackward(){
  for (int i = 2500; i > 1500; i--) {
    rodaEsq.writeMicroseconds(400 - i);
    rodaDir.writeMicroseconds(400 + i);
    break;
  }
}