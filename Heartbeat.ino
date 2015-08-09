/*
  AutoSub Spire
  Burning Man 2014
  seph@directionless.org
  
  Various sources:
    * http://sean.voisen.org/blog/2011/10/breathing-led-with-arduino/
    * the BlinkWithoutDelay example
  
  Simple heartbeat sketch for the becon on top of the spire.
  Expects to work with an NPN transistor.
  
  Entirely pulled from a blog post that had clever math.
  
  Basic theory:
  1. Global function for how to computer heartbeat output, based on integer input
  2. Global variables for the step in the heartbeat we're at
  3. Every cycle check if we're hit the interval trigger
  4. If so, feed the step into the heartbeat function
  
*/

// period, in ms. 
const float period = 1000.0;

#include <math.h>

void setup() {
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  analogWrite(13, 0);
  analogWrite(9, 0);

}

void loop() {
  // adjust the 1000*pi to be the cycle. 
  //float val = (exp(sin(millis()/1000.0*PI)) - 0.36787944)*108.0;
  float val = (exp(sin(millis()/period*PI)) - 0.36787944)*108.0;
  analogWrite(13, val); // boarduino has a digital pin on 13, good for status
  analogWrite(9, val);  // actual analog output

}
