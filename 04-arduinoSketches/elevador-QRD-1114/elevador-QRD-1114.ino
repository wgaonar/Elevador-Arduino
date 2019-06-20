/******************************************************************************
elevador-QRD-1114.ino
Main program to control a elevator's model
Wilmer Gaona @ Marymount School Cuernavaca
June 12, 2019

Connect a QRD1114, 330 resistor and 10k resistor as follows:

QRD1114 Pin ---- Arduino ---- Resistors
    1              A0      10k Pull-up to 5V
    2              GND
    3                      220 Resistor to 5V
    4              GND

As an object comes closer to the QRD1114, the voltage on A0 should go down.
*******************************************************************************/

#include "display7Seg-QRD-1114.h"
#include "motor-QRD-1114.h"

const int sensorFloor_1 = A3;
const int sensorFloor_2 = A4;
const int sensorFloor_3 = A5;

const int buttonFloor_1 = 6;
const int buttonFloor_2 = 7;
const int buttonFloor_3 = 8;

const int speedControl = A6;

// Speed is in percentage for the elevator ranging from 0 to 255
int speed = 0;


int actualFloor=0;

// Threshold value for detecting the elevator
int QRD1114_Threshold = 200;

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

    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Show the initial signal for a working display
  initDisplay();

  // Initialize the elevator send it to the 1 floor
  homeElevator();


}

void loop() {
  speed = map(analogRead(speedControl),0,1023,75,255); // map the speed from 0-1023 to 200-255
  delay(10);
   
   if(digitalRead(buttonFloor_3) == HIGH && actualFloor!=3) {
      while(analogRead(sensorFloor_3) >= QRD1114_Threshold) {
        motorGoUp(speed);
      }
      motorBrake();
      actualFloor = 3;
      displayNumber(actualFloor);
   }
   else if(digitalRead(buttonFloor_1) == HIGH && actualFloor!=1) {
      while(analogRead(sensorFloor_1) >= QRD1114_Threshold){
        motorGoDown(speed);

      }
      motorBrake();
      actualFloor = 1;
      displayNumber(actualFloor);
   }
   else if(digitalRead(buttonFloor_2) == HIGH && actualFloor!=2) {
      if (actualFloor == 3) {
        while(analogRead(sensorFloor_2) >= QRD1114_Threshold){
          motorGoDown(speed);
        }
        motorBrake();
        actualFloor = 2;
        displayNumber(actualFloor);
      }
      else if (actualFloor == 1) {
        while(analogRead(sensorFloor_2) >= QRD1114_Threshold){
          motorGoUp(speed);
        }
        motorBrake();
        actualFloor = 2;
        displayNumber(actualFloor);
      }
   }
}

void homeElevator() {

  while(analogRead(sensorFloor_1) >= QRD1114_Threshold) {
    speed = map(analogRead(speedControl),0,1023,128,255); // map the speed from 0-1023 to 200-255
    motorGoDown(speed);
    Serial.print("homing QRD1114_Value: ");
    Serial.print(analogRead(sensorFloor_1));
    Serial.print(" Speed: ");
    Serial.println(speed);
    delay(10);
  }
  motorBrake();
  actualFloor = 1;
  displayNumber(actualFloor);
}
