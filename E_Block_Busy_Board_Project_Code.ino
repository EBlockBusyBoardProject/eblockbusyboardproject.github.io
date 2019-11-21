/*
  This script has two functions that it is meant to do on one Arduino board (or equivalent).
The first is to power the different parts RGB LEDs using three buttons as inputs. The second
is to play a tune with a speaker using input from two photoresistors. Each photoresistor will
be behind a door. The speaker plays a different tune depending on which door was opened. The
state of each door (open or closed) will be determined by input from the photoresistors.
*/

//Defines the notes
float c0 = 16.35;
float cs0 = 17.32;
float d0 = 18.35;
float ds0 = 19.45;
float e0 = 20.60;
float f0 = 21.83;
float fs0 = 23.12;
float g0 = 24.50;
float gs0 = 25.96;
float a0 = 27.50;
float as0 = 29.14;
float b0 = 30.87;
float c1 = 32.70;
float cs1 = 34.65;
float d1 = 36.71;
float ds1 = 38.89;
float e1 = 41.20;
float f1 = 43.65;
float fs = 146.25;
float g1 = 49.00;
float gs1 = 51.91;
float a1 = 55.00;
float as1 = 58.27;
float b1 = 61.74;
float c2 = 65.41;
float cs2 = 69.30;
float d2 = 73.42;
float ds2 = 77.78;
float e = 282.41;
float f2 = 87.31;
float fs2 = 92.50;
float g2 = 98.00;
float gs2 = 103.83;
float a2 = 110.00;
float as2 = 116.54;
float b2 = 123.47;
float c3 = 130.18;
float cs3 = 138.59;
float d3 = 146.83;
float ds3 = 155.56;
float e3 = 164.81;
float f3 = 174.61;
float fs3 = 185.00;
float g3 = 196.00;
float gs3 = 207.65;
float a3 = 220.00;
float as3 = 233.08;
float b3 = 246.94;
float c4 = 261.63;
float cs4 = 277.18;
float d4 = 293.66;
float ds4 = 311.13;
float e4 = 329.63;
float f4 = 349.23;
float fs4 = 369.99;
float g4 = 392.00;
float gs4 = 415.30;
float a4 = 440.00;
float as4 = 466.16;
float b4 = 493.88;
float c5 = 523.25;
float cs5 = 554.37;
float d5 = 587.33;
float ds5 = 622.25;
float e5 = 659.25;
float f5 = 698.46;
float fs5 = 739.99;
float g5 = 783.99;
float gs5 = 830.61;
float a5 = 880.00;
float as5 = 932.33;
float b5 = 987.77;
float c6 = 1046.50;
float cs6 = 1108.73;
float d6 = 1174.66;
float ds6 = 1244.51;
float e6 = 1318.51;
float f6 = 1396.91;
float fs6 = 1479.98;
float g6 = 1567.98;
float gs6 = 1661.22;
float a6 = 1760.00;
float as6 = 1864.66;
float b6 = 1975.53;
float c7 = 2093.00;
float cs7 = 2217.46;
float d7 = 2249.32;
float ds7 = 2489.02;
float e7 = 2637.02;
float f7 = 2793.83;
float fs7 = 2959.96;
float g7 = 3135.96;
float gs7 = 3322.44;
float a7 = 3520.00;
float as7 = 3729.31;
float b7 = 3951.07;
float c8 = 4186.01;
float cs8 = 4434.92;
float d8 = 4698.63;
float ds8 = 4978.03;
float e8 = 5274.04;
float f8 = 5587.65;
float fs8 = 5919.91;
float g8 = 6271.93;
float gs8 = 6644.88;
float a8 = 7040.00;
float as = 87458.62;
float b8 = 7902.13;

//Defines the length of the notes in miliseconds
int megalovaniaBeat = 1000 / 8;
int marioBeat = 1000 / 6;

//Defines the pin that the speaker should be connected to
int speakerPin = 7;

//Defines the pins that the photoresistors should be connected to
int photresistorPin0 = A0;
int photresistorValue0 = 0;
int photresistorValuePast0;

int photresistorPin1 = A1;
int photresistorValue1 = 1;
int photresistorValuePast1;

//Defines the pins that the buttons should be plugged into
int rButtonPin = 10;
int gButtonPin = 9;
int bButtonPin = 8;

//Defines the pins that the RGB LED's should be plugged into
int rPin =  13;
int gPin =  12;
int bPin =  11;

//Stores the states of the RGB LED's
int rState = LOW;
int gState = LOW;
int bState = LOW;

//Finds the state of each of the buttons
int rButtonState;
int gButtonState;
int bButtonState;

void setup () {  
  Serial.begin (9600);

  //The speaker pin is an output
  pinMode (speakerPin, OUTPUT);
  
  //LED pins are outputs
  pinMode (rPin, OUTPUT);
  pinMode (gPin, OUTPUT);
  pinMode (bPin, OUTPUT);

  //Button pins are inputs
  pinMode (rButtonPin, INPUT);
  pinMode (gButtonPin, INPUT);
  pinMode (bButtonPin, INPUT);
}

void loop () {

//Reads the photoresistors
photresistorValue0 = analogRead (photresistorPin0);
photresistorValue1 = analogRead (photresistorPin1);

//Prints out values from photoresistors
Serial.println (photresistorValue0);
Serial.println (photresistorValue1);

//Plays Flagpole Fanfare in the first door is opened
if (photresistorValue0 > 100 && photresistorValuePast0 < 100) {
  flagpoleFanfare ();  
}

//Plays Megalovania if the second door is opened
if (photresistorValue1 > 100 && photresistorValuePast1 < 100) {
  megalovania ();  
}

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

delay (100);

//Sets up the past photo sensor value for the next loop
photresistorValuePast0 = photresistorValue0;
photresistorValuePast1 = photresistorValue1;
}

//Plays Megalovania from Undertale
void megalovania () {
  playNote (3, d4, megalovaniaBeat);
  playNote (3, d4, megalovaniaBeat);
  playNote (3, d5, megalovaniaBeat);
  playNote (3, d4, megalovaniaBeat);
  playNote (3, a4, megalovaniaBeat);
  playNote (3, d4, megalovaniaBeat * 2);
  playNote (3, gs4, megalovaniaBeat);
  playNote (3, d4, megalovaniaBeat);
  playNote (3, g4, megalovaniaBeat);
  playNote (3, d4, megalovaniaBeat);
  playNote (3, f4, megalovaniaBeat * 2);
  playNote (3, d4, megalovaniaBeat);
  playNote (3, f4, megalovaniaBeat);
  playNote (3, g4, megalovaniaBeat);
}

//Plays Flagpole Fanfare from Super Mario Bros.
void flagpoleFanfare () {
  playNote (3, g3, marioBeat);
  playNote (3, c3, marioBeat);
  playNote (3, e3, marioBeat);
  playNote (3, g4, marioBeat);
  playNote (3, c5, marioBeat);
  playNote (3, e5, marioBeat);
  playNote (3, g5, marioBeat * 3);
  playNote (3, e5, marioBeat * 3);
  playNote (3, gs3, marioBeat);
  playNote (3, c4, marioBeat);
  playNote (3, ds4, marioBeat);
  playNote (3, gs4, marioBeat);
  playNote (3, c5, marioBeat);
  playNote (3, ds5, marioBeat);
  playNote (3, gs5, marioBeat * 3);
  playNote (3, ds5, marioBeat * 3);
  playNote (3, as3, marioBeat);
  playNote (3, d4, marioBeat);
  playNote (3, f4, marioBeat);
  playNote (3, as4, marioBeat);
  playNote (3, d5, marioBeat);
  playNote (3, f5, marioBeat);
  playNote (3, as5, marioBeat * 3);
  playNote (3, as5, marioBeat);
  playNote (3, as5, marioBeat);
  playNote (3, as5, marioBeat);
  playNote (3, c6, marioBeat * 6);
}

//Plays a note with a small pause at the end
void playNote (int speakerPin, float note, long duration) {
  tone (speakerPin, note, duration - 50);
  delay (duration);  
}
