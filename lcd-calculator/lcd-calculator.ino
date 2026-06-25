#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

// Main operation switches
int addSwitch = 6;
int subSwitch = 7;
int mulSwitch = 8;
int divSwitch = 9;

// Control switches
int incr = 6;
int dec  = 7;
int save = 8;
int res  = 9;

int count = 0;

int x = 0;
int y = 0;

bool firstValueSaved = false;

bool lastIncr = LOW;
bool lastDec  = LOW;
bool lastSave = LOW;
bool lastRes  = LOW;

void showMenu() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("1:Add 2:Sub");

  lcd.setCursor(0, 1);
  lcd.print("3:Mul 4:Div");
}

void setup() {

  pinMode(addSwitch, INPUT);
  pinMode(subSwitch, INPUT);
  pinMode(mulSwitch, INPUT);
  pinMode(divSwitch, INPUT);

  pinMode(incr, INPUT);
  pinMode(dec, INPUT);
  pinMode(save, INPUT);
  pinMode(res, INPUT);

  lcd.begin(16, 2);

  lcd.print("LCD Calculator");

  delay(2000);

  showMenu();
}

void loop() {

  // ================= ADDITION MODE =================

  if (digitalRead(addSwitch) == HIGH) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Addition Mode");

    delay(1000);

    count = 0;

    x = 0;
    y = 0;

    firstValueSaved = false;

    while (1) {

      // Display current value
      lcd.setCursor(0, 1);
      lcd.print("                ");

      lcd.setCursor(0, 1);
      lcd.print("Value:");
      lcd.print(count);

      // ========== Increment ==========
      if (digitalRead(incr) == HIGH && lastIncr == LOW) {

        count++;
      }

      // ========== Decrement ==========
      if (digitalRead(dec) == HIGH && lastDec == LOW) {

        count--;
      }

      // ========== Save ==========
      if (digitalRead(save) == HIGH && lastSave == LOW) {

        // Save X
        if (!firstValueSaved) {

          x = count;

          lcd.clear();

          lcd.print("X Saved=");
          lcd.print(x);

          firstValueSaved = true;

          count = 0;

          delay(1000);
        }

        // Save Y
        else {

          y = count;

          lcd.clear();

          lcd.print("Y Saved=");
          lcd.print(y);

          delay(1000);
        }
      }

      // ========== Result ==========
      if (digitalRead(res) == HIGH && lastRes == LOW) {

        int result = x + y;

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Sum = ");

        lcd.print(result);

        delay(3000);

        showMenu();

        break;
      }

      // Save current states
      lastIncr = digitalRead(incr);
      lastDec  = digitalRead(dec);
      lastSave = digitalRead(save);
      lastRes  = digitalRead(res);

      delay(50);
    }
  }

  // ================= SUBTRACTION MODE =================

  if (digitalRead(subSwitch) == HIGH) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Subtraction Mode");

    delay(1000);

    count = 0;

    x = 0;
    y = 0;

    firstValueSaved = false;

    while (1) {

      // Display current value
      lcd.setCursor(0, 1);
      lcd.print("                ");

      lcd.setCursor(0, 1);
      lcd.print("Value:");
      lcd.print(count);

      // ========== Increment ==========
      if (digitalRead(incr) == HIGH && lastIncr == LOW) {

        count++;
      }

      // ========== Decrement ==========
      if (digitalRead(dec) == HIGH && lastDec == LOW) {

        count--;
      }

      // ========== Save ==========
      if (digitalRead(save) == HIGH && lastSave == LOW) {

        // Save X
        if (!firstValueSaved) {

          x = count;

          lcd.clear();

          lcd.print("X Saved=");
          lcd.print(x);

          firstValueSaved = true;

          count = 0;

          delay(1000);
        }

        // Save Y
        else {

          y = count;

          lcd.clear();

          lcd.print("Y Saved=");
          lcd.print(y);

          delay(1000);
        }
      }

      // ========== Result ==========
      if (digitalRead(res) == HIGH && lastRes == LOW) {

        int result = x - y;

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Sub = ");

        lcd.print(result);

        delay(3000);

        showMenu();

        break;
      }

      // Save current states
      lastIncr = digitalRead(incr);
      lastDec  = digitalRead(dec);
      lastSave = digitalRead(save);
      lastRes  = digitalRead(res);

      delay(50);
    }
  }

  // ================= MULTIPLICATION MODE =================

  if (digitalRead(mulSwitch) == HIGH) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Multiply Mode");

    delay(1000);

    count = 0;

    x = 0;
    y = 0;

    firstValueSaved = false;

    while (1) {

      // Display current value
      lcd.setCursor(0, 1);
      lcd.print("                ");

      lcd.setCursor(0, 1);
      lcd.print("Value:");
      lcd.print(count);

      // ========== Increment ==========
      if (digitalRead(incr) == HIGH && lastIncr == LOW) {

        count++;
      }

      // ========== Decrement ==========
      if (digitalRead(dec) == HIGH && lastDec == LOW) {

        count--;
      }

      // ========== Save ==========
      if (digitalRead(save) == HIGH && lastSave == LOW) {

        // Save X
        if (!firstValueSaved) {

          x = count;

          lcd.clear();

          lcd.print("X Saved=");
          lcd.print(x);

          firstValueSaved = true;

          count = 0;

          delay(1000);
        }

        // Save Y
        else {

          y = count;

          lcd.clear();

          lcd.print("Y Saved=");
          lcd.print(y);

          delay(1000);
        }
      }

      // ========== Result ==========
      if (digitalRead(res) == HIGH && lastRes == LOW) {

        int result = x * y;

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Result = ");

        lcd.print(result);

        delay(3000);

        showMenu();

        break;
      }

      // Save current states
      lastIncr = digitalRead(incr);
      lastDec  = digitalRead(dec);
      lastSave = digitalRead(save);
      lastRes  = digitalRead(res);

      delay(50);
    }
  }
  // ================= DIVISION MODE =================

  if (digitalRead(divSwitch) == HIGH) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Division Mode");

    delay(1000);

    count = 0;

    x = 0;
    y = 0;

    firstValueSaved = false;

    while (1) {

      // Display current value
      lcd.setCursor(0, 1);
      lcd.print("                ");

      lcd.setCursor(0, 1);
      lcd.print("Value:");
      lcd.print(count);

      // ========== Increment ==========
      if (digitalRead(incr) == HIGH && lastIncr == LOW) {

        count++;
      }

      // ========== Decrement ==========
      if (digitalRead(dec) == HIGH && lastDec == LOW) {

        count--;
      }

      // ========== Save ==========
      if (digitalRead(save) == HIGH && lastSave == LOW) {

        // Save X
        if (!firstValueSaved) {

          x = count;

          lcd.clear();

          lcd.print("X Saved=");
          lcd.print(x);

          firstValueSaved = true;

          count = 0;

          delay(1000);
        }

        // Save Y
        else {

          y = count;

          lcd.clear();

          lcd.print("Y Saved=");
          lcd.print(y);

          delay(1000);
        }
      }

      // ========== Result ==========
      if (digitalRead(res) == HIGH && lastRes == LOW) {

        int result = x / y;

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Division = ");

        lcd.print(result);

        delay(3000);

        showMenu();

        break;
      }

      // Save current states
      lastIncr = digitalRead(incr);
      lastDec  = digitalRead(dec);
      lastSave = digitalRead(save);
      lastRes  = digitalRead(res);

      delay(50);
    }
  }
}