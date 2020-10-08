// I'm trying to figure this whole thing out myself without looking anything up
// This likely isn't the most logical or best practices way of doing it
// Copied from main.sh
// Trying digital out

// Brown +
// Blue -
// Black interrupt

//int analogPin = A3;

//int val = 0;

//int digitalPin = D12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(digitalRead(12));
  //val = analogRead(analogPin);

  //Serial.println(val);

  //if (val < 4) {
  //  Serial.println("Detect Magnet");
  //} else {
  //  Serial.println ("No Magnet");
  //}
  
 // Serial.println(val);
}
