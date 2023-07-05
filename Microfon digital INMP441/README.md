# Microfon digital INMP441

## Descriere produs
Microfonul digita INMP441 produs de cei de la Invensense este o solutie accesibila pentru proiectede de buget in care este necesara implementarea unui microfon. Comunicarea cu aces modul se face i2s, protocol pe care il gasim disponibil pe ESP32.

## Detalii tehnice
- SN Microfon: INMP441
- Tensiune de lucru: 1.62 - 3.3V
- Consum: 1.4 mA
- ADC: 24 Bit
- Comunicare : I2S
- SNR    Raportul semnal/zgomot: 61 dBA
- Banda de frecventa: 60Hz-15kHz
- Sensibilitate: -21dBFS

## Notite
- Plotterul de la Arduino a fost modificat ca sa afiseze 1024 de sample-uri in loc de 50 de sample-uri implicit.
- Pentru ca plotterul sa randeze in timp real (aproximativ), am marit baudrate-ul de la Serial la 1,000,000.
- Sample rate-ul din exemplu a fost setat la 300, initial fiind 8000.

## Plotter
![image](https://i.imgur.com/45x0mn6.png)

## Link Resurse
- [Website](https://www.xab3.ro/produse/microfon-digital-inmp441)
- [Datasheet](Datasheet%20INMP441.pdf)
- Afisarea mai multor date in Arduino Plotter: [click aici](https://github.com/arduino/arduino-ide/issues/803#issuecomment-1552393634)
