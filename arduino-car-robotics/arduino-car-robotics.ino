// ==========================
// IR + ULTRASONIC ROBOT
// ==========================

// Motor Driver Pins
int ENA = 5;
int ENB = 6;

int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;

// IR Sensors
int leftIR = 2;
int rightIR = 3;

// HC-SR04
int trig = 4;
int echo = 7;

long duration;
float distance;

// Speed
int normalSpeed = 150;

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

  analogWrite(ENA, normalSpeed);
  analogWrite(ENB, normalSpeed);

  Serial.begin(9600);

  Serial.println("Robot Started");
}

void loop()
{
  // ==========================
  // HC-SR04 Reading
  // ==========================
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH, 25000);

  if (duration == 0)
  {
    distance = 400;
  }
  else
  {
    distance = duration * 0.0343 / 2;
  }

  // ==========================
  // IR Reading
  // ==========================
  int left = digitalRead(leftIR);
  int right = digitalRead(rightIR);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");

  Serial.print(" | Left: ");
  Serial.print(left);

  Serial.print(" Right: ");
  Serial.println(right);

  // ==========================
  // ULTRASONIC PRIORITY
  // ==========================
  if (distance <= 10)
  {
    Serial.println("FRONT OBSTACLE");

    stopp();
    delay(200);

    backward();
    delay(1500);

    stopp();
    delay(200);

    moveLeft();
    delay(400); 

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
    Serial.println("RIGHT OBSTACLE");

    stopp();
    delay(200);

    backward();
    delay(1000);

    stopp();
    delay(200);

    moveLeft();
    delay(400);

    stopp();
    delay(100);
  }

  // ==========================
  // Left Obstacle
  // ==========================
  else if (left == 1 && right == 0)
  {
    Serial.println("LEFT OBSTACLE");

    stopp();
    delay(200);

    backward();
    delay(1000);

    stopp();
    delay(200);

    moveRight();
    delay(400);

    stopp();
    delay(100);
  }

  // ==========================
  // Both Obstacles
  // ==========================
  else if (left == 1 && right == 1)
  {
    Serial.println("BOTH OBSTACLES");

    stopp();
    delay(200);

    backward();
    delay(1500);

    stopp();
    delay(200);

    moveLeft();
    delay(400); 

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