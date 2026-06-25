#include <RH_ASK.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>

// RX on D11
RH_ASK rf_driver(2000, 11, 12);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  // Startup Screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Car Starting!");

  lcd.setCursor(0, 1);
  lcd.print("Let's GO!");

  delay(2000);

  lcd.clear();

  if (rf_driver.init())
  {
    Serial.println("RX OK");

    lcd.setCursor(0, 0);
    lcd.print("Waiting Data");
  }
  else
  {
    Serial.println("RX FAIL");

    lcd.setCursor(0, 0);
    lcd.print("RF Init Fail");
  }
}

void loop()
{
  uint8_t buf[60];
  uint8_t buflen = sizeof(buf);

  if (rf_driver.recv(buf, &buflen))
  {
    buf[buflen] = '\0';

    String data = String((char*)buf);

    Serial.print("RX -> ");
    Serial.println(data);

    lcd.clear();

    // First line
    lcd.setCursor(0, 0);
    lcd.print(data.substring(0, 16));

    // Second line
    if (data.length() > 16)
    {
      lcd.setCursor(0, 1);
      lcd.print(data.substring(16, 32));
    }
  }
}