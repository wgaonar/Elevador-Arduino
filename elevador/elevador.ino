
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


void setup() {
    for (int i=0;i<8;i++){
      pinMode(display7Seg[i], OUTPUT);
    }

    initDisplay();
    
}

void loop() {
  countUp();
  
  while(true) {
    for(int i=0;i<10;i++) {
      flashingUp();
    }
    displayOff();
    delay(1000);
    for(int i=0;i<10;i++) {
      flashingDown();
    }
  }

}

// Turn ON and the OFF the display to show that it works
void initDisplay(){
    // loop to turn leds ON
    for (int j=0;j<8;j++){
      digitalWrite(display7Seg[j],HIGH);
    }
    delay(2000);
    // loop to turn leds OFF
    displayOff();
    delay(2000);
}

// Do a counting task from 0 to 9
void countUp(){
   for (int i=0;i<10;i++){
    for (int j=0;j<8;j++){
      digitalWrite(display7Seg[j], numArray[i][j]);
    }
    delay(250);
  }
}

// Turn Off the display
void displayOff() {
  for (int j=0;j<8;j++){
      digitalWrite(display7Seg[j],LOW);
  }
}

// Show a flashing pattern to signal the Up direction
void flashingUp(){
  for (int i=0;i<3;i++){
      for (int j=0;j<8;j++){
        digitalWrite(display7Seg[j], symbolArray[i][j]);
      }
      delay(100);
    }
}

// Show a flashing pattern to signal the Bottom direction
void flashingDown(){
  for (int i=2;i>=0;i--){
      for (int j=0;j<8;j++){
        digitalWrite(display7Seg[j], symbolArray[i][j]);
      }
      delay(100);
    }
}
