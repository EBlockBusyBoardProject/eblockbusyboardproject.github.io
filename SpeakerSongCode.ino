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
float c7;
float cs7;
float d7;
float ds7;
float e7;
float f7;
float fs7;
float g7;
float gs7;
float a7;
float as7;
float b7;
float c8;
float cs8;
float d8;
float ds8;
float e8;
float f8;
float fs8;
float g8;
float gs8;
float a8;
float as8;
float b8;
float bs8;

//Defines the length of the notes in miliseconds
int starBeat = 1000 / 2;
int megalovaniaBeat = 1000 / 8;
int marioBeat = 1000 / 6;

//Defines the pin that the speaker should be connected to
int speakerPin = 3;

int rnd;

void setup() {  
  pinMode (speakerPin, OUTPUT);
}

void loop() {
  rnd = random (0, 3);

  if (rnd == 0) {
    littleStar ();
  } else if (rnd == 1) {
    megalovania ();
  } else if (rnd == 2) {
    flagpoleFanfare ();
  }

  delay (1000);
}

//Plays Twinkle Twinkle Little Star
void littleStar () {
  playNote (3, c4, starBeat);
  playNote (3, c4, starBeat);
  playNote (3, g4, starBeat);
  playNote (3, g4, starBeat);
  playNote (3, a4, starBeat);
  playNote (3, a4, starBeat);
  playNote (3, g4, starBeat * 2);
}

//Plays Megalovania
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
};

//Plays a note with a small pause at the end
void playNote (int speakerPin, float note, long duration) {
  tone (speakerPin, note, duration - 50);
  delay (duration);  
}
