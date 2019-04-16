/*
  Light sequence

  Turns an LED on for the set time by the potentiometer. After the specific period, it turns the current one off
  and jumps to the next one till the chain is finished. This cyclus will be repeated infinitly.

  Created: 09 April 2019
  Author: Patrick Scheidegger

  This code was intentionally created for the LB 2 of the learning unit (module) 242.
*/
 
// the ID's of the pins
const int PINS[] = {10,9,8,7,6,5,4,3,2};

const int POT_ID = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LEDs and turn them off
  for(int i = 0; i < 9; i++){
    pinMode(PINS[i],OUTPUT);
    digitalWrite(PINS[i],LOW);
  }
}

/*
 * Gets the time out based on the user input
 * of the potentiometer
 * 
 * return int, time out duration in milliseconds
 */
int getTimeOut(){
  int timeOut = analogRead(POT_ID);
  // set minimum time out
  if(timeOut <= 40){
    timeOut = 40;  
  }
  timeOut /= 2;
  return timeOut;
}

void loop() {
  // turn one LED on for a specific time, then turn it off
  for(int i = 0; i < 9; i++){
    digitalWrite(PINS[i],HIGH);
    delay(getTimeOut());
    digitalWrite(PINS[i],LOW);
  }
}
