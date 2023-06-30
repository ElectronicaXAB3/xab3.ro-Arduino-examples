#include <Keypad.h>

const byte ROWS = 4; //4 randuri
const byte COLS = 4; //4 coloane

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; //tastele puse intr-o matrice, caracterele pot fi modificate

byte rowPins[ROWS] = {9, 8, 7, 6}; //ROW pins conectati la D9, D8, D7, D6
byte colPins[COLS] = {5, 4, 3, 2}; //COLUMN pins conectati la D5, D4, D3, D2

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //initializare keypad

void setup(){
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey(); //citire caracter
  if(key) //daca a fost apasat, se afiseaza caracterul
    Serial.print(key);
  delay(100);
}
