/*
 Display all the fast rendering fonts.

 This sketch uses the GLCD (font 1) and fonts 2, 4, 6, 7, 8
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
*/

// New background colour
#define TFT_BROWN 0x38E0

// Pause in milliseconds between screens, change to 0 to time font rendering
#define WAIT 500

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

unsigned long targetTime = 0; // Used for testing draw times

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  targetTime = millis();

  // First we test them with a background colour set
  tft.setTextSize(1);
  tft.fillScreen(TFT_RED);
  tft.setTextColor(TFT_WHITE);

  tft.drawString("happy valentine's day", 0, 0, 4);
  tft.drawString("i love you so much", 0, 32, 4);
  tft.drawString("<3 <3 <3 <3 <3", 0, 52, 4);
  delay(WAIT);

  tft.fillScreen(TFT_PINK);
  tft.setTextColor(TFT_PURPLE);
  tft.drawString("happy valentine's day", 0, 0, 4);
  tft.drawString("i love you so much", 0, 32, 4);
  tft.drawString("<3 <3 <3 <3 <3", 0, 52, 4);
  delay(WAIT);

  tft.fillScreen(TFT_RED);
  tft.setTextColor(TFT_WHITE);
  tft.drawString("happy valentine's day", 0, 0, 4);
  tft.drawString("i love you so much", 0, 32, 4);
  tft.drawString("<3 <3 <3 <3 <3", 0, 52, 4);
  delay(WAIT);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_RED);
  tft.drawString("cupid xoxo", 0, 0, 4);
  tft.drawString("<3 <3 <3", 0, 32, 4);
  tft.drawString("heart eyes", 0, 52, 4);
  delay(WAIT);

  tft.fillScreen(TFT_PINK);
  tft.setTextColor(TFT_RED);
  
  tft.drawString("candy hearts", 0, 0, 4);
  tft.drawString("red roses", 0, 32, 4);
  delay(WAIT);
  
  tft.setTextColor(TFT_MAGENTA);
  delay(WAIT);

  // Now test them with transparent background
  targetTime = millis();

  tft.setTextSize(1);
  tft.fillScreen(TFT_PINK);
  tft.setTextColor(TFT_PURPLE);

  tft.drawString("happy valentine's day", 0, 0, 4);
  tft.drawString("i love you so much", 0, 32, 4);
  tft.drawString("<3 <3 <3 <3 <3", 0, 52, 4);
  delay(WAIT);

  tft.fillScreen(TFT_PURPLE);
  tft.setTextColor(TFT_WHITE);

  tft.drawString("sending love letter", 0, 0, 4);
  tft.drawString("you're my world", 0, 32, 4);
  tft.drawString("xoxoxooxo", 0, 52, 4);

  delay(WAIT);
  tft.fillScreen(TFT_RED);
   tft.setTextColor(TFT_PINK);
  tft.drawString("kisses to you", 0, 0, 4);
  tft.drawString("you're my world", 0, 32, 4);
  tft.drawString("xoxoxooxo", 0, 52, 4);
  delay(WAIT);

  tft.setTextColor(TFT_MAGENTA);
  delay(WAIT);
}
