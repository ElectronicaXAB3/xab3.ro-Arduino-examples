#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc; //definirea modulului

void setup() {
  Wire.begin();
  rtc.begin(); //initializarea modulului
  Serial.begin(9600);

  //setarea datei - daca este cazul, in cazul in care anul este 2023, nu se mai seteaza data la rularea programului
  if(rtc.now().year() != 2023) 
    rtc.adjust(DateTime(2023, 6, 26, 15, 30, 0));
}

void loop() {
  DateTime now = rtc.now(); //citirea datelor din modul
  int year = now.year();
  int month = now.month();
  int day = now.day();
  int hour = now.hour();
  int min = now.minute();
  int second = now.second();

  char date[25];
  sprintf(date, "%d.%d.%d - %d:%d:%d", year, month, day, hour, min, second); //formatarea stringului "date" cu structura datei Year.Month.Day - Hour:Min:Sec
  Serial.println(date); //afisarea datei
  delay(1000);
}