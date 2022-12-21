#include <FastLED.h>

#define NUM_LEDS 120
#define LED_PIN 6
#define LED_FIRE 9
 
CRGB leds[NUM_LEDS];
 
uint8_t paletteIndex = 0;
int brightness = 0; 
 
DEFINE_GRADIENT_PALETTE ( heatmap_gp ) {
      0,    0,  0,  150,  // blu
    20,  100,  0,  255,  // violaceo
    60,  240, 0, 255,
    80,  255, 255,   0,  // giallo acceso
    150,  100, 100, 255,   // azzurro
    200,  255, 255, 0,   // sole
    220,  240, 130, 20,   // arancione
    255,  0, 0, 150,   // blu
};
 
CRGBPalette16 myPal = heatmap_gp;
 
void setup() {  
    pinMode(LED_FIRE, OUTPUT);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);   // up to 255
}
 
void loop() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, myPal, 255, LINEARBLEND);
 
  FastLED.show();
  
  EVERY_N_MILLISECONDS(200) {
    paletteIndex++;
  }
  if(paletteIndex%255 == 0){
    for(int i=0;i<500;i++){
        fire();
    }
    analogWrite(LED_FIRE,0);
  }
}


void fire(){
   brightness=random(10,255);
   analogWrite(LED_FIRE, brightness);
   delay(random(30,70));
  }
