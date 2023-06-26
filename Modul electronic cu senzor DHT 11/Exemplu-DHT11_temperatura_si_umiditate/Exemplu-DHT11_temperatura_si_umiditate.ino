#include <DHT.h>

#define DATA_PIN 3 //pinul la care este legat, in cazul de fata D3
#define DHT_TYPE DHT11 //tipul de modul

DHT dht(DATA_PIN, DHT_TYPE); //declarare modul

void setup() {
  Serial.begin(9600);
  dht.begin(); //initializare modul
}

void loop() {
  float hum = dht.readHumidity(); //citire umiditate
  float temp = dht.readTemperature(); //citire temperatura
  //afisare date
  Serial.print("Umiditatea aerului: ");
  Serial.print(hum);
  Serial.println("%");
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" *C");
  Serial.println("-------------");
  delay(1000);
}
