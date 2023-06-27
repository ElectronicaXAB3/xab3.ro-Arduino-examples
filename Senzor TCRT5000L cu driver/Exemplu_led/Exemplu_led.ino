#define pinOUT 7 //pinul de output pentru senzor
#define led 6 //pinul pentru led

void setup() {
  Serial.begin(9600);
  pinMode(pinOUT, INPUT); //definirea senzorului
  pinMode(led, OUTPUT); //definirea ledului
}

void loop() {
  int valoare = digitalRead(pinOUT); //citirea valorilor din senzor
  if(valoare) //daca valoare = 1 => un obiect este in apropiere
    digitalWrite(led, HIGH); //porneste ledul
  else //valoare = 0 => nu exista obiecte in apropiere
    digitalWrite(led, LOW); //opreste ledul
  delay(100);
}
