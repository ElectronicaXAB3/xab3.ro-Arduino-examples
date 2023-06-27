#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define i2c_address 0x3C //adresa de la i2c OLED Display
#define OLED_RESET -1 //butonul de reset pentru OLED, -1 daca nu e cazul
#define OLED_WIDTH 128 //dimensiunea OLED-ului, in cazul de fata e 128x64
#define OLED_HEIGHT 64

const int trigPin = 9; //trigger Pin pentru HC-SR04
const int echoPin = 10; //echo Pin pentru HC-SR04

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET); //initializare OLED

void setup() {
  pinMode(trigPin, OUTPUT); //definire trigPin
  pinMode(echoPin, INPUT); //definire echoPin
  Serial.begin(9600);

  while(!display.begin(SSD1306_SWITCHCAPVCC, i2c_address));
  display.display();
}

float getDistance() //functie pentru determinarea distantei
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH); //duratia pentru unda sonora de la senzor la un obiect si inapoi
  float distance = (duration * 0.0343) / 2; //determinarea distantei folosind relatia distanta = (durata * viteza_sunet) / 2
  return distance; //returneaza distanta dintre senzor si obiect
}

void loop() {
  //Serial.println(getDistance());
  display.clearDisplay(); //sterge tot textul de pe OLED
  display.setTextSize(1); //seteaza dimensiunea textului la 1
  display.setTextColor(WHITE); //seteaza culoarea textului
  display.setCursor(0, 0); //seteaza punctul de inceput la (0,0)
  char text[64];
  float distance = getDistance(); //determinarea distantei
  sprintf(text, "Distanta: %d cm", (int)distance); //formatarea textului cu distanta
  Serial.println(text);
  display.println(text); //scrierea textului pe OLED
  display.display(); //afisarea textului pregatit
  delay(1000);
}
