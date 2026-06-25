#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

int mqPin = A0;
void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smoke Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  int val1 = analogRead(mqPin);
  

  if(val1 < 300) {
    lcd.setCursor(0,0);
    lcd.print("Smoke");
    lcd.setCursor(0,1);
    lcd.print("Detected");
    delay(100);
    lcd.clear();
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("NO");
    lcd.setCursor(0,1);
    lcd.print("Smoke!");
    delay(100);
    lcd.clear();
  }