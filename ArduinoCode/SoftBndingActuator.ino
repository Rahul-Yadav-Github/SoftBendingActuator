// SoftBendingActuator.ino

// Define the pins connected to the relay module
#define RELAY_PIN_1 2 // Relay control pin for valve 1
#define RELAY_PIN_2 3 // Relay control pin for valve 2

// Define the analog pin connected to the flex sensor
#define FLEX_SENSOR_PIN A0

// Define the range of the sensor values (calibration required)
#define SENSOR_MIN 600   // Minimum sensor value (adjust based on calibration)
#define SENSOR_MAX 900   // Maximum sensor value (adjust based on calibration)

// Define the range of the angle values
#define ANGLE_MIN 0      // Minimum angle in degrees
#define ANGLE_MAX 90     // Maximum angle in degrees

void setup() {
  // Initialize relay control pins as outputs
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the flex sensor
  int sensorValue = analogRead(FLEX_SENSOR_PIN);

  // Map the sensor value to an angle
  int angle = map(sensorValue, SENSOR_MIN, SENSOR_MAX, ANGLE_MIN, ANGLE_MAX);

  // Print the sensor value and the corresponding angle
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" - Angle: ");
  Serial.println(angle);

  // Example control logic based on the angle
  if (angle < 30) {
    // Open Valve 1 and close Valve 2
    digitalWrite(RELAY_PIN_1, HIGH);
    digitalWrite(RELAY_PIN_2, LOW);
  } else if (angle > 60) {
    // Close Valve 1 and open Valve 2
    digitalWrite(RELAY_PIN_1, LOW);
    digitalWrite(RELAY_PIN_2, HIGH);
  } else {
    // Close both valves
    digitalWrite(RELAY_PIN_1, LOW);
    digitalWrite(RELAY_PIN_2, LOW);
  }

  // Wait for 100 milliseconds before the next reading
  delay(100);
}
