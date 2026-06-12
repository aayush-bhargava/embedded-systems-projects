/*This is a program where switches are used as a calculator.
in short : 
switch 1 counts the number of presses a user makes and increment on every press.
switch 2 will decrement on every press.
now switch 3 will display output on a led where it will blink the led the exact number of times a user pressed switch 1/2*/

int pinOut  = 13;
int pin1Out = 12;
int pin2Out = 11;
int pin3Out = 10;
int pinIn  = 2;
int pin1In = 3;
int pin2In = 4;
int pin3In = 5;

// Counters
int count0 = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;

// Boolean variables for previous states
bool lastButton0 = LOW;
bool lastButton1 = LOW;
bool lastButton2 = LOW;
bool lastButton3 = LOW;

void setup() {

  Serial.begin(9600);

  pinMode(pinOut, OUTPUT);
  pinMode(pin1Out, OUTPUT);
  pinMode(pin2Out, OUTPUT);
  pinMode(pin3Out, OUTPUT);

  pinMode(pinIn, INPUT);
  pinMode(pin1In, INPUT);
  pinMode(pin2In, INPUT);
  pinMode(pin3In, INPUT);
}

// Function to blink LED
void blinkLED(int ledPin, int times) {

  for (int i = 0; i < times; i++) {

    digitalWrite(ledPin, HIGH);
    delay(100);

    digitalWrite(ledPin, LOW);
    delay(100);
  }
}

void loop() {

  // Read buttons
  bool button0 = digitalRead(pinIn);
  bool button1 = digitalRead(pin1In);
  bool button2 = digitalRead(pin2In);
  bool button3 = digitalRead(pin3In);

  // ================= SWITCH 1 =================
  // Count ONLY when button is PRESSED

  if (button0 == HIGH && lastButton0 == LOW) {

    count0++;

    Serial.print("Switch 1 Press Count = ");
    Serial.println(count0);

   // blinkLED(pinOut, count0);
  }

  // ================= SWITCH 2 =================

  if (button1 == HIGH && lastButton1 == LOW) {

    count1++;

    Serial.print("Switch 2 Press Count = ");
    Serial.println(count1);

   // blinkLED(pin1Out, count1);
  }

  // ================= SWITCH 3 =================

   if (button2 == HIGH && lastButton2 == LOW) {
    blinkLED(pinOut, count0);
  }

  // Save current state as previous state
  lastButton0 = button0;
  lastButton1 = button1;
  lastButton2 = button2;
 // lastButton3 = button3;

  // Small debounce delay
  delay(100);
}