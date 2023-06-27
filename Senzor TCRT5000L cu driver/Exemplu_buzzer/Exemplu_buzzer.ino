#define pinOUT 7 //pinul de output pentru senzor
#define buzzer 6 //pinul pentru buzzer

void setup() {
  Serial.begin(9600);
  pinMode(pinOUT, INPUT); //definirea senzorului
  pinMode(buzzer, OUTPUT); //definirea buzzerului
}

void loop() {
  int valoare = digitalRead(pinOUT); //citirea valorilor din senzor
  if(valoare) //daca valoare = 1 => un obiect este in apropiere
    tone(buzzer, 1000); //porneste buzzerul
  else //valoare = 0 => nu exista obiecte in apropiere
    noTone(buzzer, 1000); //opreste buzzerul
  delay(100);
}
