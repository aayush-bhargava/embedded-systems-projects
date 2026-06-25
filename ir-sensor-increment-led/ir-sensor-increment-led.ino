/*This program connects the IR sensor to a led where we can count the number of times an object is detected and exact number of times the led will blink.*/


int irSensor = 2;    // IR Sensor OUT pin
int ledPin = 13;     // LED pin

bool currentState = LOW;
bool lastState = LOW;

int objectCount = 0;

void setup() {

  Serial.begin(9600);

  pinMode(irSensor, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // Read IR sensor
  currentState = digitalRead(irSensor);

  // Detect object
  if (currentState == HIGH && lastState == LOW) {

    objectCount++;

    Serial.print("Object Detected Count = ");
    Serial.println(objectCount);

    // LED ON
    digitalWrite(ledPin, HIGH);
    delay(100);

    // LED OFF
    digitalWrite(ledPin, LOW);
  }

  // Save previous state
  lastState = currentState;

  delay(50);
}