#include <Adafruit_APDS9960.h>

#define INT 2 //pinul INT este legat la D2 in cazul de fata

Adafruit_APDS9960 apds; //definirea modulului

void setup() {
  Serial.begin(9600);
  pinMode(INT, INPUT_PULLUP); //definirea pinului INT ca input
  while(!apds.begin());
  //activarea proximitatii
  apds.enableProximity(true);
  apds.setProximityInterruptThreshold(0, 100);
  apds.enableProximityInterrupt();
}

void loop() {
  if(!digitalRead(INT)) //daca pinul INT a fost intrerupt, atunci se afiseaza valorile
  {
    Serial.println(apds.readProximity());
    apds.clearInterrupt();
  }
}
