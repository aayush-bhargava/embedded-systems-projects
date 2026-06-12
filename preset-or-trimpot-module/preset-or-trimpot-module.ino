int preset = A0;
void setup() {

  Serial.begin(9600);
}

void loop() {

  int value = analogRead(preset);

  Serial.print("Preset Value = ");
  Serial.println(value);

  delay(200);
}