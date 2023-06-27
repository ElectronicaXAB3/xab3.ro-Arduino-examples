#define pinOUT 7 //definirea pinului de output

void setup() {
  Serial.begin(9600);
  pinMode(pinOUT, INPUT); //definirea pinului ce primeste input de la senzor
}

void loop() {
  int stare = digitalRead(pinOUT); //citirea valorii oferite de senzor 0 = fara miscare, 1 = miscare
  Serial.println(stare); //afisarea valorii citite
  delay(10);
}
