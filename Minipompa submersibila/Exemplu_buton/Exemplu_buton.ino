#define buttonPin 2 //pin pentru buton
#define pompaPin 3 //pinul de la releu ce este conectat la pompa sau alte module de OUTPUT

void setup() {
  //definire pini
  pinMode(buttonPin, INPUT);
  pinMode(pompaPin, OUTPUT);
}

int lastState = 0; //variabila pentru a vedea starea anterioara apasarii butonului

void loop() {
  int state = digitalRead(buttonPin); //variabila ce citeste starea butonului (1 = apasat, 0 = nu este apasat)
  if(state == 1 && state != lastState) //daca butonul este apasat, dar 
    digitalWrite(pompaPin, !digitalRead(pompaPin));
  lastState = state;
  delay(100);
}
