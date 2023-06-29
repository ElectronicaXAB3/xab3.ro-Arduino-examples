#include <SPI.h>
#include <MFRC522.h>

//definire pini RFID module
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); //definire modul RFID

void setup() {
  Serial.begin(9600);
  SPI.begin(); //initializare SPI
  mfrc522.PCD_Init(); //initializare modul
}

void loop() {
  if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
  {
    byte newData[] = {0x01, 0x02, 0x03, 0x04, 0x05}; //biti ce vor fi scrisi pe card, acesta este doar un exemplu
    if(mfrc522.MIFARE_Write(1, newData, sizeof(newData))) //scriere date pe tag.
      Serial.println("Scris cu succes.");
    else //in cazul in care exista erori de scriere, se va afisa urmatorul mesaj
      Serial.println("Nu s-a putut scrie in noul tag.");
  }
  delay(100);
}
