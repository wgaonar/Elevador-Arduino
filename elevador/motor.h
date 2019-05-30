const int motorPin_1 = 9;
const int motorPin_2 = 10;
const int motorEnA = 11;


// Define one direction for the motor
void motorGoUp(int speed){
  int mappedSpeed = map(speed,0,100,0,255);
  analogWrite(motorEnA,mappedSpeed);
  digitalWrite(motorPin_1,HIGH);
  digitalWrite(motorPin_2,LOW);
  delay(100);
}

// Define one direction for the motor
void motorGoDown(int speed){
  int mappedSpeed = map(speed,0,100,0,255);
  analogWrite(motorEnA,mappedSpeed);
  digitalWrite(motorPin_1,LOW);
  digitalWrite(motorPin_2,HIGH);
  delay(100);
}

// Define one direction for the motor
void motorBrake(){
  digitalWrite(motorPin_1,HIGH);
  digitalWrite(motorPin_2,HIGH);
}
