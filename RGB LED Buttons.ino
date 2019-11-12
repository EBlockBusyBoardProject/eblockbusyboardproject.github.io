/*
This script changes the color of an RGB LED using three buttons as input.

RGB LED
  Connect the red pin to pin 2 with a 330 resistor
  Connect the ground pin to ground
  Connect the green pin to pin 3 with a 330 resistor
  Connect the blue pin to pin 4 with a 330 resistor

Button
  Connect each button to the 5V pin and to ground with a 10K resistor
  Connect the button that controls red, to pin 12
  Connect the button that controls green, to pin 11
  Connect the button that controls blue, to pin 10
*/

//Defines the pins that the buttons are plugged into
int rButtonPin = 2;
int gButtonPin = 3;
int bButtonPin = 4;

//Defines the pins that the RGB LED is plugged into
int rPin =  12;
int gPin =  11;
int bPin =  10;

//Stores the states of the RGB LED
int rState = LOW;
int gState = LOW;
int bState = LOW;

//Finds the state of each of the buttons
int rButtonState;
int gButtonState;
int bButtonState;

void setup() {
  //LED pins are outputs
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  //Button pins are inputs
  pinMode(rButtonPin, INPUT);
  pinMode(gButtonPin, INPUT);
  pinMode(bButtonPin, INPUT);
}

void loop() {
  //Finds the state of the buttons
  rButtonState = digitalRead (rButtonPin);
  gButtonState = digitalRead (gButtonPin);
  bButtonState = digitalRead (bButtonPin);

  //Turns the red part of the RGB LED on if the red button is being pressed
  if (rButtonState == HIGH) {
    digitalWrite (rPin, HIGH);
  } else {
    digitalWrite (rPin, LOW);
  }

  //Turns the green part of the RGB LED on if the green button is being pressed
  if (gButtonState == HIGH) {
    digitalWrite (gPin, HIGH);
  } else {
    digitalWrite (gPin, LOW);
  }

  //Turns the green part of the RGB LED on if the green button is being pressed
  if (bButtonState == HIGH) {
    digitalWrite (bPin, HIGH);
  } else {
    digitalWrite (bPin, LOW);
  }
}
