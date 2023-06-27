#include <AT24Cxx.h>
#define i2c_address 0x57 //0x57 este codul chipului AT24C32 (i2c_scanner)

AT24Cxx eep(i2c_address, 32); //definirea si initializarea variabilei pentru prelucrarea AT24C32 la adresa i2c_address, avand 32kB

void setup() {
  Serial.begin(9600); //initializare serial
}

void loop() {
  Serial.println(eep.length());
  for(int address = 0; address < 16; address++) //parcurgerea memoriei de la adresa 0 la adresa 16
  {
    int val = eep.read(address); //citirea valorii de la o adresa specifica
    Serial.print("address: "); //afisarea datelor
    Serial.println(address);
    Serial.print("value: ");
    Serial.println(val);
    delay(100);
  } 
  static int i = 0; //definirea unei variabile i, care numara de la 0 la 255 (2^8)
  for(int address = 0; address<16; address++) //parcurgerea memoriei de la adresa 0 la adresa 16
  {
    int val = ++i; //initializarea unei variabile cu o valoare de test
    eep.write(address, val); //scrierea valorii in memorie la adresa specifica
  }
  if(i > 255)
    i = 0;
  delay(100);
}
