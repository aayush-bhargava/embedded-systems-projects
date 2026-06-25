#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

int trigPin = 8;
int echoPin = 9;

long duration;
float distance;

void setup() {

  lcd.begin(16, 2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.clear();
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  // Clear previous text
  lcd.clear();

  // Print on single line
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");

  lcd.print(distance);

  //lcd.print(" cm");

  delay(500);
}







/*int pir = 8;

void setup() {

  pinMode(pir, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {

  int val = digitalRead(pir);
  lcd.clear();
  if (val == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("MOTION");
    lcd.setCursor(0, 1);
    lcd.print("DETECTED");
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("NO MOTION");
  }
  delay(500);
}*/