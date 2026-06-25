#include <RH_ASK.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>

RH_ASK rf_driver;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Waiting...");

  rf_driver.init();
}

void loop()
{
  uint8_t buf[20];
  uint8_t buflen = sizeof(buf);

  if (rf_driver.recv(buf, &buflen))
  {
    buf[buflen] = '\0';  // Convert received bytes to string

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Text:");

    lcd.setCursor(0, 1);
    lcd.print((char*)buf);
  }
}