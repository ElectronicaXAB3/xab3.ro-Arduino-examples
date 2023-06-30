#include <DS18B20.h>

DS18B20 ds(2); //modulul este initializat

void setup() {
  Serial.begin(9600);
  Serial.print("Devices: "); //numarul de senzori conectati la D2
  Serial.println(ds.getNumberOfDevices());
  Serial.println();
}

void loop() {
  while (ds.selectNext()) { //parcurgere fiecare senzor
    switch (ds.getFamilyCode()) { //afisare modelul senzorului
      case MODEL_DS18S20:
        Serial.println("Model: DS18S20/DS1820");
        break;
      case MODEL_DS1822:
        Serial.println("Model: DS1822");
        break;
      case MODEL_DS18B20:
        Serial.println("Model: DS18B20");
        break;
      default: //afisare mesaj in cazul in care a fost detectat un modul, dar este necunoscut
        Serial.println("Unrecognized Device");
        break;
    }

    uint8_t address[8]; //initializare variabila pentru adresa
    ds.getAddress(address); //obtinere adresa modulului selectat

    Serial.print("Address:"); //afisare adresa modulului selectat (important pentru a obtine date de la un senzor specific)
    for (uint8_t i = 0; i < 8; i++) {
      Serial.print(" ");
      Serial.print(address[i]);
    }
    Serial.println();
  }

  delay(10000);
}