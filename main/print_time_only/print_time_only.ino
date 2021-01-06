#include "Nextion.h"

NexText avgmph = NexText(0, 4, "avgmph");
NexText timer = NexText(0, 5, "time");
NexText mph = NexText(0, 6, "mph");
NexText kph = NexText(0, 7, "avgmph");
//NexProgressBar percentSpeed = (0, 10, "percentSpeed");

void setup() {
  //This is for the serial monitor. Remove the // if you need to use it.
  Serial.begin(9600);
}

void loop(void) {
  unsigned long runMillis= millis();
  unsigned long allSeconds=millis()/1000;

  int secsRemaining=allSeconds%3600;
  int runMinutes=secsRemaining/60;
  int runSeconds=secsRemaining%60;

  if (digitalRead(7) == 0) {
    nexSerial.write(0xFF);
    nexSerial.write(0xFF);
    nexSerial.write(0xFF);
    avgmph.setText("Mag");
  } else {
    nexSerial.write(0xFF);
    nexSerial.write(0xFF);
    nexSerial.write(0xFF);
    avgmph.setText("no");
  }

  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);

  char buf[21];
  sprintf(buf,"%02d:%02d",runMinutes,runSeconds);
  timer.setText(buf);
  Serial.println(runMillis, "ms");
}
