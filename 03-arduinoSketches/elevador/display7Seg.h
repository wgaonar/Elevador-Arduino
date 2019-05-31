void displayOn();
void displayOff();
void countUp();
void directionPattern(int);
void flashingUp();
void flashingDown();

/* Define the outputs for the 7 segments display
A0 -> a-segment
A1 -> b-segment
A2 -> c-segment
A3 -> d-segment
A4 -> e-segment
A5 -> f-segment
12 -> g-segment
13 -> dp-segment
*/
const int display7Seg[] = {A0,A1,A2,A3,A4,A5,12,13};

// Array multidimensional para mostrar los números
int  numArray[12][8] =
{
  { 1, 1, 1, 1, 1, 1, 0, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1, 0 }, // 2
  { 1, 1, 1, 1, 0, 0, 1, 0 }, // 3
  { 0, 1, 1, 0, 0, 1, 1, 0 }, // 4
  { 1, 0, 1, 1, 0, 1, 1, 0 }, // 5
  { 1, 0, 1, 1, 1, 1, 1, 0 }, // 6
  { 1, 1, 1, 0, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1, 0 }, // 8
  { 1, 1, 1, 0, 0, 1, 1, 0 }, // 9
  { 1, 0, 1, 1, 0, 1, 1, 1 }, // Letter S
  { 1, 1, 1, 1, 1, 1, 1, 1 }, // Letter B
  
};


int symbolArray[3][8] =
{
  { 1, 0, 0, 0, 0, 0, 0, 0 }, // Upper dash
  { 0, 0, 0, 0, 0, 0, 1, 0 }, // Middle dash
  { 0, 0, 0, 1, 0, 0, 0, 0 }, // Bottom dash
};


// Turn ON and the OFF the display to show that it works
void initDisplay(){
    for (int n=0;n<2;n++) {
      // loop to turn leds ON
      displayOn();
      delay(500);
    
       // loop to turn leds OFF
      displayOff();
      delay(500);
    }
    
    // Do the counting from 0 to 9
    countUp();
    delay(500);

    // Show X times the direction pattern in both directions
    directionPattern(2);

    // Let the display be ready to start with the program
    displayOff();
}

void displayNumber(int number) {
  for (int segment=0;segment<8;segment++){
      digitalWrite(display7Seg[segment], numArray[number][segment]);
  }
}

void displaySymbol(int symbol) {
  for (int segment=0;segment<8;segment++){
      digitalWrite(display7Seg[segment], symbolArray[symbol][segment]);
  }
}

// Turn On the display
void displayOn() {
  for (int segment=0;segment<8;segment++){
      digitalWrite(display7Seg[segment],HIGH);
  }
}

// Turn Off the display
void displayOff() {
  for (int segment=0;segment<8;segment++){
      digitalWrite(display7Seg[segment],LOW);
  }
}

// Do a counting task from 0 to 9
void countUp(){
  // Go into each number of the matrix of numbers
  for (int number=0;number<10;number++){
    displayNumber(number);
    // Wait one second showing 0 befor continue with the counting
    if (number==0)
      delay(500);
    else
      delay(125);
  }
}

void directionPattern(int times){
    for(int i=0;i<times;i++) {
      flashingUp();
    }
    displayOff();
    delay(1000);
    for(int i=0;i<times;i++) {
      flashingDown();
    }
}

// Show a flashing pattern to signal the Up direction
void flashingUp(){
  for (int symbol=0;symbol<3;symbol++){
      displaySymbol(symbol);
      delay(150);
  }
}

// Show a flashing pattern to signal the Down direction
void flashingDown(){
  for (int symbol=2;symbol>=0;symbol--){
      displaySymbol(symbol);
      delay(150);
   }
}

// Overloaded function with the delay time as a paremeter
void flashingDown(int delayTime){
  for (int symbol=2;symbol>=0;symbol--){
      displaySymbol(symbol);
      delay(delayTime);
   }
}
