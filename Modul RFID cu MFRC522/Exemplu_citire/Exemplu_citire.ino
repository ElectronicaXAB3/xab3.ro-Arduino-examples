#include <SPI.h>
#include <MFRC522.h>

//definire pini RFID module
#define SS_PIN 10
#define RST_PIN 9

//definire pin yala sau alte module de output
#define outPIN 3

MFRC522 mfrc522(SS_PIN, RST_PIN); //definire modul RFID

void setup() {
  Serial.begin(9600);
  pinMode(outPIN, OUTPUT); //initializare outPIN
  SPI.begin(); //initializare SPI
  mfrc522.PCD_Init(); //initializare modul
}

void loop() {
  if(mfrc522.PICC_IsNewCardPresent()) //verificare daca este card valid
  {
    if(mfrc522.PICC_ReadCardSerial()) //verificare daca se poate citi cardul
    {
      String tag = ""; //tag va fi sub forma HEX (string)
      for(byte i = 0; i<mfrc522.uid.size; i++) //parcurgere fiecare bit citit
      {
        //adaugare cod hex sub forma ff in string
        tag.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        tag.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
      tag.toUpperCase(); //formatare text astfel incat sa fie doar majuscule
      if(tag.substring(1) == "AA 59 18 B1") //verificare daca tagul citit este cel permis (de pilda, tagul permis ar fi "AA 59 18 B1")
      {
        //exemplul este pentru o posibila yala
        digitalWrite(pinOUT, HIGH); //pornire modul de OUTPUT
        delay(2000); //asteptare 2s pana se opreste
        digitalWrite(pinOUT, LOW); //oprire modul de OUTPUT
      }
    }
  }
  delay(1000);
}
