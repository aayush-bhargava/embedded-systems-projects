#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {

  Serial.begin(9600);

  if (!mpu.begin()) {
    Serial.println("MPU6050 Not Found!");
    while (1);
  }

  Serial.println("MPU6050 Ready!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void loop() {

  sensors_event_t a, g, temp;

  mpu.getEvent(&a, &g, &temp);

  Serial.print("Acc X: ");
  Serial.print(a.acceleration.x);

  Serial.print("  Y: ");
  Serial.print(a.acceleration.y);

  Serial.print("  Z: ");
  Serial.println(a.acceleration.z);

  Serial.print("Gyro X: ");
  Serial.print(g.gyro.x);

  Serial.print("  Y: ");
  Serial.print(g.gyro.y);

  Serial.print("  Z: ");
  Serial.println(g.gyro.z);

  Serial.print("Temp: ");
  Serial.print(temp.temperature);
  Serial.println(" C");

  Serial.println("--------------------");

  delay(1000);
}