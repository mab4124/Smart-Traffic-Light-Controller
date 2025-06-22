// Smart Traffic Light Controller with Pedestrian and Emergency Override

// Pin definitions
const int redA = 2;
const int yellowA = 3;
const int greenA = 4;

const int redB = 5;
const int yellowB = 6;
const int greenB = 7;

const int redC = 8;
const int yellowC = 9;
const int greenC = 10;

const int redD = 11;
const int yellowD = 12;
const int greenD = 13;

const int pedestrianButtonPin = A0;  // Pedestrian button input (active LOW)
const int emergencySensorPin = A1;   // Emergency vehicle sensor (active LOW)
const int pedestrianGreen = A2;      // Pedestrian green LED (optional)
const int buzzerPin = A3;             // Buzzer pin (optional)

bool pedestrianRequest = false;
bool emergencyActive = false;

void setup() {
  // Initialize LED pins
  for (int pin = 2; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }
  // Initialize control pins
  pinMode(pedestrianButtonPin, INPUT_PULLUP);
  pinMode(emergencySensorPin, INPUT_PULLUP);
  pinMode(pedestrianGreen, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  allRed();
}

void loop() {
  emergencyActive = (digitalRead(emergencySensorPin) == LOW);
  pedestrianRequest = (digitalRead(pedestrianButtonPin) == LOW);

  if (emergencyActive) {
    emergencyOverride();
  } else if (pedestrianRequest) {
    pedestrianPhase();
  } else {
    normalSequence();
  }
}

void allRed() {
  for (int pin = 2; pin <= 13; pin++) {
    digitalWrite(pin, LOW);
  }
  digitalWrite(redA, HIGH);
  digitalWrite(redB, HIGH);
  digitalWrite(redC, HIGH);
  digitalWrite(redD, HIGH);
  digitalWrite(pedestrianGreen, LOW);
  noTone(buzzerPin);
}

void activateGreenPhase(int redPin, int yellowPin, int greenPin) {
  allRed();
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(4000);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(1000);
}

void normalSequence() {
  activateGreenPhase(redA, yellowA, greenA);
  activateGreenPhase(redB, yellowB, greenB);
  activateGreenPhase(redC, yellowC, greenC);
  activateGreenPhase(redD, yellowD, greenD);
}

void pedestrianPhase() {
  allRed();
  digitalWrite(pedestrianGreen, HIGH);
  tone(buzzerPin, 1000); // buzzer on
  delay(7000);

  // Blink pedestrian green LED warning
  for (int i = 0; i < 6; i++) {
    digitalWrite(pedestrianGreen, LOW);
    delay(500);
    digitalWrite(pedestrianGreen, HIGH);
    delay(500);
  }
  digitalWrite(pedestrianGreen, LOW);
  noTone(buzzerPin);
}

void emergencyOverride() {
  allRed();
  // Assume direction A is emergency lane for demo
  digitalWrite(redB, HIGH);
  digitalWrite(redC, HIGH);
  digitalWrite(redD, HIGH);
  digitalWrite(redA, LOW);
  digitalWrite(greenA, HIGH);
  tone(buzzerPin, 2000);
  delay(10000); // emergency green duration
  noTone(buzzerPin);
  allRed();
}
