void setup() {

  Serial.begin(9600);
}

void loop() {

  float temperature = analogRead(A0);
  float value = temperature / 2; //approximation
  //real value is 0.488!

  Serial.print("Temperature = ");
  Serial.print(value);
  Serial.println(" C");

  delay(1000);
}