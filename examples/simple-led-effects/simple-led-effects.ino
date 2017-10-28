#include <led-effects.h>

#define ledPin 6 
#define NUMPIXELS 12

void done();

NeoPatterns leds(NUMPIXELS, ledPin, done);

// Define some colors with RGB values
uint32_t red = leds.Color(255, 0, 0);
uint32_t green = leds.Color(0, 255, 0);

// Initialize everything and prepare to start
void setup()
{ 
  leds.begin();
  leds.ColorSet(green);
  leds.Fade(red, green, 50, 100); // color1, color2, steps, interval
  leds.RainbowCycle(20);          // interval
  leds.Scanner(red, 50);          // color, interval
  leds.TheaterChase(red, green, 150);
}

// Main loop
void loop()
{
  leds.Update(); 
}

void done() {
  leds.Reverse();
}

