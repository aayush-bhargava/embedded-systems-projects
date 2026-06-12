/*#include <EEPROM.h>
int addr = A0;

void setup() {
  pinMode(addr, INPUT);
}
void loop() {
  int val = analogRead(A0) / 4;

  EEPROM.write(addr, val);

  addr = addr + 1;
  if(addr == EEPROM.length()) {
    addr = 0;
  }
  delay(100);
}*/

/*#include <EEPROM.h>

int addr = 0;   // EEPROM address
byte value;

void setup() {

  Serial.begin(9600);

  while (!Serial) {
    // Wait for Serial Monitor
  }
}

void loop() {

  // Read EEPROM value
  value = EEPROM.read(addr);

  // Print address and value
  Serial.print(addr);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();

  // Increment address
  addr = addr + 1;

  // Reset address after maximum EEPROM size
  if (addr == EEPROM.length()) {

    addr = 0;
  }

  delay(500);
}*/


#include <EEPROM.h>

int address = 0;
int addr = A0;

int sensorValue;
int storedValue;

void setup() {

  Serial.begin(9600);

  // Read old stored value
  EEPROM.get(address, storedValue);

  Serial.print("Previously Stored Value = ");
  Serial.println(storedValue);
}

void loop() {

  // Read preset value
  sensorValue = analogRead(addr);

  // Store into EEPROM
  EEPROM.put(address, sensorValue);

  Serial.print("Current Stored Value = ");
  Serial.println(sensorValue);

  delay(2000);
}