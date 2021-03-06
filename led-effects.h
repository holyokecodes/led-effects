#ifndef ledEffects_h
#define ledEffects_h

/*
* Library adapted from https://learn.adafruit.com/multi-tasking-the-arduino-part-3/overview
*/

#include <Adafruit_NeoPixel.h>

// Pattern types supported:
enum  pattern { NONE, RAINBOW_CYCLE, THEATER_CHASE, COLOR_WIPE, SCANNER, FADE };
// Patern directions supported:
enum  direction { FORWARD, REVERSE };

class NeoPatterns : public Adafruit_NeoPixel
{
public:
    pattern  ActivePattern;  // which pattern is running
    direction Direction;     // direction to run the pattern
    
    unsigned long Interval;   // milliseconds between updates
    unsigned long lastUpdate; // last update of position
    
    uint32_t Color1, Color2;  // What colors are in use
    uint16_t TotalSteps;  // total number of steps in the pattern
    uint16_t Index;  // current step within the pattern
    
    void (*OnComplete)();  // Callback on completion of pattern

    NeoPatterns(uint16_t pixels, uint8_t pin, void (*callback)() = NULL, uint8_t type = NEO_GRB + NEO_KHZ800);

    void Update();
    void Increment();
    void Reverse();
    void RainbowCycle(uint8_t interval, direction dir = FORWARD);
    void RainbowCycleUpdate();
    void TheaterChase(uint32_t color1, uint32_t color2, uint8_t interval, direction dir = FORWARD);
    void TheaterChaseUpdate();
    void ColorWipe(uint32_t color, uint8_t interval, direction dir = FORWARD);
    void ColorWipeUpdate();
    void Scanner(uint32_t color1, uint8_t interval);
    void ScannerUpdate();
    void Fade(uint32_t color1, uint32_t color2, uint16_t steps, uint8_t interval, direction dir = FORWARD);
    void FadeUpdate();
    uint32_t DimColor(uint32_t color);
    void ColorSet(uint32_t color);
    uint8_t Red(uint32_t color);
    uint8_t Green(uint32_t color);
    uint8_t Blue(uint32_t color);
    uint32_t Wheel(byte WheelPos);
    
    int getDistance(int trigPin, int echoPin);
};

#endif