// Obstacle avoidance + moving head
#include <Servo.h>

Servo motor;
int servoPin = 6;
int irSensor = 9;
int motor1 = 1;
int motor2 = 2;
int motor3 = 3;
int motor4 = 4;

void setup()
{
  pinMode(irSensor, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  motor.attach(servoPin);
  motor.write(90);
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
    delay(500);
  }
  else
  { // obstacle detected

    // stop
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    delay(1000);

    // move head
    motor.write(0);
    delay(500);
    motor.write(180);
    delay(500);
    motor.write(90);
    delay(500);

    // go back
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    delay(1000);

    // turn
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    delay(1000);
  }
}
