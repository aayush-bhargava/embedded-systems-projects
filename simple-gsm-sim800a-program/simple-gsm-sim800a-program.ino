//GSM Module - Global System for Mobile Communication

char mob[] = "+918290224002";

void setup()
{
  Serial.begin(9600);

  delay(5000);

  Serial.print("ATD");
  Serial.print(mob);
  Serial.println(";");

  delay(30000);

  Serial.println("ATH");
}

void loop()
{
}