#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define RESET -1
#define i2c_address 0x3C

#define senzorPin A0

Adafruit_SSD1306 display(RESET);

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, i2c_address);
  display.clearDisplay();
}

void printText(char* text)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(text);
  display.display();
}

void loop() {
  int val = analogRead(senzorPin);
  Serial.println(val);
  char txt[120];
  sprintf(txt, "Luminozitate: %d", val);
  printText(txt);
  delay(100);
}
