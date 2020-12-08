#include "Ucglib.h"  // Include Ucglib library to drive the display
Ucglib_ILI9341_18x240x320_HWSPI ucg(9, 10, 8);  // (A0=9, CS=10, RESET=8)

int MagYesNo;  // Create a variable to have something dynamic to show on the display
int MagCount;
int Dist;

void setup(void)  // Start of setup
{

  Serial.begin(9600);
  
  ucg.begin(UCG_FONT_MODE_SOLID);  // It writes a background for the text. This is the recommended option
  ucg.clearScreen();  // Clear the screen
  ucg.setFont(ucg_font_inr38_mr);

}  // End of setup

void loop(void)  // Start of loop
{
  //my code for magnet serial output
  if (digitalRead(7) == 0) {
    Serial.println("Magnet");
    MagYesNo = 1;
    MagCount ++;
  } else {
    Serial.println("No Magnet");
    MagYesNo = 0;
  }

//  Dist = MagCount * (85.75/12);
 
  // Write to the display the Variable1 with left text alignment:
//  ucg.setFont(ucg_font_inb30_mr);  // Set font
//  ucg.setColor(0, 255, 255, 0);  // Set color (0,R,G,B)

//  ucg.setPrintPos(10,50);  // Set position (x,y)
//  ucg.print(MagYesNo);  // Print text or value
  
  ucg.setPrintPos(0,100);  // Set position (x,y)
  ucg.print(MagCount);  // Print text or value

//  ucg.setPrintPos(0,150);  // Set position (x,y)
//  ucg.print(Dist);  // Print text or value


}  // End of loop
