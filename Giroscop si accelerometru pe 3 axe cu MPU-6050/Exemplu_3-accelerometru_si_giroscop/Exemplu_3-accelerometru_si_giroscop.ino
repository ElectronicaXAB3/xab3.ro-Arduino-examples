#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu; //definire modul

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

  mpu.setGyroRange(MPU6050_RANGE_500_DEG); //raza giroscopului
  //alte variante: MPU6050_RANGE_250_DEG, MPU6050_RANGE_500_DEG, MPU6050_RANGE_1000_DEG, MPU6050_RANGE_2000_DEG

  mpu.setFilterBandwidth(MPU6050_BAND_260_HZ); //setarea frecventei modulului
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
  Serial.print("Acceleratie m/s^2: ");
  Serial.println(accel.acceleration.z);

  Serial.println("-----------");

  //afisare date pentru giroscop pe axa xyz
  Serial.print("Rotatie X: ");
  Serial.println(gyro.gyro.x);
  Serial.print("Rotatie Y: ");
  Serial.println(gyro.gyro.y);
  Serial.print("Rotatie Z: ");
  Serial.println(gyro.gyro.z);

  //afisare date pentru temperatura
  Serial.print("Temperatura: ");
  Serial.print(temp.temperature);
  Serial.println(" *C");
  delay(500);
}