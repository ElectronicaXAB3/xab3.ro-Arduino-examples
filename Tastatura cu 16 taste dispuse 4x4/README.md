# Tastatura cu 16 taste dispuse 4x4 si Modul Display cu 7 segmente 2x4 digit

## Descriere produs
Tastatura 16 taste | Display 7 segmente
--- | ---
Tastatura cu 16 taste (cifrele de la 0 la 9, A, B, C, D, steluta si diez). Tastele sunt conectate in forma matriceala 4x4. Tastatura este echipata cu un cablu de tip DIP mama cu pas de 2.54mm cu lungimea de 5cm, iar pe spate este cu autoadeziv, ceea ce implica o usoara fixare pe carcase sau panouri. | Circuitul integrat MAX7219 este unul dintre cele mai uzuale drivere pentr afisaje led. Pentru comunicarea cu acesta sunt necesare doar 4 fire, iar spre deosebire de alte circuite acesta ne permite accesarea individuala a fiecarui digit fara a fi nevoiti sa rescriem intreg afisajul.

## Detalii tehnice

### Tastatura 16 taste
- Taste: 16
- Dispunere taste: 4x4
- Conector 	DIP mama cu pas: 2.54mm
- Lungime cablu: 5cm
- Fixare: autoadeziv

### Display 7 segmente
- Viteza de comunicare: 10Mhz
- Accesare digit: Posibilitate apelare individuala/digit fara rescriea totala a continutului
- Consum at 5V: 300mA (toate segmentele ON) suporta pana la 500mA
- Luminozitate: Reglabila cu rezistor at Pin 18 ISET
- Drive Common: Cathode LED
- Comunicare: SPI
- Tensiune de operare: 3.3V-6V

## Link Resurse
Tastatura 16 taste | Display 7 segmente
--- | ---
[Website](https://www.xab3.ro/produse/tastatura-4x4) | [Website](https://www.xab3.ro/produse/modul-display-cu-7-segmente-2x4-digit)
[Datasheet](Datasheet%20Keyboard.pdf) | [Datasheet](Datasheet%20MAX7219.pdf)
[Keypad.h](https://github.com/Chris--A/Keypad) | [LedControl.h](https://github.com/wayoda/LedControl)