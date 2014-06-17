
/*
 * To use this sketch, connect the eight pins from your LCD like thus:
 *
 * Pin 1 -> +3.3V (rightmost, when facing the display head-on)
 * Pin 2 -> Arduino digital pin 3
 * Pin 3 -> Arduino digital pin 4
 * Pin 4 -> Arduino digital pin 5
 * Pin 5 -> Arduino digital pin 7
 * Pin 6 -> Ground
 * Pin 7 -> 10uF capacitor -> Ground
 * Pin 8 -> Arduino digital pin 6
 *
 * Since these LCDs are +3.3V devices, you have to add extra components to
 * connect it to the digital pins of the Arduino (not necessary if you are
 * using a 3.3V variant of the Arduino, such as Sparkfun's Arduino Pro).
 */


/* sclk  = 0,   /* clock       (display pin 2) */
/*sdin  = 1,   /* data-in     (display pin 3) */
/*dc    = 2,   /* data select (display pin 4) */
/*reset = 5,   /* reset       (display pin 8) */
/*sce   = GND  /* enable      (display pin 5) */

#include <PCD8544.h>
#include <DigiUSB.h>

// A custom glyph (a smiley)...
static const byte glyph[] = { 
  B00010000, B00110100, B00110000, B00110100, B00010000 };


static PCD8544 lcd;


void setup() {
  DigiUSB.begin();
  // PCD8544-compatible displays may have a different resolution...
  lcd.begin(84, 48);

  // Add the smiley to position "0" of the ASCII table...
  lcd.createChar(0, glyph);
}


void loop() {
  // Just to show the program is alive...
  static int counter = 0;
  int lastRead;
  // Write a piece of text on the first line...
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  if(DigiUSB.available()){
    lastRead = DigiUSB.read();
    lcd.write(lastRead);
  }
  // Write the counter on the second line...

DigiUSB.delay(100);
}


/* EOF - HelloWorld.ino */


