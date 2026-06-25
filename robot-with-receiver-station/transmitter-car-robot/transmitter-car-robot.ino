#include <RH_ASK.h>
#include <SPI.h>
#include <DHT.h>

// ==========================
// DHT11
// ==========================
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ==========================
// RF TX on D8
// ==========================
RH_ASK rf_driver(2000, 0, A0);

// ==========================
// Motor Driver Pins
// ==========================
int ENA = 5;
int ENB = 6;

int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;

// ==========================
// IR Sensors
// ==========================
int leftIR = 2;
int rightIR = 3;

// ==========================
// HC-SR04
// ==========================
int trig = 4;
int echo = 7;

long duration;
float distance;

// ==========================
// Timing
// ==========================
unsigned long lastDHTRead = 0;
unsigned long lastSend = 0;

// Cached DHT values
int temperature = 0;
int humidity = 0;

void setup()
{
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 108);
  analogWrite(ENB, 108);

  Serial.begin(9600);

  dht.begin();

  if (!rf_driver.init())
  {
    Serial.println("RF Init Failed");
  }
  else
  {
    Serial.println("RF Init OK");
  }

  Serial.println("Robot Started");
}

void loop()
{
  // ==========================
  // Ultrasonic
  // ==========================
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  // FIXED: Reduced timeout
  duration = pulseIn(echo, HIGH, 10000);

  if (duration == 0)
  {
    distance = 400;
  }
  else
  {
    distance = duration * 0.0343 / 2;
  }

  // ==========================
  // IR Read
  // ==========================
  int left = digitalRead(leftIR);
  int right = digitalRead(rightIR);

  // ==========================
  // DHT Read Every 5 Seconds
  // ==========================
  if (millis() - lastDHTRead >= 5000)
  {
    lastDHTRead = millis();

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t) && !isnan(h))
    {
      temperature = (int)t;
      humidity = (int)h;
    }
  }

  // ==========================
  // RF Send Every 2 Seconds
  // ==========================
  if (millis() - lastSend >= 2000)
  {
    lastSend = millis();

    char msg[50];

    sprintf(msg,
            "D:%d L:%d R:%d T:%d H:%d",
            (int)distance,
            left,
            right,
            temperature,
            humidity);

    rf_driver.send((uint8_t *)msg, strlen(msg));
    // rf_driver.waitPacketSent();

    Serial.println(msg);
  }

  // ==========================
  // HC-SR04 Priority
  // ==========================
  if (distance <= 10)
  {
    stopp();
    delay(200);

    backward();
    delay(1500);

    stopp();
    delay(200);

    moveLeft();
    delay(600);

    stopp();
    delay(100);

    return;
  }

  // ==========================
  // No Obstacle
  // ==========================
  if (left == 0 && right == 0)
  {
    forward();
  }

  // ==========================
  // Right Obstacle
  // ==========================
  else if (left == 0 && right == 1)
  {
    stopp();
    delay(200);

    backward();
    delay(1000);

    stopp();
    delay(200);

    moveLeft();
    delay(600);

    stopp();
    delay(100);
  }

  // ==========================
  // Left Obstacle
  // ==========================
  else if (left == 1 && right == 0)
  {
    stopp();
    delay(200);

    backward();
    delay(1000);

    stopp();
    delay(200);

    moveRight();
    delay(600);

    stopp();
    delay(100);
  }

  // ==========================
  // Both Obstacles
  // ==========================
  else if (left == 1 && right == 1)
  {
    stopp();
    delay(200);

    backward();
    delay(1500);

    stopp();
    delay(200);

    moveLeft();
    delay(600);

    stopp();
    delay(100);
  }
}

// ==========================
// Motor Functions
// ==========================

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveLeft()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveRight()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopp()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}