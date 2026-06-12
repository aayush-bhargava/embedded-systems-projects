int ldrPin = A0;     // LDR connected to A0
int ledPin = 13;     // LED pin

void setup() {

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  Serial.print("LDR Value = ");
  Serial.println(ldrValue);

  // Dark condition
  if (ldrValue < 500) {

    digitalWrite(ledPin, HIGH);
  }

  // Bright condition
  else {

    digitalWrite(ledPin, LOW);
  }

  delay(200);
}