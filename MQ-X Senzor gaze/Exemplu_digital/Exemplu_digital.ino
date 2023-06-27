#define pinD 7 //pinul digital MQ-X
#define pinBuzzer 6 //pinul buzzerului
void setup() {
  Serial.begin(9600);
  pinMode(pinD, INPUT); //definirea senzorului MQ-X
  pinMode(pinBuzzer, OUTPUT); //definirea buzzerului
}

void loop() {
  int val = digitalRead(pinD); // 0 -> gaz detectat
  if(val == 0)
  {
    //gaz detectat => buzzer on
    tone(pinBuzzer, 1000); //pornesc buzzerul
  }
  else //gazul nu mai este detectat
    noTone(pinBuzzer);
  delay(100);
}
