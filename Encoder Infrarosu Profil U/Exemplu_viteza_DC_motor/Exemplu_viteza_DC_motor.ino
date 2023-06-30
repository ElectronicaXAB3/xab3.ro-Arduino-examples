#define pinIR 2 //definire pin OUT pentru encoder

volatile int pulseCount = 0; //variabila in care va fi stocat numarul de pulsatii
unsigned long previousMillis = 0; //variabila in care va fi stocat timpul anterior in milisecunde
const unsigned long interval = 1000; //intervalul in milisecunde

void setup() {
  Serial.begin(9600);
  pinMode(pinIR, INPUT_PULLUP); //definire pin ca INPUT
  attachInterrupt(digitalPinToInterrupt(pinIR), countPulses, FALLING); //Atasare Interrupt la pinIR cu functia countPulses()
}

void loop() {
  unsigned long currentMillis = millis(); //timpul curent
  if(currentMillis-previousMillis >= interval)
  {
    detachInterrupt(digitalPinToInterrupt(pinIR)); //deatasare Interrupt de la pinIR
    float velocity = calculateVelocity(); //calcularea vitezei
    Serial.println((String)"Viteza: " + velocity + " RPM"); //afisare date
    pulseCount = 0; //resetare contor pulsuri
    previousMillis = currentMillis;
    attachInterrupt(digitalPinToInterrupt(pinIR), countPulses, FALLING); //reatasare Interrupt la pinIR cu functia countPulses()
  }
}

void countPulses() //functie pentru numararea pulsatiilor
{
  pulseCount++;
}

float calculateVelocity()
{
  const int pulseCountPerRevolution = 20; //se modifica in functie de motor, important de calibrat
  float timeInSeconds = interval / 1000.0; //transformare ms in s
  float velocity = (pulseCount * 60.0 / pulseCountPerRevolution) / timeInSeconds; //formula pt viteza in rotatii pe minut RPM
  return velocity;
}
