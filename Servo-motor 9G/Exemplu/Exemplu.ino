#include <Servo.h>

Servo servo; //definirea variabilei servo

void setup() {
  servo.attach(7); //setarea servo-ului pe pinul D7
}

void loop() {
  for(int unghi = 1; unghi < 90; unghi ++) //parcurgerea de la 1* la 90*
  {
    servo.write(unghi); //setarea servo-ului la un unghi
    delay(100);
  }
  for(int unghi = 90; unghi > 0; unghi --) //parcurgerea de la 90* la 1*
  {
    servo.write(unghi); //setarea servo-ului la un unghi
    delay(100);
  }
}
