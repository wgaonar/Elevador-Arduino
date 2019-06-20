const int motorPin_1 = 9;
const int motorPin_2 = 10;
const int motorEnA = 11;

// Define one direction for the motor
void motorBrake(){
  digitalWrite(motorPin_1,HIGH);
  digitalWrite(motorPin_2,HIGH);
}

// Define one direction for the motor
void motorGoUp(int speed){
  analogWrite(motorEnA,speed);
  digitalWrite(motorPin_1,HIGH);
  digitalWrite(motorPin_2,LOW);
  flashingDown(); // Check a synchronization problem. I have to use the inverse pattern
  delay(20);
}

// Define one direction for the motor
void motorGoDown(int speed){
  analogWrite(motorEnA,speed*0.5);
  digitalWrite(motorPin_1,LOW);
  digitalWrite(motorPin_2,HIGH);
  flashingUp(); // Check a synchronization problem. I have to use the inverse pattern
  delay(20);
}
