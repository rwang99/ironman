#include <Arduino.h>
#include <stdio.h>
#include <serial_interface.h>
#include <neopixel_blit.h>

#define NUM_LIGHTS 10
#define INIT_BRIGHTNESS 10
#define INCREMENT_BRIGHTNESS 2

#define SWITCH 21
#define LEFTBUTTON 4
#define RIGHTBUTTON 19

void setup() {
  init_neopixel_blit();
}

Pixels all_offs = {{0}};
int brightness = INIT_BRIGHTNESS;

void loop() {
  int i;
  Pixels pix = {{0}};

  if (digitalRead(SWITCH)){                 // Check if "on" switch is on before turning lights on
    for (i = 0; i<NUM_LIGHTS; i++){
      pix[i][PIX_RED] = brightness;
      pix[i][PIX_BLU] = brightness;
      pix[i][PIX_GRN] = brightness;
    } 
  } else {
    for (i = 0; i<NUM_LIGHTS; i++){
      pix[i][PIX_RED] = 0;
      pix[i][PIX_BLU] = 0;
      pix[i][PIX_GRN] = 0;
    } 
  }

  if (digitalRead(LEFTBUTTON) && brightness > 0){     // Allows you to change brightness with left or right button
    brightness -= INCREMENT_BRIGHTNESS;
    if (brightness < 0){
      brightness = 0; 
    }
  } else if (digitalRead(RIGHTBUTTON) && brightness < 255){
    brightness += INCREMENT_BRIGHTNESS;
    if (brightness > 255){
      brightness = 255; 
    }
  }
  
//  Serial.print("brightness: ");Serial.println(brightness);
  delay(30);
  neopixel_blit(pix); 
}
