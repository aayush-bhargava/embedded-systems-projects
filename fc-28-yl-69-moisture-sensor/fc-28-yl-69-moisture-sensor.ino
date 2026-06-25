//This is the code for soil sensor / moisture sensor
//--------------------------------------------------------
//Metallic probe is named as YL-69
//Controller or IC for this sensor is named as FC-28.
//--------------------------------------------------------
//This is the sample program for tanki wala alarm.
int pin = A0;
int buzz = 4;

void setup()
{
  pinMode(buzz, OUTPUT);
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(MOISTURE_PIN);

  Serial.print("Moisture Value: ");
  Serial.println(val);

  // Adjust threshold after testing
  if (val < 600)
  {
    digitalWrite(BUZZER_PIN, HIGH); // Buzzer ON
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW); // Buzzer OFF
  }

  delay(500);
}