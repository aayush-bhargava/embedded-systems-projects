#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
//back light! --
//BLA-
//BLK-
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {

  // Initialize LCD
  lcd.begin(16, 2);


  // First line
  lcd.setCursor(0, 0);
  lcd.print("Hello Aayush");

  // Second line
 // lcd.setCursor(0, 1);
 // lcd.print("LCD Working :)");
}

void loop() {

  //LCD TEXT SCROLL FUNCTION
  lcd.setCursor(15, 0);
  for(int i=0; i<=15; i++) {
    lcd.scrollDisplayRight();
    delay(300);
    lcd.scrollDisplayRight();
    delay(300);
  }
  
  //LCD BLINKING PROGRAM!
 /* lcd.clear();
  delay(250);
  lcd.print("Zaza");
  delay(250);
  //----------------------------------
  lcd.noDisplay();
  delay(300);
  lcd.display();
  delay(300);*/

}