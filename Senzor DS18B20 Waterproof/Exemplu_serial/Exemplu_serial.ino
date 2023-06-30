#include <DS18B20.h>

DS18B20 ds(2); //initializare senzor
uint8_t address[] = {40, 243, 35, 87, 4, 226, 60, 186}; //adresa unui senzor (pt a obtine adresa tuturor senzorilor, se poate rula exemplul "Exemplu_obtinere_adresa")
uint8_t selected; //variabila pentru a verifica daca a fost selectat modulul (0 daca nu s-a gasit modulul cu adresa respectiva)

void setup() {
  Serial.begin(9600);
  selected = ds.select(address); //selectare modul dupa adresa

  if(!selected)
  {
    Serial.println("Nu s-a gasit niciun modul.");
    while(!selected)
      selected = ds.select(address); //(re)selectare modul dupa adresa
  }
}

void loop() {
  Serial.print(ds.getTempC()); //afisare temperatura in grade celsius.
  //pentru a afisa in grade Fahrenheit, se foloseste functia getTempF()
  Serial.println(" *C");
  delay(100);
}
