

const int SENSOR1_PIN = 8;
const int SENSOR2_PIN = 9;
const int SENSOR3_PIN = 10;
const int SENSOR4_PIN = 13;
const int SENSOR5_PIN = 4;
const int SENSOR6_PIN = 5;
const int SENSOR7_PIN = 6;
const int SENSOR8_PIN = 7;

const int TRANSMITTER_PIN = 11;

int value1;
int value2;
int value3;
int value4;
int value5;
int value6;
int value7;
int value8;

int previous1 = HIGH;
int previous2 = HIGH;
int previous3 = HIGH;
int previous4 = HIGH;
int previous5 = HIGH;
int previous6 = HIGH;
int previous7 = HIGH;
int previous8 = HIGH;

void setup() {

  Serial.begin(9600);

  pinMode(SENSOR1_PIN, INPUT_PULLUP);
  pinMode(SENSOR2_PIN, INPUT_PULLUP);
  pinMode(SENSOR3_PIN, INPUT_PULLUP);
  pinMode(SENSOR4_PIN, INPUT_PULLUP);
  pinMode(SENSOR5_PIN, INPUT_PULLUP);
  pinMode(SENSOR6_PIN, INPUT_PULLUP);
  pinMode(SENSOR7_PIN, INPUT_PULLUP);
  pinMode(SENSOR8_PIN, INPUT_PULLUP);

  pinMode(TRANSMITTER_PIN, OUTPUT);

  digitalWrite(TRANSMITTER_PIN, LOW);

  Serial.println("================================");
  Serial.println("WIRELESS SECURITY SYSTEM STARTED");
  Serial.println("Monitoring 8 sensors...");
  Serial.println("================================");

  delay(1000);
}

void loop() {

  // Read all sensors

  value1 = digitalRead(SENSOR1_PIN);
  value2 = digitalRead(SENSOR2_PIN);
  value3 = digitalRead(SENSOR3_PIN);
  value4 = digitalRead(SENSOR4_PIN);
  value5 = digitalRead(SENSOR5_PIN);
  value6 = digitalRead(SENSOR6_PIN);
  value7 = digitalRead(SENSOR7_PIN);
  value8 = digitalRead(SENSOR8_PIN);

  // Check if any sensor detects motion

  int motionDetected = 0;

  if (value1 == LOW ||
      value2 == LOW ||
      value3 == LOW ||
      value4 == LOW ||
      value5 == LOW ||
      value6 == LOW ||
      value7 == LOW ||
      value8 == LOW) {

    motionDetected = 1;
  }

  // Detect newly triggered sensors

  if (value1 == LOW && previous1 == HIGH) {
    Serial.println("MOTION DETECTED: SENSOR 1");
  }

  if (value2 == LOW && previous2 == HIGH) {
    Serial.println("MOTION DETECTED: SENSOR 2");
  }

  if (value3 == LOW && previous3 == HIGH) {
    Serial.println("MOTION DETECTED: SENSOR 3");
  }

  if (value4 == LOW && previous4 == HIGH) {
    Serial.println("MOTION DETECTED: SENSOR 4");
  }

  if (value5 == LOW && previous5 == HIGH) {
    Serial.println("MOTION DETECTED: SENSOR 5");
  }

  if (value6 == LOW && previous6 == HIGH) {
    Serial.println("MOTION DETECTED: SENSOR 6");
  }

  if (value7 == LOW && previous7 == HIGH) {
    Serial.println("MOTION DETECTED: SENSOR 7");
  }

  if (value8 == LOW && previous8 == HIGH) {
    Serial.println("MOTION DETECTED: SENSOR 8");
  }

  // Control wireless transmitter

  if (motionDetected == 1) {

    digitalWrite(TRANSMITTER_PIN, LOW);

  } else {

    digitalWrite(TRANSMITTER_PIN, 1);

  }

  // Save previous sensor states

  previous1 = value1;
  previous2 = value2;
  previous3 = value3;
  previous4 = value4;
  previous5 = value5;
  previous6 = value6;
  previous7 = value7;
  previous8 = value8;

  delay(100);
}
