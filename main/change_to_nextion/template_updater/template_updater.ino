#include "Nextion.h"

NexText avgmph = NexText(0, 4, "avgmph");
NexText timer = NexText(0, 5, "time");
NexText mph = NexText(0, 6, "mph");
NexText kph = NexText(0, 7, "avgmph");
//NexProgressBar percentSpeed = (0, 10, "percentSpeed");


unsigned long magPresent;
unsigned long magNonPresent;

float magElapsed;
float elapsedHr;
float mph1;
float mph2;
float milesPerTire;
float tireSizeIn = 83;

void setup() {
  Serial.begin(9600);
}

void loop(void) {


  unsigned long runMillis = millis();

  if (digitalRead(7) == 0) {
    magPresent = runMillis;
  }

  if (digitalRead(7) == 1) {
    magNonPresent = runMillis;
  }

  magElapsed = (magNonPresent - magPresent);
  
  elapsedHr = ((magElapsed/1000)/60)/60;
  milesPerTire = ((tireSizeIn/12)/5280);

  mph1 = milesPerTire/elapsedHr;
  
  mph2 = mph1;
  
  if (mph2 > mph1){
  mph2 = milesPerTire/elapsedHr;
  }

  Serial.print(magPresent);
  Serial.print(" time present,");
  Serial.print(magNonPresent);
  Serial.print(" time nonpresent, ");
  Serial.print(runMillis);
  Serial.print(" total time  ");
  Serial.print(magElapsed);
  Serial.print(" magElapsed to hour  ");
  Serial.println((mph2) );

//  char buf[21];
//  sprintf(buf, sizeof buf, mph2);
//
//   avgmph.setText(buf);
//   nexSerial.write(0xFF);
//   nexSerial.write(0xFF);
//   nexSerial.write(0xFF);
}


//mph = mag elapsed to seconds to minutes to hours 

// from inches to feet to miles

// only update when its 0 again
// dont update if > 50000

//1hr = 3,600,000 ms

//2.1m in 700c tire, 83 inches total

//every rotation is 83 inches

// mph = (0.001309974/(magElapsed/3600000))





  //  if (digitalRead(7) == 0) {
  //    Serial.println("Magnet");
  //
  //    while(digitalRead(7) == 0){
  //      gap1 = 200;
  //    }
  //
  //  } else {
  //    //Serial.println(runMillis);
  //    Serial.println(gap1);
  //  }
  //
  //


//}

//
//
//
//
//#include "Nextion.h"
//
//NexText avgmph = NexText(0, 4, "avgmph");
//NexText timer = NexText(0, 5, "time");
//NexText mph = NexText(0, 6, "mph");
//NexText kph = NexText(0, 7, "avgmph");
////NexProgressBar percentSpeed = (0, 10, "percentSpeed");
//
//void setup() {
//  //This is for the serial monitor. Remove the // if you need to use it.
//  Serial.begin(9600);
//}
//
//void loop(void) {
//  unsigned long runMillis= millis();
//  unsigned long allSeconds=millis()/1000;
//
//  int secsRemaining=allSeconds%3600;
//  int runMinutes=secsRemaining/60;
//  int runSeconds=secsRemaining%60;
//
//  if (digitalRead(7) == 0) {
//    nexSerial.write(0xFF);
//    nexSerial.write(0xFF);
//    nexSerial.write(0xFF);
//    avgmph.setText("Mag");
//  } else {
//    nexSerial.write(0xFF);
//    nexSerial.write(0xFF);
//    nexSerial.write(0xFF);
//    avgmph.setText("no");
//  }
//
//  nexSerial.write(0xFF);
//  nexSerial.write(0xFF);
//  nexSerial.write(0xFF);
//
//  char buf[21];
//  sprintf(buf,"%02d:%02d",runMinutes,runSeconds);
//  timer.setText(buf);
//  Serial.println(runMillis, "ms");
//}
