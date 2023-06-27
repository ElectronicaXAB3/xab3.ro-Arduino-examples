#define pinOUT 7 //pinul de output al senzorului
#define pinLED 6 //pinul ledului

void setup() {
  Serial.begin(9600);
  pinMode(pinOUT, INPUT); //definirea pinului ce primeste input de la senzor
  pinMode(pinLED, OUTPUT); //definirea pinului pentru led
}

void loop() {
  int stare = digitalRead(pinOUT); //citirea valorii oferite de senzor 0 = fara miscare, 1 = miscare
  if(stare == 1) //verificare daca exista miscari
    digitalWrite(pinLED, HIGH); //ledul se aprinde
  else
    digitalWrite(pinLED, LOW); //ledul se opreste
  delay(10);
}
