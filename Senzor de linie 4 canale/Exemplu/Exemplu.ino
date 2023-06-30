#define pin1 2
#define pin2 3
#define pin3 4
#define pin4 5 //declarare pini de output

void setup() {
  Serial.begin(9600);
  pinMode(pin1, INPUT); //definire pini de output ca INPUT (citirea se face prin acesti pini)
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
}

void loop() {
  Serial.println((String)"Linie 1: " + digitalRead(pin1)); //afisarea valorii citite de pe pin1
  Serial.println((String)"Linie 2: " + digitalRead(pin2)); //afisarea valorii citite de pe pin2
  Serial.println((String)"Linie 3: " + digitalRead(pin3)); //afisarea valorii citite de pe pin3
  Serial.println((String)"Linie 4: " + digitalRead(pin4)); //afisarea valorii citite de pe pin4
  //0 - detectat, 1 - nedetectat
  delay(100);
}
