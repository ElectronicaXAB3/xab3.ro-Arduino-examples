#define PIN A0 //pinul de output al senzorului A0

void setup() {
  Serial.begin(9600); //initializare serial
}

void loop() {
  //500 = 100% => x% = valoare * 100 / 500
  //500 este valoarea maxima (testata in cazul de fata), chiar daca valoarea analogica poate fi intre 0-1023
  unsigned int value = (int)(analogRead(PIN) * 100 / 500); //citirea valorii analogice si convertirea in procente
  Serial.print("Nivelul apei: ");
  Serial.println(value);
  delay(100);
}
