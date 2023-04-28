#include <Servo.h>
#include <SoftwareSerial.h>

// Define o pino do servo motor
int servoPin1 = 6;
int servoPin2 = 2;
Servo servo1;
Servo servo2;

// Define os pinos TX e RX do módulo Bluetooth
int bluetoothTx = 11;
int bluetoothRx = 12;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
}

void loop() {
  // Verifica se há um sinal recebido do aplicativo via Bluetooth
  if (bluetooth.available() > 0) {
    // Lê o sinal recebido do aplicativo
    char signal = bluetooth.read();
    
    if (signal == 'f') {
      servo1.writeMicroseconds(1000);
      servo2.writeMicroseconds(2000);
    }
    else if (signal == 'b') {
      servo1.writeMicroseconds(2000);
      servo2.writeMicroseconds(1000);
    }
    else if (signal == 'r') {
      servo1.writeMicroseconds(1000);
      servo2.writeMicroseconds(1000);
    }
    else if (signal == 'l'){
      servo1.writeMicroseconds(2000);
      servo2.writeMicroseconds(2000);
    }
    else if (signal == 's') {
      servo1.writeMicroseconds(1500);
      servo2.writeMicroseconds(1500);
    }
  }
}