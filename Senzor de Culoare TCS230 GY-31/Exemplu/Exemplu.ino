//definire pini
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// variabile pentru stocarea frecventelor din photodiode
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  pinMode(S0, OUTPUT); //initializare pini
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  //Setarea frecventei la 20% (S0 = 1, S1 = 0 => 20%, S0 = S1 = 1 => 100%, S0 = 0, S1 = 1 => 2%)
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  Serial.begin(9600);
}
void loop() {
  //Setarea modulului in modul citire a culorii rosu.
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  //Citirea frecventei de rosu
  redFrequency = pulseIn(sensorOut, LOW);
  
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);
  
  //Setarea modulului in modul citire a culorii verde.
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  //Citirea frecventei de verde
  greenFrequency = pulseIn(sensorOut, LOW);
   
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);
 
  //Setarea modulului in modul citire a culorii albastru.
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
    //Citirea frecventei de albastru
  blueFrequency = pulseIn(sensorOut, LOW);
  
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  delay(100);
}