
/***************************************************
  This is our GFX example for the Adafruit ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/
//#define ILI9341_BLACK       0x0000  ///<   0,   0,   0
//#define ILI9341_NAVY        0x000F  ///<   0,   0, 123
//#define ILI9341_DARKGREEN   0x03E0  ///<   0, 125,   0
//#define ILI9341_DARKCYAN    0x03EF  ///<   0, 125, 123
//#define ILI9341_MAROON      0x7800  ///< 123,   0,   0
//#define ILI9341_PURPLE      0x780F  ///< 123,   0, 123
//#define ILI9341_OLIVE       0x7BE0  ///< 123, 125,   0
//#define ILI9341_LIGHTGREY   0xC618  ///< 198, 195, 198
//#define ILI9341_DARKGREY    0x7BEF  ///< 123, 125, 123
//#define ILI9341_BLUE        0x001F  ///<   0,   0, 255
//#define ILI9341_GREEN       0x07E0  ///<   0, 255,   0
//#define ILI9341_CYAN        0x07FF  ///<   0, 255, 255
//#define ILI9341_RED         0xF800  ///< 255,   0,   0
//#define ILI9341_MAGENTA     0xF81F  ///< 255,   0, 255
//#define ILI9341_YELLOW      0xFFE0  ///< 255, 255,   0
//#define ILI9341_WHITE       0xFFFF  ///< 255, 255, 255
//#define ILI9341_ORANGE      0xFD20  ///< 255, 165,   0
//#define ILI9341_GREENYELLOW 0xAFE5  ///< 173, 255,  41
//#define ILI9341_PINK        0xFC18  ///< 255, 130, 198

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the Adafruit shield, these are the default.
#define TFT_MISO 12
#define TFT_CLK 13
#define TFT_MOSI 11
#define TFT_DC 9
#define TFT_RST 8
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();
//
//  // read diagnostics (optional but can help debug problems)
//  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
//  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
//  x = tft.readcommand8(ILI9341_RDMADCTL);
//  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
//  x = tft.readcommand8(ILI9341_RDPIXFMT);
//  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
//  x = tft.readcommand8(ILI9341_RDIMGFMT);
//  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
//  x = tft.readcommand8(ILI9341_RDSELFDIAG);
//  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
}

void loop(void) {

      if (digitalRead(7) == 0) {
    Serial.println("Magnet");
    //Variable1 = 1;
  } else {
    //Variable1 = 0;
    Serial.println("No Magnet");
  }
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(2);
  tft.println("my foonting turlingdromes.");
  tft.println("And hooptiously drangle me");
  tft.println("with crinkly bindlewurdles,");
  tft.println("Or I will rend thee");
  tft.println("in the gobberwarts");
  tft.println("with my blurglecruncheon,");
  tft.println("see if I don't!");
  delay(5000);
//  tft.reset();

}
