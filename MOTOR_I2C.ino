// I2C communication
#include <Wire.h>

// MOTOR CODE
int motor_direc1 = 7;
int motor_speed1 = 6;
int motor_direc2 = 4;
int motor_speed2 = 5;


void setup() {
  // I2C communication
  Wire.begin(8);
  Wire.onReceive(receiveData);
  // SETTING UP MOTOR PINS
  pinMode(motor_direc1, OUTPUT);
  pinMode(motor_direc2, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  delay(1000);
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    char receivedChar = Wire.read(); // receive a byte as character

    // Check for complex command format
    if (receivedChar == 'C') {
      while (Wire.available() < 4) {}  // Wait for 4 bytes (command + parameters)

      char command = Wire.read();
      int direction = Wire.read();
      int pwm_L = Wire.read();
      int pwm_R = Wire.read();

      // Perform actions based on received command and parameters
      if (command == 'F') {
        // Motor control command
        Serial.println("Received 'F' command. Moving motor.");
        goForward(direction, pwm_L, pwm_R);
      
      } else if (command == 'B') {
        // Motor Goes Backwards
        Serial.println("Recived 'B' command. Moving motor.");
        goBackward(direction, pwm_L, pwm_R);
      
      } else if (command == 'L') {
        // Motor Goes Backwards
        Serial.println("Recived 'L' command. Moving motor.");
        turnLeft(direction, pwm_L, pwm_R);
      
      } else if (command == 'B') {
        // Motor Goes Backwards
        Serial.println("Recived 'B' command. Moving motor.");
        goBackward(direction, pwm_L, pwm_R);
      
      }
    }
    // Add additional conditions for other commands, if needed
  }
}

void goForward(int duration, int pwm_1, int pwm_2) {
  // This is the code for the motor to go forward; VERY SIMPLE ATM
  digitalWrite(motor_direc1, HIGH);
  digitalWrite(motor_direc2, HIGH);
  analogWrite(motor_speed1, pwm_1);
  analogWrite(motor_speed2, pwm_2);
  delay(duration);
}

void goBackward(int duration, int pwm_1, int pwm_2) {
  // This is the code for the motor to go forward; VERY SIMPLE ATM
  digitalWrite(motor_direc1, LOW);
  digitalWrite(motor_direc2, LOW);
  analogWrite(motor_speed1, pwm_1);
  analogWrite(motor_speed2, pwm_2);
  delay(duration);
}

void turnLeft(int duration, int pwm_1, int pwm_2) {
  // This is the code for the motor to go forward; VERY SIMPLE ATM
  digitalWrite(motor_direc1, HIGH);
  digitalWrite(motor_direc2, LOW);
  analogWrite(motor_speed1, pwm_1);
  analogWrite(motor_speed2, pwm_2);
  delay(duration);
}

void turnRight(int duration, int pwm_1, int pwm_2) {
  // This is the code for the motor to go forward; VERY SIMPLE ATM
  digitalWrite(motor_direc1, LOW);
  digitalWrite(motor_direc2, HIGH);
  analogWrite(motor_speed1, pwm_1);
  analogWrite(motor_speed2, pwm_2);
  delay(duration);
}

void loop() {
  
}
