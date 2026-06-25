const int touchPin = 8;
const int ledPin = 12;

bool ledState = false;
bool lastTouchState = LOW;

void setup() {

  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  bool currentTouch = digitalRead(touchPin);

  // Detect touch event
  if (currentTouch == HIGH && lastTouchState == LOW) {

    ledState = !ledState;

    digitalWrite(ledPin, ledState);

    Serial.print("LED State: ");
    Serial.println(ledState ? "ON" : "OFF");

    delay(200); // debounce
  }

  lastTouchState = currentTouch;
}