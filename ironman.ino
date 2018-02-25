#include <Arduino.h>
#include <stdio.h>
#include <serial_interface.h>
#include <neopixel_blit.h>

#define NUM_LIGHTS 10
#define BRIGHTNESS 40

void setup() {
  
  init_neopixel_blit();
}

Pixels all_offs = {{0}};

void loop() {
  int i;
  Pixels pix = {{0}};

  for (i = 0; i<NUM_LIGHTS; i++){
    pix[i][PIX_RED] = BRIGHTNESS;
    pix[i][PIX_BLU] = BRIGHTNESS;
    pix[i][PIX_GRN] = BRIGHTNESS;
  } 
               
  neopixel_blit(pix); 
  delay(1000);
}
