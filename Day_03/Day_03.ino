// Obstacle avoidance using IR sensor
int irSensor = 8;
int motor1 = 10;
int motor2 = 11;
int motor3 = 12;
int motor4 = 13;

void setup()
{
  pinMode(irSensor, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}

void loop()
{
  int reading = digitalRead(irSensor);

  if (reading == HIGH)
  { // No obstacle, path clear

    // move forward
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    delay(200);
  }
  else {
    // obstacle detected

    // stop
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    delay(200);
    
    // turn
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    delay(200);
  }
}
