#include <HX711.h>

#define DT 2 //pinul DT de pe modul
#define SCK 3 //pinul SCK de pe modul

HX711 scale; //definire modul

void setup() {
  Serial.begin(9600);
  scale.begin(DT, SCK); //initializare modul
  scale.set_scale(-400); //calibrare modul
  //pentru calibrare, initial se lasa argumentul gol ("scale.setscale()"), iar dupa se va pune o greutate cunoscuta
  //de pilda 100g. Se folosese formula calibrare = valoare_citita / valoare_cunoscuta
  Serial.println("Initializare...");
  delay(1000);
  scale.tare();
  Serial.println("Initializat.");
}

void loop() {
  if(scale.is_ready()) //verificare daca senzorul este pregatit
  {
    long value = scale.get_units(); //se citeste valoarea de pe cantar (dupa calibrare, daca este cazul)
    Serial.println(value); //afisare valoare
  }
  delay(100);
}
