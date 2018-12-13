#include <led-effects.h>

#define ledPin 6 
#define NUMPIXELS 12

void done();

NeoPatterns leds(NUMPIXELS, ledPin, done);

// Define some colors with RGB values
uint32_t red = leds.Color(255, 0, 0);
uint32_t blue = leds.Color(0, 0, 255);

// Initialize everything and prepare to start
void setup()
{ 
  leds.begin();
}

// Main loop
void loop()
{
  // Fade from Color1 to Color2
  leds.ActivePattern = FADE;
  leds.Color1 = red;
  leds.Color2 = blue;
  leds.Interval = 100;
  leds.TotalSteps = 100;
  leds.Update(); 
}

void done() {
  leds.Reverse();
}