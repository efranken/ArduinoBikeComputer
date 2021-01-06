
#include "SPI.h"




void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 

}

void loop(void) {

      if (digitalRead(7) == 0) {
    Serial.println("Magnet");
    //Variable1 = 1;
  } else {
    //Variable1 = 0;
    Serial.println("No Magnet");
  }



//  tft.reset();

}
