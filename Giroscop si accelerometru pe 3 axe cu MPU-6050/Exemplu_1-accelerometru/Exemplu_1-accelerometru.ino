#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu; //definire senzor

void setup() {
  Serial.begin(9600); //initializare serial
  
  if(!mpu.begin())
  {
    Serial.println("Eroare senzor.");
    while(1)
    {
      delay(10); 
    }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G); //raza accelerometrului
  //alte variante: MPU6050_RANGE_2_G, MPU6050_RANGE_4_G, MPU6050_RANGE_8_G, MPU6050_RANGE_16_G

  mpu.setFilterBandwidth(MPU6050_BAND_5HZ); //setarea frecventei modulului
  //alte variante posibile: MPU6050_BAND_260_HZ, MPU6050_BAND_184_HZ, MPU6050_BAND_94_HZ, MPU6050_BAND_44_HZ, MPU6050_BAND_21_HZ, MPU6050_BAND_10_HZ, MPU6050_BAND_5_HZ

}

void loop() {
  sensors_event_t accel, gyro, temp; 
  mpu.getEvent(&accel, &gyro, &temp); //citirea datelor pentru accelerometru, giroscop si temperatura
  
  //afisare date pentru acceleratie pe axa xOy
  Serial.print("Acceleratie X: ");
  Serial.println(accel.acceleration.x);
  Serial.print("Acceleratie Y: ");
  Serial.println(accel.acceleration.y);
  Serial.print("Acceleratie Z: ");
  Serial.println(accel.acceleration.z);
  delay(500);
}