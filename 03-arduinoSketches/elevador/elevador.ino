
#include "display7Seg.h"
#include "motor.h"

const int sensorFloor_1 = 2;
const int sensorFloor_2 = 3;
const int sensorFloor_3 = 4;

const int buttonFloor_1 = 6;
const int buttonFloor_2 = 7;
const int buttonFloor_3 = 8;

// Speed in percentage for the elevator ranging from 0 to 100
int speed = 50;

int actualFloor;

void setup() {
  // Configure the pins for the 7 segments display
  for (int segment=0;segment<8;segment++){
    pinMode(display7Seg[segment], OUTPUT);
  }
  
  // Configure the pins for the buttons and sensors for the levels
  pinMode(buttonFloor_1,INPUT);
  pinMode(buttonFloor_2,INPUT);
  pinMode(buttonFloor_3,INPUT);
  pinMode(sensorFloor_1,INPUT);
  pinMode(sensorFloor_1,INPUT);
  pinMode(sensorFloor_1,INPUT);
  
  // Configure the pins for the motor
  pinMode(motorPin_1,OUTPUT);
  pinMode(motorPin_2,OUTPUT);
  pinMode(motorEnA,OUTPUT);

  // Show the initial signal for a working display
  initDisplay();

  // Initialize the elevator send it to the 1 floor
  homeElevator();
}

void loop() {
   if(digitalRead(buttonFloor_3) == HIGH && actualFloor!=3) {
      while(digitalRead(sensorFloor_3) == LOW) {
        motorGoUp(speed);
 
      }
      motorBrake();
      actualFloor = 3;
      displayNumber(actualFloor);
   }
   else if(digitalRead(buttonFloor_1) == HIGH && actualFloor!=1) {
      while(digitalRead(sensorFloor_1) == LOW){
        motorGoDown(speed);

      }
      motorBrake();
      actualFloor = 1;
      displayNumber(actualFloor);
   }
   else if(digitalRead(buttonFloor_2) == HIGH && actualFloor!=2) {
      if (actualFloor == 3) {
        while(digitalRead(sensorFloor_2) == LOW){
          motorGoDown(speed);
        }
        motorBrake();
        actualFloor = 2;
        displayNumber(actualFloor);
      }
      else if (actualFloor == 1) {
        while(digitalRead(sensorFloor_2) == LOW){
          motorGoUp(speed);
        }
        motorBrake();
        actualFloor = 2;
        displayNumber(actualFloor);
      }
   }
}

void homeElevator() {
  while(digitalRead(sensorFloor_1) == LOW) {
    motorGoDown(speed*0.75);
  }
  motorBrake();
  actualFloor = 1;
  displayNumber(actualFloor);
}
