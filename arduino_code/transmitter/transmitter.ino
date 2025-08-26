
// LiFi V2V Transmitter (manual style)
// NOTE: testing version - may need tweaking for LED brightness

int ledPin = 9;  // tx led pin
int brakePin1 = 7; // simulate brake signal

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(brakePin1, INPUT);
}

void loop() {
  int brakeState = digitalRead(brakePin1);

  if (brakeState == HIGH) {
    // send braking signal
    digitalWrite(ledPin, HIGH);
    delay(100); // basic delay for demo
    digitalWrite(ledPin, LOW);
    delay(100);
  } else {
    // idle state (nothing)
    digitalWrite(ledPin, LOW);
  }
}
