// I'm trying to figure this whole thing out myself without looking anything up
// This likely isn't the most logical or best practices way of doing it

// Brown +
// Blue -
// Black interrupt

int analogPin = A3;

int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);

  if (val < 4) {
    Serial.println("Detect Magnet");
  } else {
    Serial.println ("No Magnet");
  }
  
 // Serial.println(val);
}
