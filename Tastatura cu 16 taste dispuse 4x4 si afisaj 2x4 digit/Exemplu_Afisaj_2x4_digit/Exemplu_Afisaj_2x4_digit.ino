#include <LedControl.h>
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
LedControl lc = LedControl(12, 11, 10, 1); //initializare afisaj

void setup(){
  Serial.begin(9600);
  lc.shutdown(0, false); //pornire afisaj
  lc.clearDisplay(0); //golire afisaj
}

void setChar(char* text) //functie pentru setarea caracterului pe pozitia poz
{
  lc.clearDisplay(0); //golire afisaj
  for(int i = 0; i<strlen(text); i++)
  {
    lc.setChar(0, 7-i, text[i],false); //setarea caracterului key pe pozitia poz
    //echivalentul setChar pentru afisarea unui numar, folosind variabila int este setDigit
  }
}

int poz = 0; //variabila pentru numarul de caractere introduse

void loop() {
  char key = keypad.getKey(); //citire caracter
  char txt[8]; //variabila unde vor fi memorate toate caracterele
  if(key) //daca a fost apasat, se afiseaza caracterul
  {
    Serial.print(key);
    if(poz < 8 && key <= '9' && key >= '0') //sa se afiseze doar caractere numerice
      txt[poz++] = key;

    //A va avea rolul de a sterge un caracter
    if(key == 'A') //stergem ultimul caracter
    {
      txt[poz - 1] = 0; //stergem ultimul caracter
      poz--; //pozitia va fi decrementata
    }
    setChar(txt); //setare caractere pe afisaj
  }
  delay(100);
}