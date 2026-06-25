// Interrupt Programing //
// -------------------- //
// polling vs interrupt : polling executes code with manual interuptions like checking door with no bell.
//                        interrupt executes code based on interrupts like checking the door based on bell rings.
//--------------------- // 

volatile bool pressed = false;
void setup()
{
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(2),
    buttonISR,
    FALLING
  );

  Serial.println("Interrupt Test Started");
  Serial.println("Press button connected between D2 and GND");
}

void loop()
{
  if (pressed)
  {
    Serial.println("Interrupt Triggered!");
    pressed = false;
  }
}
void buttonISR()
{
  pressed = true;
}