#define pinOUT A0 //outputul va fi prin A0
  
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int value = analogRead(pinOUT);  //citirea valorii analogice de la iesire (0-1023)
  Serial.println(value); // Afisare valoare
  delay(100);
}