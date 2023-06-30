#include <TM1638.h>

#define STB A0 // Strobe digital pin
#define CLK A1 // clock digital pin
#define DIO A2 // data digital pin

TM1638 tm(CLK,DIO,STB); //definire si initializare placuta

void setup() {
  tm.reset(); //resetare date anterioare
}

unsigned long number = 0; //definire variabila pentru counting

void afisare(unsigned long nr)
{
  const uint8_t digits[]={0x3F,0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //definire cifre ce vor aparea pe afisaj
  //ele inseamna in ordine 0, 1, 2, ..., 9 -- sunt convertite din binar in HEX.
  unsigned short i = 0; //variabila pentru pozitia cifrei de pe afisaj
  do
  {
    tm.displayDig(i, digits[nr%10]); //afisare cifra specifica (de la dreapta la stanga)
    i++; //urmatorul digit de pe afisaj
    nr/=10; //urmatoarea cifra
  } while(nr);
}

void loop() {
  tm.reset(); //resetare afisaj, pentru a nu ramane date in plus
  afisare(number); //OUTPUT pe afisaj
  uint8_t buttons = tm.getButtons(); //definire variabila pentru butoane.
  //valoarea lui este in binar.
  tm.writeLeds(buttons); //pornire leduri in functie de butoanele apasate
  if(buttons == 1) //daca primul este apasat, atunci var number se incrementeaza
    number ++;
  else if (buttons == 2) //daca al doilea buton este apasat, atunci var number se scade (daca numarul este pozitiv)
    if(number != 0)
      number --;
  delay(100);
}