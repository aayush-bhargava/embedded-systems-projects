#include <SoftwareSerial.h>

SoftwareSerial BT(0,1);

int ENA = 5;
int ENB = 6;

int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 150);
  analogWrite(ENB, 150);

  BT.begin(9600);
}

void loop()
{
  if(BT.available())
  {
    char cmd = BT.read();

    if(cmd == 'F')
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    else if(cmd == 'B')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    else if(cmd == 'L')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    else if(cmd == 'R')
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    else if(cmd == 'S')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
  }
}