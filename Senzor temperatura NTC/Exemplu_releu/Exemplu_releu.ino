#define pinSenzor 7 //D7 este pinul legat la senzorul NTC
#define pinReleu 6 //D6 este pinul legat la releu

void setup() {
  pinMode(pinSenzor, INPUT); //datele vor fi citite din senzor
  pinMode(pinReleu, OUTPUT); //Outputul va fi prin releu
}

void loop() {
  int valoare = digitalRead(pinSenzor); //daca valoare = 1 => temperatura setata pe senzor nu a fost atinsa, valoare = 0 => temperatura setata a fost atinsa
  if(valoare)
    digitalWrite(pinReleu, LOW); //releul va fi deschis
  else
    digitalWrite(pinReleu, HIGH); //releul va fi inchis
  delay(100);
}