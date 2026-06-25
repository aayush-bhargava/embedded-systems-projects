int pin = 13;
int sound = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(sound, INPUT);
  // put your setup code here, to run once:
}
void loop() {
  int val = digitalRead(sound);

  if(val == HIGH) {
    digitalWrite(pin, HIGH);
    Serial.println("SOUND DETECTED!");
    delay(250);
  }
  else{
    digitalWrite(pin, LOW);
    Serial.println("LOW SOUND!");
    delay(250);
  }
}