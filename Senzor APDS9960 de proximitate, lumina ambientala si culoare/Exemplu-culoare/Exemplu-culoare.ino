#include <Adafruit_APDS9960.h>

#define INT 2 //pinul INT este legat la D2 in cazul de fata

Adafruit_APDS9960 apds; //definirea modulului

void setup() {
  Serial.begin(9600);
  pinMode(INT, INPUT_PULLUP); //definirea pinului INT ca input
  while(!apds.begin());
  //activarea senzorului de culoare
  apds.enableColor(true);
}

void loop() {
  uint16_t r, g, b, c; //rgb - red green blue, c - clear
  while(!apds.colorDataReady())
    delay(5);
  apds.getColorData(&r, &g, &b, &c); //citirea culorilor sub forma RGB
  char color[50];
  sprintf(color, "R: %d G: %d B: %d clear: %d", r, g, b, c); //formatarea textului de afisare
  Serial.println(color);
  delay(1000);
}
