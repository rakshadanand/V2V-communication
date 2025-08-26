
// LiFi V2V Receiver (manual style)
// NOTE: simple test version - needs fine tuning

int ldrPin = A0;  // photodiode/ldr input
int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // for debug only
}

void loop() {
  int sensorVal = analogRead(ldrPin);

  if (sensorVal > 500) { // crude threshold test
    digitalWrite(buzzerPin, HIGH); // alarm ON
    Serial.println("Braking signal detected!");
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(50);
}
