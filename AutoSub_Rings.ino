/* 
   AutoSub Spire Rings. 

   N rings, each with M columns. We want to be able to control them as
   both rings, as well as by column.

   Memory is at more of a premium than CPU, so the basic idea is to
   iterate of the LEDs, and act on each one. There are some helper
   functions that you can call to see what row or column something is
   in. This should make it pretty clean to interact with.
*/

#define NUM_RINGS 11
#define NUM_COLUMNS 6
#define NUM_LEDS 66


int DEFAULT_BRIGHT = 50;
int DEFAULT_SATURATION = 200;
int MUTATE_BRIGHT = 255;
int MUTATE_SATURATION = 255;

int DELAY = 5;

// Stripe ever N columns
// Uses mod to figure out what should be active
// recommend things that evenly divide into 6. (2, 3, or 6)
int stripe_every = 6;

// How often to mutuate. Recommend 50-100
int MUTATION_RATE = 7;

// How often to *change* the game we're playing.
// Lets say every minute?
int GAME_CHANGE = 10000;

// FastSPI Stuff
#include "FastSPI_LED2.h"
#define DATA_PIN 6
//#define CLOCK_PIN 8


// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];
CHSV ledhsv[NUM_LEDS];

// Helper functions
int ring_num(int i) { return i/NUM_COLUMNS; }
int column_num(int i) { return i % NUM_COLUMNS; }

// What counters for the special ring and special column
boolean active_columns[NUM_COLUMNS] = {0};
boolean active_rings[NUM_RINGS] = {0};
int active_ring = 0;
int active_column = 0;

// counter for doing loop calculations
unsigned int count = 0;

void mode1_setup() {
  // Initialize colors. Each ring a different color, evenly spaced
  // over hald the rainbow. (seems to make for nice set of fades)
  for(int i = 0; i < NUM_LEDS; i = i + 1) {
    int hue = ring_num(i) * 255 / (NUM_RINGS * 2);
    ledhsv[i].hue        =   hue;
    ledhsv[i].saturation =   DEFAULT_SATURATION;
    ledhsv[i].value      =   DEFAULT_BRIGHT;

    Serial.print(i);
    Serial.print(" r");
    Serial.print(ring_num(i));
    Serial.print(" c");
    Serial.print(column_num(i));
    Serial.print(" hue: ");
    Serial.println(hue);
  }
}


void mode1_loop(unsigned int count) {

  // Change the game
  if(count % GAME_CHANGE == 0) {
    MUTATION_RATE      = random(7, 70);
    DEFAULT_BRIGHT     = random(40, 240);
    DEFAULT_SATURATION = random(150, 240);

  }

  // mutate the active column every 10 cycles
  if(count % MUTATION_RATE == 0) {
    active_column = (active_column + 1)  % NUM_COLUMNS;
  
    for(int c = 0; c < NUM_COLUMNS; c++ ) {
      if( (c + active_column % NUM_COLUMNS ) % stripe_every == 0 ) {
	active_columns[c] = true;
      }
      else {
	active_columns[c] = false;
      }
    }
  }



  for(int i = 0; i < NUM_LEDS; i = i + 1) {
    hsv2rgb_spectrum( ledhsv[i], leds[i] );
    ledhsv[i].hue -= 1;

    // Mutate the active column
    if( active_columns[column_num(i)] == true ) {
      ledhsv[i].saturation = MUTATE_SATURATION;
      ledhsv[i].value      = MUTATE_BRIGHT;
    } else {
      ledhsv[i].saturation = DEFAULT_SATURATION;;
      ledhsv[i].value      = DEFAULT_BRIGHT;
    }

  }
}

void setup() {
  // Boring arduino setup
  long tempBits = 0;   // create a long of random bits to use as seed
  for (int i=1; i<=32 ; i++){                    
    tempBits = ( tempBits | ( analogRead( 3 ) & 1 ) ) << 1;
  }
  randomSeed(tempBits);
  
  Serial.begin(9600);

  // sanity check delay - allows reprogramming if accidently blowing
  // power w/leds
  delay(1000);
  
  // initial the LEDs
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);

  // Set everything block. Just clear everything.
  fill_solid( &(leds[0]), NUM_LEDS, CRGB::Black );
  FastLED.show();

  mode1_setup();
}


void loop() {
  count++;
  mode1_loop(count);
  FastLED.show();
  delay(DELAY);
}
