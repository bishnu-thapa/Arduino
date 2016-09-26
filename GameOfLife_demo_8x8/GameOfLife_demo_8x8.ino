/*
 * 
 * 8x8 LED matrix Game of Life demo for Arduino. Version 1.4, 160421.
 * Copyright (c) 2016 Dalibor Sramek, http://www.insula.cz
 * Released under the The MIT License (MIT)
 * https://opensource.org/licenses/MIT
 * (Except the function freeRAM which is optional and credited in the code.)
 * 
 */


// Let's define a couple of constants first
#define _8X8_STEP 250  // delay time for each step
#define _8X8HIST 35   // size of the buffer to check for a repeating pattern

// We need LedControl library: http://playground.arduino.cc/Main/LedControl
#include "LedControlMS.h"

// The library brings an object for controlling the 8x8 LED matrix display
// Change the numbers according to the actual hardware configuration
LedControl lc = LedControl(12, 11, 10, 1);  // DIN, CLK, CS, # of displays

/*
 * The application logic uses 8 byte (8x8 bits) buffers for computation.
 * Some helper functions to manipulate the buffers follow.
 */

// Initialize the buffer with zeroes
void initBuffer(byte *m) {
  byte i;
  for (i = 0; i < 8; i++) m[i] = 0;
}

// Copy the first buffer (source) into the second buffer (target)
void copyBuffer(byte *s, byte *t) {
  byte i;
  for (i = 0; i < 8; i++) t[i] = s[i];
}


// Compare two buffers, return true if the content is identical
bool cmpBuffer(byte *s, byte *t) {
  bool r = true;
  byte i;
  for (i = 0; i < 8; i++) if (s[i] != t[i]) { r = false; break; }
  return r;
}

// Fill the buffer with random numbers (2 32-bit numbers fill 64-bit buffer) 
void randomizeBuffer(byte *m) {
  long *l;
  l = (long *)m;
  l[0] = random();
  l[1] = random();
}

// Get dot status (buffer, x coordinate, y coordinate)
bool getDot(byte *m, byte x, byte y) {
  return (m[y] & (128 >> x)) > 0;
}

// Set dot status (buffer, x coordinate, y coordinate, new status)
void setDot(byte *m, byte x, byte y, bool v) {
  if (v) m[y] |= (128 >> x);
  else m[y] &= ~(128 >> x);
}

// Switch dot on (buffer, x coordinate, y coordinate)
void dotOn(byte *m, byte x, byte y) {
  setDot(m, x, y, true);
}

// Switch dot off (buffer, x coordinate, y coordinate)
void dotOff(byte *m, byte x, byte y) {
  setDot(m, x, y, false);
}

// Toggle dot (buffer, x coordinate, y coordinate)
void dotToggle(byte *m, byte x, byte y) {
  setDot(m, x, y, !getDot(m, x, y));
}

/*
 * Specific functions for the game of life
 */

// Count alive neighbors of the cell (buffer, x coordinate, y coordinate)
byte countNbors(byte *m, byte x, byte y) {
  byte c = 0;
  if ((x > 0) && (y > 0) && getDot(m, x - 1, y - 1)) c++;
  if (           (y > 0) && getDot(m, x    , y - 1)) c++;
  if ((x < 7) && (y > 0) && getDot(m, x + 1, y - 1)) c++;
  if ((x < 7)            && getDot(m, x + 1, y    )) c++;
  if ((x < 7) && (y < 7) && getDot(m, x + 1, y + 1)) c++;
  if (           (y < 7) && getDot(m, x    , y + 1)) c++;
  if ((x > 0) && (y < 7) && getDot(m, x - 1, y + 1)) c++;
  if ((x > 0)            && getDot(m, x - 1, y    )) c++;
  return c;
}


/*
 * A couple of functions to display things on the actual LED matrix. 
 */
 
// Display a buffer byte by byte
void displayBuffer(byte *buffer) {
  byte i;
  for (i = 0; i < 8; i++) lc.setRow(0, i, buffer[i]);
}

// Display the introductory splashscreen (ankh symbol rolling up)
void splash1() {
  static byte s_a[8] = { 0x18, 0x24, 0x24, 0x18, 0x7e, 0x18, 0x18, 0x18 };
  byte s_b[8]; 
  byte i, j;
  copyBuffer(s_a, s_b);
  displayBuffer(s_b);
  delay(_8X8_STEP * 8);
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 7; j++) s_b[j] = s_b[j + 1];
    s_b[7] = 0;
    displayBuffer(s_b);
    delay(_8X8_STEP / 2);
  }
}

// Display the divider splashscreen between before a new game (expanding square)
void splash2() {
  static byte s[5][8] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00 },
    { 0x00, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x7e, 0x00 },
    { 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff }
  };
  byte i;
  for (i = 0; i < 5; i++) {
    displayBuffer(s[i]);
    delay(_8X8_STEP / 2);
  }
}

// Get number of available SRAM bytes (may be useful for debugging)
// This code is published at http://playground.arduino.cc/Code/AvailableMemory
word freeRAM() {
  extern word __heap_start, *__brkval;
  word v;
  return (word) &v - (__brkval == 0 ? (word) &__heap_start : (word) __brkval);
}

// Display graphical representation of free SRAM (lit LEDs represent full RAM)
void splash3() {
  byte s[8], i, j;
  word fr;
  initBuffer(s);
  fr = freeRAM() / 32;
  for (i = 0; i < 8; i++) for (j = 0; j < 8; j++) if ((8 * j + i) >= fr) dotOn(s, i, j);
  displayBuffer(s);
  delay(_8X8_STEP * 12);
}

/*
 * Now we are all set and can define the two standard Arduino functions
 */

// SETUP
void setup() {
  // Switch off built-in LED on pin 13
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  // Initialize the random number generator with reading from an unconnected pin
  randomSeed(analogRead(0));
  // Initialize the display
  lc.shutdown(0, false);
  lc.setIntensity(0, 3);
  lc.clearDisplay(0);
  // Display the introductory splash screen
  splash1();
}

// LOOP
void loop() {

  // Let's have a couple of predefined seed patterns with long playing time
  const byte nseeds = 8;
  byte seeds[nseeds][8] = {
    { 0xa2, 0xb4, 0x71, 0x03, 0xf1, 0xaa, 0x8b, 0xa5 }, // 221 rounds
    { 0xa9, 0x7d, 0x49, 0x9a, 0x30, 0x4a, 0xbf, 0x81 }, // 206 rounds
    { 0xbd, 0xaa, 0xfb, 0x31, 0xa3, 0x61, 0xc7, 0x5a }, // 202 rounds
    { 0x18, 0x78, 0xc2, 0xaa, 0x25, 0x0d, 0x2b, 0x23 }, // 200 rounds
    { 0x2b, 0x16, 0x1a, 0xe5, 0xde, 0x28, 0xaa, 0x38 }, // 182 rounds, period 32
    { 0x33, 0xb7, 0xe5, 0x37, 0x05, 0x99, 0xad, 0x48 }, // 181 rounds, period 32
    { 0x62, 0x0d, 0x36, 0x05, 0x5c, 0xca, 0x09, 0xd0 }, // 172 rounds, period 32
    { 0x4c, 0x10, 0xde, 0xc8, 0x84, 0x41, 0xb6, 0xe7 }  // 170 rounds, period 32
  };

  byte buffer_a[8];            // primary buffer shown on the LED matrix
  byte buffer_b[8];            // secondary buffer used for computation
  byte buffer_h[_8X8HIST][8];  // buffer history to detect repeating patterns
  byte hpoint = 0;             // history buffer pointer
  byte nbors, alive;
  byte dejavu;
  byte i, j;
  word rl = 0;                 // game runlength
  byte rc = 50;

  // Show remaining free memory
  splash3();

  // Start with empty buffer (this will reset the game in the second round)
  initBuffer(buffer_a);

  // Inner infinite loop to allow variable initialization in the loop() function
  while (true) {
      
    // First clear buffer B
    initBuffer(buffer_b);
  
    // Calculate future status for each cell and store it into the buffer B
    // https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        alive = getDot(buffer_a, i, j); // get current cell status
        nbors = countNbors(buffer_a, i, j); // count number of neighbors
        if (alive) {
          if ((nbors == 2) || (nbors == 3)) dotOn(buffer_b, i, j);
        }
        else {
          if (nbors == 3) dotOn(buffer_b, i, j);
        }
      }
    }
  
    // Check if the calculated pattern is already stored in the history
    dejavu = 0;
    for (i = 0; i < hpoint; i++) {
      if (cmpBuffer(buffer_b, buffer_h[i])) {
        // Pattern found
        dejavu = hpoint - i;
        break;
      }
    }
  
    // If pattern reoccurs we need to start a new game
    if (dejavu) {
      delay(_8X8_STEP * 4);  // show the final pattern for a while
      if ((dejavu >= 32) || (rl > 99)) splash1();  // use special splash for patterns
      else splash2();                              // with long period or run length
      // Each defined number of games reseed the RNG
      if (--rc == 0) {
        randomSeed(analogRead(0));
        rc = 50;
      }
      i = random(10 * nseeds);
      if (i < nseeds) copyBuffer(seeds[i], buffer_a);   // use on of the seeds
      else randomizeBuffer(buffer_a);  // or randomly reset the buffer
      hpoint = 0;  // reset history pointer
      rl = 0;  // reset run length counter
    }
    // Otherwise copy the new pattern to the screen buffer A
    else {
      copyBuffer(buffer_b, buffer_a);
      copyBuffer(buffer_b, buffer_h[hpoint]);  // store pattern to the history
      hpoint++;  // increase the history pointer
      if (hpoint >= _8X8HIST) hpoint = 0;  // prevent overflow
      rl++;  // increase run length counter
    }
  
    // Display the new pattern for a while and repeat the cycle
    displayBuffer(buffer_a);
    delay(_8X8_STEP);

  }  // of inner while loop

}

