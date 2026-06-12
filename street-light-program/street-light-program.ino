int pin = 10;
int led = 12;
int sensor = A0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pin, OUTPUT);
  pinMode(sensor, INPUT);
  // put your setup code here, to run once:
}

void loop() {
  int val = analogRead(sensor);
  if(val < 500){ //Light Conditions
    digitalWrite(pin, HIGH);
    digitalWrite(led, HIGH);
    Serial.print("D LDR VALUE : ");
    Serial.println(val);
  }
  else { //dark conditions
    digitalWrite(pin, LOW);
    digitalWrite(led, LOW);
    Serial.print("L LDR VALUE : ");
    Serial.println(val);
  }
  delay(200);

}
