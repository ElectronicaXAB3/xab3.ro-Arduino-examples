#include <SPI.h>
#include <SD.h>

void setup() {
  Serial.begin(9600);

  if(!SD.begin(4)) //initializare modul pe portul 4 (CS = 4)
  {
    Serial.println("Nu s-a putut initializa modulul.");
    while(1);
  }
  //scriere in fisier
  File file = SD.open("file.txt", FILE_WRITE); //deschidere fisier cu permisiune WRITE
  if(file) //verificare daca fisierul a putut fi deschis corect
  {
    file.println("test 123");
    file.print("1234");
    file.close();
  }
  else //daca exista erori, afisam un mesaj
    Serial.println("Eroare in timp ce se deschidea fisierul file.txt.");
  
  //citire din fisier
  file = SD.open("file.txt"); //deschidere fisier cu permisiune READ
  if(file) //verificare daca s-a deschis fisierul corect
  {
    Serial.println("file.txt: ");
    while(file.available()) //citire pana la EOF (end of file)
      Serial.write(file.read());
    file.close();
  }
  else
    Serial.println("Eroare in timp ce se deschidea fisierul file.txt.");
}

void loop() {
    //functie loop
}
