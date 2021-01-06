#include "Nextion.h"

const byte ReedPin = 11; // pin connected to reed switch
const float WheelRadius = 0.00131;// the wheel radius in miles
const float WheelCircumference = 2 * PI * WheelRadius;
const float MPHconst = WheelCircumference * 3600000.0; // Killometers per hour at 1 revolution per millisecond.

float elapsedHr;

NexText avgmph = NexText(0, 4, "avgmph");
NexText timer = NexText(0, 5, "time");
NexText mph = NexText(0, 6, "mph");
NexText kph = NexText(0, 7, "kph");

const unsigned DebounceTime = 10;  // Milliseconds of bouncing to ignore

unsigned TickCounter = 0;
volatile float totalVelocity = 0;
volatile float avgMph = 0;
volatile int totalTick = 0;

// Shared with the ISR.  Must mark as 'volatile' so the compiler knows
// they can change at any time
volatile float CurrentVelocity = 0.00; // mph
volatile float TotalDistance = 0.00; // km

void setup()
{
  Serial.begin(9600);
  pinMode(ReedPin, INPUT);
  noInterrupts();

  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// set entire TCCR1B register to 0
  TCNT1  = 0;// initialize counter value to 0
  TCCR1B |= (1 << WGM12);// set to Waveform Generation Mode 4 (CTC mode, TOP is in OCR1A)
  OCR1A = 1999;// set TOP for 1kHz interrupts  = (16*10^6) / (1000*8) - 1
  TCCR1B |= (1 << CS11);  // Set CS11 bit for 8 prescaler (2 MHz clock)
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt

  interrupts();
}

void loop()
{
  displayText();

  delay(100);
}

// Interrupt occurs every millisecond
ISR(TIMER1_COMPA_vect)
{
  static unsigned long lastStateChangeTime = 0;
  static boolean reedWasClosed = false;

  unsigned long currentTime = millis();

  
  boolean reedIsClosed = digitalRead(ReedPin);

  // Check for state change
  if (reedIsClosed != reedWasClosed && currentTime - lastStateChangeTime > DebounceTime)
  {
    reedWasClosed = reedIsClosed;
    lastStateChangeTime = currentTime;
    if (reedIsClosed)
    {
      // Reed Has Just Closed
      TotalDistance += WheelCircumference;
      
      // KPHconst is KPH at 1 revolution per tick.
      CurrentVelocity = MPHconst / TickCounter;
      if (CurrentVelocity < 100)
      {
        totalVelocity += CurrentVelocity;
        totalTick += 1;
        avgMph = totalVelocity / totalTick;
      }
      
      TickCounter = 0;
    }
  }

  if (TickCounter > 4000)// Count milliseconds unless the wheel has stopped
  {
    CurrentVelocity = 0;// set velocity to 0 when tire is still for 4 seconds - 2 seconds had a low speed of 14.8mph
    //totalTick += 1;
  }
  else
  {
    TickCounter++;
  }
}


void displayText()
{
  // Because 'volatile' variables can change any time interrupts are enabled
  // we have to make local copies while interrupts are disables.  If we don't
  // the value of the variable might change half-way thourgh fetching!

  unsigned long allSeconds=millis()/1000; //time calculation variables, these get placed here because if they are outside
  int secsRemaining=allSeconds%3600;      //of a loop or looped function they will never update
  int runMinutes=secsRemaining/60;
  int runSeconds=secsRemaining%60;


  float localTotalDistance;
  float localCurrentVelocity;
  float localCurrentVelocityK;
  float localAvgMph;
  
  noInterrupts();
  localTotalDistance = TotalDistance;
  localCurrentVelocity = CurrentVelocity;
  localCurrentVelocityK = CurrentVelocity * 1.60934;
  localAvgMph = avgMph;
  interrupts();


  //  Serial.print(int(localCurrentVelocity));
  //  Serial.println(" km/h");
  //
   if (TotalDistance > 1) {
    Serial.print(localTotalDistance);
     Serial.println(" km");
   }
    else {
     Serial.print(int(localTotalDistance * 1000.0));
     Serial.println(" m");
 }

//time elapsed
  char elapsed[21];
  sprintf(elapsed,"%02d:%02d",runMinutes,runSeconds);  
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  timer.setText(elapsed);

//avgmph
  char speedoAvg[4];
  dtostrf(localAvgMph, 4, 1, speedoAvg);
  Serial.println(localCurrentVelocity);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  avgmph.setText(speedoAvg);


//mph
  char speedoM[4];
  dtostrf(localCurrentVelocity, 4, 1, speedoM);
  Serial.println(localCurrentVelocity);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  mph.setText(speedoM);

//kph
  char speedoK[4];
  dtostrf(localCurrentVelocityK, 4, 1, speedoK);
  Serial.println(localCurrentVelocityK);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  nexSerial.write(0xFF);
  kph.setText(speedoK);
}
