#define pinSenzor 7 //D7 este pinul legat la senzorul NTC
#define pinRED 6 //D6 este pinul legat la catodul RED
#define pinGREEN 5 //D5 este pinul legat la catodul GREEN

void setup() {
  pinMode(pinSenzor, INPUT); //datele vor fi citite din senzor
  pinMode(pinRED, OUTPUT); //definirea pinului RED
  pinMode(pinGREEN, OUTPUT); //definirea pinului green
}

void loop() {
  int valoare = digitalRead(pinSenzor); //daca valoare = 1 => temperatura setata pe senzor nu a fost atinsa, valoare = 0 => temperatura setata a fost atinsa
  if(valoare) {
    //ledul RGB va afisa culoarea rosie
    digitalWrite(pinGREEN, LOW);
    digitalWrite(pinRED, HIGH);
  }
  else {
    //ledul RGB va afisa culoarea verde
    digitalWrite(pinRED, LOW);
    digitalWrite(pinGREEN, HIGH);
  }
  delay(100);
}