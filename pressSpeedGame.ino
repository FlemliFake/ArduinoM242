/*
  Press speed game

  The player has to press the button as quick as possible. The more clicks he did the more LEDs
  will get turned on. The game will restart if all LEDs are turned on and some additional clicks are done.

  Created: 09 April 2019
  Author: Patrick Scheidegger

  This code was intentionally created for the LB 2 of the learning unit (module) 242.
*/

// the number of the pushbutton pin
const int BUTTON = 2;
// the ID's of the pins
const int PINS[] = {3,4,5,6,7};
// amount of points which are needed to reach the next state
const int DISTANCE = 200;
// current score of the player
int playerScore = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LEDs and turn them off
  for(int i = 0; i < 5; i++){
    pinMode(PINS[i],OUTPUT);
    digitalWrite(PINS[i],LOW);
  }
  // initialize the pushbutton
  pinMode(BUTTON, INPUT);
}

void loop() {
  // read the state of the pushbutton value
  int buttonState = digitalRead(BUTTON);
  if (buttonState == HIGH) {
    playerScore++;
  }
  digitalWrite(PINS[playerScore / DISTANCE],HIGH);
  // if all LEDs are turned on and enough clicks were done
  // reset the game
  if(playerScore > (5 * DISTANCE)){
    playerScore = 0;
    for(int i = 0; i < 5; i++){
      digitalWrite(PINS[i],LOW);
    }
  }
}
