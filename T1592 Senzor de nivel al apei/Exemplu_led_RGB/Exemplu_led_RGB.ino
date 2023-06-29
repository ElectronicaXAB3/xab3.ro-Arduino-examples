#define PIN A0 //pinul de output al senzorului A0
#define R 2 //pinul RED D2
#define G 3 //pinul GREEN D3
//BLUE poate fi ignorat (Daca se foloseste un singur led RGB)

void setup() {
  Serial.begin(9600); //initializare serial
  pinMode(R, OUTPUT); //initializare pini
  pinMode(G, OUTPUT);
}

void loop() {
  //500 = 100% => x% = valoare * 100 / 500
  //500 este valoarea maxima (testata in cazul de fata), chiar daca valoarea analogica poate fi intre 0-1023
  unsigned int value = (int)(analogRead(PIN) * 100 / 500); //citirea valorii analogice si convertirea in procente
  if(value > 75) //daca value > 75 => RED
  {
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
  }
  else if(value > 50) //daca value > 50 && value < 75 => YELLOW (RED + GREEN)
  {
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
  }
  else //altfel => GREEN
  {
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
  }
  delay(100);
}
