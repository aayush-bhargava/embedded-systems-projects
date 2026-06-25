#include <Servo.h>

Servo myServo;

int servoPin = 9;

void setup() {

  myServo.attach(servoPin);
}

void loop() {

  // 0° to 180°
  for(int angle = 0; angle <= 180; angle++) {

    myServo.write(angle);

    delay(15);
  }

  delay(500);

  // 180° to 0°
  for(int angle = 180; angle >= 0; angle--) {

    myServo.write(angle);

    delay(15);
  }

  delay(500);
}