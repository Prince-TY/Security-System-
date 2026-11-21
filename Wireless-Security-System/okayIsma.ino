

const int sensors[] = {8, 9, 10, 13, 4, 5, 6, 7};

const int TRANSMITTER_PIN = 11;

int previous[8] = {
  HIGH, HIGH, HIGH, HIGH,
  HIGH, HIGH, HIGH, HIGH
};

bool transmitterActive = false;

unsigned long transmitterStartTime = 0;

const unsigned long TRANSMITTER_DURATION = 3000;

void setup() {

  Serial.begin(115200);

  for (int i = 0; i < 8; i++) {
    pinMode(sensors[i], INPUT_PULLUP);
  }

  pinMode(TRANSMITTER_PIN, OUTPUT);

  digitalWrite(TRANSMITTER_PIN, LOW);

  Serial.println("WIRELESS SECURITY SYSTEM STARTED");
  Serial.println("MONITORING 8 SENSORS");
  Serial.println("AREA SECURE");

}

void loop() {

  // Check all 8 sensors

  for (int i = 0; i < 8; i++) {

    int current = digitalRead(sensors[i]);

    // Detect a new motion event

    if (current == LOW && previous[i] == HIGH) {

      Serial.print("MOTION DETECTED: SENSOR ");
      Serial.println(i + 1);

      // Activate transmitter only if it is currently OFF

      if (transmitterActive == false) {

        digitalWrite(TRANSMITTER_PIN, HIGH);

        transmitterActive = true;

        transmitterStartTime = millis();

        Serial.println("WARNING: INTRUSION DETECTED");
        Serial.println("TRANSMITTER ON");

      }

    }

    previous[i] = current;

  }

  // Turn transmitter OFF after 2 seconds

  if (transmitterActive == true) {

    if (millis() - transmitterStartTime >= TRANSMITTER_DURATION) {

      digitalWrite(TRANSMITTER_PIN, LOW);

      transmitterActive = false;

      Serial.println("TRANSMITTER OFF");
      Serial.println("WAITING FOR NEW DETECTION");

    }

  }

}
