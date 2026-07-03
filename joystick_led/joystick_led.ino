// Joystick-controlled 4-LED direction indicator
// Arduino UNO

const int VRX_PIN = A0;   // Joystick X-axis (Left/Right)
const int VRY_PIN = A1;   // Joystick Y-axis (Up/Down)

const int LED_UP    = 8;  // LED 1 - Up
const int LED_DOWN  = 9;  // LED 2 - Down
const int LED_LEFT  = 10; // LED 3 - Left
const int LED_RIGHT = 11; // LED 4 - Right

const int THRESHOLD_HIGH = 700; // above this = pushed one way
const int THRESHOLD_LOW  = 300; // below this = pushed other way
// Center rest value is ~512 on a 10-bit ADC (0-1023)

void setup() {
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  Serial.begin(9600); // for debugging raw joystick values
}

void loop() {
  int xVal = analogRead(VRX_PIN);
  int yVal = analogRead(VRY_PIN);

  // Reset all LEDs each loop
  digitalWrite(LED_UP, LOW);
  digitalWrite(LED_DOWN, LOW);
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_RIGHT, LOW);

  // Y-axis controls Up/Down
  if (yVal > THRESHOLD_HIGH) {
    digitalWrite(LED_UP, HIGH);
  } else if (yVal < THRESHOLD_LOW) {
    digitalWrite(LED_DOWN, HIGH);
  }

  // X-axis controls Left/Right
  if (xVal > THRESHOLD_HIGH) {
    digitalWrite(LED_RIGHT, HIGH);
  } else if (xVal < THRESHOLD_LOW) {
    digitalWrite(LED_LEFT, HIGH);
  }

  Serial.print("X: "); Serial.print(xVal);
  Serial.print(" | Y: "); Serial.println(yVal);

  delay(50); // small debounce/smoothing
}
