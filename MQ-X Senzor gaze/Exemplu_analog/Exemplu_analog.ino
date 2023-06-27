#define pinA A0 //pinul analogic MQ-X
#define pinBuzzer 6 //pinul buzzerului

void setup() {
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT); //definirea buzzerului
}

void loop() {
  int val = analogRead(A0); //citirea valorii analogice - de la 0 la 1023
  float voltage = val * (5.0 / 1023.0); //convertirea valorii in volti
  int ppm = 5000 * voltage; //generarea ppm
  if(ppm > 1000) //gaz detectat, ~1000 ppm
    tone(pinBuzzer, 1000); //se porneste buzzerul
  else //nu s-au detectat impuritati
    noTone(pinBuzzer); //se opreste buzzerul
  delay(100);
}
