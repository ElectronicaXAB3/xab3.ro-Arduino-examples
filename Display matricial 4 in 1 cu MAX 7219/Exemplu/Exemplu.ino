#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//tipuri de hardware: FC16_HW, GENERIC_HW
#define MAX_DEVICES 4 //numarul de matrici
#define CS_PIN 3 //pinul CS este legat la D3
//DIN se leaga la D11, iar CLK la D13

MD_Parola display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES); //definire modul

void setup() {
  display.begin(); //initializare
  display.setIntensity(0); //setare intensitate de la 0 la 15
  display.displayClear();
}

void loop() {
  
  display.setTextAlignment(PA_CENTER); //setare aliniere text la centru
  //alte variante: PA_LEFT, PA_CENTER
  display.print("xab3ro"); //afisare un mesaj
  delay(100);
}
