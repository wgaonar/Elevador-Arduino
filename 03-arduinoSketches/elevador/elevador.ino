
#include "display7Seg.h"
#include "motor.h"

const int buttonFloor_1 = 6;
const int buttonFloor_2 = 7;
const int buttonFloor_3 = 8;

const int sensorFloor_1 = 4;
const int sensorFloor_2 = 3;
const int sensorFloor_3 = 2;

// Speed in percentage for the elevator ranging from 0 to 100
int speed = 50;

int actualFloor;

void setup() {
  // Configure the pins for the 7 segments display
  for (int i=0;i<8;i++){
    pinMode(display7Seg[i], OUTPUT);
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

  //Show the initial signal for a working display
  initDisplay();  
}

void loop() {
   if(digitalRead(buttonFloor_3) == HIGH) {
      while(sensorFloor_3 == LOW) {
        motorGoUp(speed);
        flashingUp();
      }
      motorBrake();
      actualFloor = 3;
      displayNumber(actualFloor);
   }
   else if(digitalRead(buttonFloor_1) == HIGH) {
      while(sensorFloor_1 == LOW){
        motorGoDown(speed);
        flashingDown();
      }
      motorBrake();
      actualFloor = 1;
      displayNumber(actualFloor);
   }
   else if(digitalRead(buttonFloor_2) == HIGH) {
      if (actualFloor == 3) {
        while(sensorFloor_2 == LOW){
          motorGoDown(speed);
          flashingDown();
        }
        motorBrake();
        actualFloor = 2;
        displayNumber(actualFloor);
      }
      else if (actualFloor == 1) {
        while(sensorFloor_2 == LOW){
          motorGoUp(speed);
          flashingUp();
        }
        motorBrake();
        actualFloor = 2;
        displayNumber(actualFloor);
      }
   }
}
