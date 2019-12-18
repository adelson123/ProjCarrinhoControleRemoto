#include <SoftwareSerial.h>

char caracter;

//pinos:
SoftwareSerial serial1(15, 14); // TX e RX do bluetooth HC-05

int buzzer = 17; //A3


int motorA1 = 9,
    motorA2 = 6,
    motorB1 = 5,
    motorB2 = 3;

void setup() {

  serial1.begin(9600);
  Serial.begin(9600);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(buzzer, OUTPUT);
}

void loop() {

  ler_BT();

}

void ler_BT() {

  if (serial1.available()) {
    caracter = serial1.read();
    Serial.println(caracter);

    switch (caracter) {
      case 'F':
        frente(100);
        break;

      case 'B':
        re(100);
        break;

      case 'L':
        esquerda(100);
        break;

      case 'R':
        direita(100);
        break;

      case 'S':
        parar();
        break;
    }
  }
}

void frente(int x) {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, x);
  analogWrite(motorB1, x);
  analogWrite(motorB2, 0);

}

void re(int x) {
  analogWrite(motorA1, x);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, x);
}


void parar() {

  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);

}

void direita(int x) {

  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, x);
  analogWrite(motorB2, 0);
}

void esquerda(int x) {

  analogWrite(motorA1, 0);
  analogWrite(motorA2, x);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}


