#include <Servo.h>
#include <SoftwareSerial.h>

// Define o pino do servo motor
//int servoPin = 6;
SoftwareSerial HC05(11, 12);
Servo servo1;
Servo servo2;

// Define os pinos TX e RX do módulo Bluetooth
//int bluetoothTx = 10;
//int bluetoothRx = 11;
//SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  Serial.begin(9600);
  HC05.begin(9600);
  servo1.attach(6);
  servo2.attach(2);
}

void loop() {
  // Verifica se há um sinal recebido do aplicativo via Bluetooth
  if (HC05.available() > 0) {
    // Lê o sinal recebido do aplicativo
    char signal = HC05.read();
    
    if (signal == 'f') {
      
      servo1.write(0);
      servo2.write(180);
    }
    
    else if (signal == 'b') {
      // Move o servo motor para a posição 0 graus
      servo1.write(180);
      servo2.write(0);
    }
    
    else if (signal == 'r') {
      servo1.write(0);
      servo2.write(0);
    }

    else if (signal == 'l'){
      servo1.write(180);
      servo2.write(180);
    }
    else if (signal == 's') {
      // Move o servo motor para a posição central (90 graus)
      servo1.write(90);
      servo2.write(90);
    }
  }
}
