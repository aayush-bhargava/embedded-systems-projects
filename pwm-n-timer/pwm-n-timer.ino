#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

int pwmPin = 9;

void setup() {

  pinMode(pwmPin, OUTPUT);

  lcd.begin(16, 2);

  lcd.setCursor(0,0);
  lcd.print("PWM Voltage");

  delay(2000);

  lcd.clear();
}

void loop() {

  // Increasing voltage
  for(int pwm = 0; pwm <= 255; pwm++) {

    analogWrite(pwmPin, pwm);

    float voltage = (pwm / 255.0) * 5.0;

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Voltage =");

    lcd.setCursor(0,1);
    lcd.print(voltage, 2);
    lcd.print(" V");

    delay(100);
  }

  // Decreasing voltage
  for(int pwm = 255; pwm >= 0; pwm--) {

    analogWrite(pwmPin, pwm);

    float voltage = (pwm / 255.0) * 5.0;

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Voltage =");

    lcd.setCursor(0,1);
    lcd.print(voltage, 2);
    lcd.print(" V");

    delay(100);
  }
}