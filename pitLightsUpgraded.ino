
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 60
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
const int pinOne = 2;
const int pinTwo = 4;
const int pinThree = 7;
bool arr[60];

void setup() {
  //makeArrayFalse();
  pinMode(pinOne, INPUT);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// *** REPLACE FROM HERE ***
void loop() {
  
  colorWipe(0x00,0xff,0x00, 50);
}



void colorWipe(byte red, byte green, byte blue, int SpeedDelay) {
  if (digitalRead(pinOne)== HIGH){
   button1(0,0xFF,0);
   showStrip();
  }else if (digitalRead(pinTwo)==HIGH){
    button2(0xFE,0x50,0);
    showStrip();
 }else if (digitalRead(pinThree)==HIGH) {
   button3(0xFF,0,0);
   showStrip();
 }
 else{
   setAll(0,0,0);
   showStrip();
 }

  }
// *** REPLACE TO HERE ***

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

int on1 = 0;
void button1(byte red, byte green, byte blue) {

  for(int i = 0; i < NUM_LEDS; i++ ) {
    if(on1> 100)
      setPixel(i, red, green, blue); 
    else
      setPixel(i, 0, 0, 0);
  }
  on1++;
  if(on1 >200)
  on1 = 0;

  showStrip();
}

int on2 = 0;
void button2(byte red, byte green, byte blue) {

  for(int i = 0; i < NUM_LEDS; i++ ) {
    if(on2> 50)
      setPixel(i, red, green, blue); 
    else
      setPixel(i, 0, 0, 0);    
  }
  on2++;
  if(on2 >100)
  on2 = 0;
  
  showStrip();
}

int on3 = 0;
void button3(byte red, byte green, byte blue) {

  for(int i = 0; i < NUM_LEDS; i++ ) {
    if(on3> 25)
      setPixel(i, red, green, blue);
    else
      setPixel(i, 0, 0, 0);
  }
  on3++;
  if(on3 > 50)
    on3 = 0;

  showStrip();
}
void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}