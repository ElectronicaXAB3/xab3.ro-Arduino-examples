#include <SoftwareSerial.h>

#define txBT 10 //pinul TX de pe modulul de bluetooth
#define rxBT 11 //pinul RX de pe modulul de bluetooth
#define pompaPin 3 //pinul de la releu (sau alte module de OUTPUT) ce este conectat la pompa

SoftwareSerial BT(txBT, rxBT); //initializare serial pentru comunicarea HC-XX - Arduino

void setup() {
  //definire pin
  pinMode(pompaPin, OUTPUT);
  BT.begin(9600); //initializare bluetooth
}

void loop() {
  if(BT.available()) //verificare daca conexiunea este valabila
  {
    char a = BT.read(); //citeste un caracter
    if(a == '1') //daca a este '1' (de exemplu), atunci pompa se porneste
      digitalWrite(pompaPin, HIGH); //pornire pompa
    else if (a == '0') //daca a este '0' (de exemplu), atunci pompa se opreste
      digitalWrite(pompaPin, LOW); //oprire pompa
  }
  delay(100);
}
