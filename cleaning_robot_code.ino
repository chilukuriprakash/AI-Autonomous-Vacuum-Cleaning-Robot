
#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>
#include <SoftwareSerial.h>

// ================= PIN CONFIGURATION =================

// Ultrasonic sensor
#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200
#define OBSTACLE_DISTANCE 15

// Bluetooth: RX first, TX second
SoftwareSerial BT(A2, A3);

// ================= MOTOR CONFIGURATION =================

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// Sensors
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;

// ================= VARIABLES =================

int motorSpeed = 180;
int distance = 200;
int distanceLeft = 0;
int distanceRight = 0;

bool automaticMode = false;
char command = 'S';

// ================= SETUP =================

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  myservo.attach(10);
  myservo.write(115);

  setMotorSpeed(motorSpeed);
  stopMotors();

  delay(500);

  distance = readPing();

  BT.println("Cleaning Robot Ready");
  BT.println("F=Forward B=Backward");
  BT.println("L=Left R=Right S=Stop");
  BT.println("A=Auto M=Manual");
  Serial.println("Bluetooth Cleaning Robot Ready");
}

// ================= MAIN LOOP =================

void loop() {

  // Receive Bluetooth commands
  while (BT.available() > 0) {
    char received = BT.read();

    // Convert lowercase to uppercase
    if (received >= 'a' && received <= 'z') {
      received = received - 32;
    }

    switch (received) {

      case 'F':
      case 'B':
      case 'L':
      case 'R':
      case 'S':
        automaticMode = false;
        command = received;
        break;

      case 'A':
        automaticMode = true;
        command = 'S';
        stopMotors();
        myservo.write(115);
        BT.println("Automatic Mode ON");
        break;

      case 'M':
        automaticMode = false;
        command = 'S';
        stopMotors();
        myservo.write(115);
        BT.println("Manual Mode ON");
        break;
    }
  }

  // Run selected mode
  if (automaticMode) {
    automaticDrive();
  } else {
    manualDrive();
  }
}

// ================= MANUAL BLUETOOTH CONTROL =================

void manualDrive() {

  switch (command) {

    case 'F':
      moveForward();
      break;

    case 'B':
      moveBackward();
      break;

    case 'L':
      turnLeft();
      break;

    case 'R':
      turnRight();
      break;

    case 'S':
    default:
      stopMotors();
      break;
  }
}

// ================= AUTOMATIC MODE =================

void automaticDrive() {

  distance = readPing();

  if (distance > OBSTACLE_DISTANCE) {
    moveForward();
  } else {

    stopMotors();
    delay(150);

    moveBackward();
    delay(300);

    stopMotors();
    delay(150);

    distanceRight = lookRight();
    delay(100);

    distanceLeft = lookLeft();
    delay(100);

    myservo.write(115);
    delay(150);

    if (distanceRight >= distanceLeft) {
      turnRight();
      delay(400);
    } else {
      turnLeft();
      delay(400);
    }

    stopMotors();
    delay(100);
  }
}

// ================= ULTRASONIC SENSOR =================

int readPing() {
  delay(40);

  unsigned int cm = sonar.ping_cm();

  // No echo means no obstacle detected within range
  if (cm == 0) {
    return MAX_DISTANCE;
  }

  return cm;
}

int lookRight() {
  myservo.write(50);
  delay(500);

  int d = readPing();

  myservo.write(115);
  delay(150);

  return d;
}

int lookLeft() {
  myservo.write(170);
  delay(500);

  int d = readPing();

  myservo.write(115);
  delay(150);

  return d;
}

// ================= MOTOR SPEED =================

void setMotorSpeed(int speedValue) {
  motor1.setSpeed(speedValue);
  motor2.setSpeed(speedValue);
  motor3.setSpeed(speedValue);
  motor4.setSpeed(speedValue);
}

// ================= MOTOR MOVEMENTS =================

void moveForward() {
  setMotorSpeed(motorSpeed);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveBackward() {
  setMotorSpeed(motorSpeed);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turnLeft() {
  setMotorSpeed(motorSpeed);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnRight() {
  setMotorSpeed(motorSpeed);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
