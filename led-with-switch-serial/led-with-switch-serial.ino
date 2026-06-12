/*
This program shows how we can use switches to make our LED glow.
This also does a new thing -> if we press 2 or more switches at a time(which is not generally possible) then another LED should glow.
that's working :) 
*/


int pinOut = 13;    // LED 1
int pin1Out = 12;   // LED 2
int pin2Out = 11;   // LED 3
int pin3Out = 10;   // LED 4
int pin4Out = 9;    // LED 5 (for 2 switches pressed together)

int pinIn = 2;      // Switch 1
int pin1In = 3;     // Switch 2
int pin2In = 4;     // Switch 3
int pin3In = 5;     // Switch 4

void setup() {

  Serial.begin(9600);

  pinMode(pinOut, OUTPUT);
  pinMode(pin1Out, OUTPUT);
  pinMode(pin2Out, OUTPUT);
  pinMode(pin3Out, OUTPUT);
  pinMode(pin4Out, OUTPUT);

  pinMode(pinIn, INPUT);
  pinMode(pin1In, INPUT);
  pinMode(pin2In, INPUT);
  pinMode(pin3In, INPUT);
}

void loop() {

  // Read switches
  int val  = digitalRead(pinIn);
  int val1 = digitalRead(pin1In);
  int val2 = digitalRead(pin2In);
  int val3 = digitalRead(pin3In);

  // Individual LEDs
  digitalWrite(pinOut, val);
  digitalWrite(pin1Out, val1);
  digitalWrite(pin2Out, val2);
  digitalWrite(pin3Out, val3);

  // Count how many switches are pressed
  int pressedCount = val + val1 + val2 + val3;

  // If 2 or more switches pressed together -> LED 5 ON
  if (pressedCount >= 2) {
    digitalWrite(pin4Out, HIGH);
    digitalWrite(pinOut, LOW);
    digitalWrite(pin1Out, LOW);
    digitalWrite(pin2Out, LOW);
    digitalWrite(pin3Out, LOW);
    Serial.println("Two or more switches pressed -> LED 5 ON");
  }
  else {
    digitalWrite(pin4Out, LOW);

    if (val == HIGH) {
      Serial.println("LED 1 Turned ON!");
    }

    if (val1 == HIGH) {
      Serial.println("LED 2 Turned ON!");
    }

    if (val2 == HIGH) {
      Serial.println("LED 3 Turned ON!");
    }

    if (val3 == HIGH) {
      Serial.println("LED 4 Turned ON!");
    }

    if (pressedCount == 0) {
      Serial.println("Nothing Happened");
    }
  }
  delay(500);
}