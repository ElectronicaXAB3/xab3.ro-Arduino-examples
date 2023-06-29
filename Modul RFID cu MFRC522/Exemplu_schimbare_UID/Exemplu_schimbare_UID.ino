#include <SPI.h>
#include <MFRC522.h>

//definire pini RFID module
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); //definire modul RFID
MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin(); //initializare SPI
  mfrc522.PCD_Init(); //initializare modul
}

void loop() {
  byte newUID[] = {0xAA, 0xBB, 0x12, 0x13}; //exemplu de UID (size MAX: 4)
  if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) //verificare daca cardul citit este valid si daca se poate citi cardul
  {
    if(mfrc522.MIFARE_SetUid(newUID, (byte)4, true)) //se incearca scrierea noului UID (este format din 4 octeti)
      Serial.println("Noul UID a fost scris.");
    else //se afiseaza mesajul de mai jos in caz contrar
      Serial.println("Nu s-a putut scrie noul UID.");
    
    //afisarea UID.
    Serial.println("Noul UID si continutul:");
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  }
  delay(100);
}
