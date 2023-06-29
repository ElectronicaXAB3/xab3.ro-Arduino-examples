#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define i2c_address 0x3C //adresa de la i2c OLED Display
#define OLED_RESET -1 //butonul de reset pentru OLED, -1 daca nu e cazul
#define OLED_WIDTH 64 //dimensiunea OLED-ului, in cazul de fata e 64x48
#define OLED_HEIGHT 48

const int trigPin = 9; //trigger Pin pentru senzor
const int echoPin = 10; //echo Pin pentru senzor

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET); //initializare OLED

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLUP);
  while(!display.begin(SSD1306_SWITCHCAPVCC, i2c_address));
  display.display();
}

int distance()
{
digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH); //duratia pentru unda sonora de la senzor la un obiect si inapoi
  float distance = (duration * 0.0343) / 2; //determinarea distantei folosind relatia distanta = (durata * viteza_sunet) / 2
  //viteza sunetului in aer este 0.0343, iar pentru apa e ~0.15
  return (int)distance; //returneaza distanta dintre senzor si obiect
}

void loop() {
  display.clearDisplay(); //sterge tot textul de pe OLED
  display.setTextSize(1); //seteaza dimensiunea textului la 1
  display.setTextColor(WHITE); //seteaza culoarea textului
  display.setCursor(0, 0); //seteaza punctul de inceput la (0,0)
  display.print("--------------->>"); //scrierea textului pe OLED
  display.println(distance());
  display.display(); //afisarea textului pregatit
  delay(100);
}
