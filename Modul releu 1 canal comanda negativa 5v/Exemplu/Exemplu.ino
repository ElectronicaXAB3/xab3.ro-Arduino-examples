#define PIN 3 //pinul de input pentru releu setat pe D3

void setup() {
  pinMode(PIN, OUTPUT); //setarea pinului PIN drept OUTPUT
}

void loop() {
  digitalWrite(PIN, HIGH); //seteaza releul pe OFF
  delay(1000);
  digitalWrite(PIN, LOW); //seteaza releul pe ON
  delay(1000);
}
