#include <led-effects.h>

#define ledPin 6 
#define NUMPIXELS 12

#define echoPin 8 // Echo Pin
#define trigPin 9 // Trigger Pin
#define maxRange 50 // Maximum range needed

NeoPatterns leds(NUMPIXELS, ledPin);

// Define some colors with RGB values
uint32_t red = leds.Color(255, 0, 0);
uint32_t green = leds.Color(0, 255, 0);

// Initialize everything and prepare to start
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  leds.begin();
}

// Main loop
void loop()
{
  int distance = leds.getDistance(trigPin, echoPin);
  Serial.println(distance);

  if (distance >= maxRange){
      // This is the default action
      
      // Fade from Color1 to Color2
      leds.ActivePattern = FADE;
      leds.Color1 = red;
      leds.Color2 = green;
      leds.Interval = 50;
      leds.TotalSteps = 100;

      // Nice rainbow pattern!
      //leds.ActivePattern = RAINBOW_CYCLE;
      //leds.Interval = 10;
      //leds.TotalSteps = 255;
      
      // Another color chase pattern
      //leds.ActivePattern = THEATER_CHASE;
      //leds.Color1 = red;
      //leds.Color2 = green;
      //leds.Interval = 150;
      //leds.TotalSteps = NUMPIXELS;

      // Wipe to a solid color
      //leds.ActivePattern = COLOR_WIPE;
      //leds.Interval = 50;
      //leds.TotalSteps = NUMPIXELS;
      //leds.Color1 = red;
  } else {
      // This pattern happens when you get closer than maxRange distance
      leds.ActivePattern = SCANNER;
      leds.Interval = 20;
      leds.TotalSteps = 20;
      leds.Color1 = green;
 }
 leds.Update(); 
}
