/*****************************************************************************************
 *                              SMART HOME AUTOMATION SYSTEM
 *----------------------------------------------------------------------------------------
 * Project Description:
 * This project demonstrates a simple Smart Home Automation System using Arduino UNO.
 * Different sensors are used to automate various home appliances and safety features.
 *
 * Components Used:
 * 1. Arduino UNO
 * 2. LDR Sensor (Automatic Light Control)
 * 3. MQ Gas Sensor (Gas Leakage Detection)
 * 4. PIR Motion Sensor (Motion Detection)
 * 5. HC-SR04 Ultrasonic Sensor (Automatic Door)
 * 6. Servo Motor
 * 7. Relay Module (Bulb Control)
 * 8. DC Motor (Fan)
 * 9. Piezo Buzzer
 * 10. Red LED
 * 11. Green LED
 *
 * Developed Using:
 * Arduino IDE
 * Tinkercad Circuit Simulator
 *
 *****************************************************************************************/

#include <Servo.h>     // Include Servo Motor Library

//----------------------------------------------------------------------------------------
// Variable Declaration
//----------------------------------------------------------------------------------------

int output1Value = 0;          // Reserved variable (currently unused)
int sen1Value = 0;             // Stores Ultrasonic Sensor distance
int sen2Value = 0;             // Stores PIR Motion Sensor value

// Analog Sensor Pins
const int gas_sensor = A1;     // MQ Gas Sensor connected to Analog Pin A1
const int LDR = A0;            // LDR Sensor connected to Analog Pin A0

// Gas Sensor Threshold Value
int limit = 400;

//----------------------------------------------------------------------------------------
// Ultrasonic Sensor Function
//----------------------------------------------------------------------------------------
// This function sends an ultrasonic pulse and returns the echo time.
// The returned value is later converted into distance (cm).
//----------------------------------------------------------------------------------------

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);

  // Clear Trigger Pin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // Send 10µs Trigger Pulse
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Configure Echo Pin as Input
  pinMode(echoPin, INPUT);

  // Read Echo Pulse Duration
  return pulseIn(echoPin, HIGH);
}

//----------------------------------------------------------------------------------------
// Servo Object
//----------------------------------------------------------------------------------------

Servo servo_7;

//----------------------------------------------------------------------------------------
// Setup Function
//----------------------------------------------------------------------------------------

void setup()
{
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Configure Analog Inputs
  pinMode(A0, INPUT);          // LDR Sensor
  pinMode(A1, INPUT);          // Gas Sensor

  // Relay Output (Bulb Control)
  pinMode(13, OUTPUT);

  // Attach Servo Motor to Digital Pin 7
  servo_7.attach(7, 500, 2500);

  // Buzzer Output
  pinMode(8, OUTPUT);

  // PIR Motion Sensor Input
  pinMode(9, INPUT);

  // DC Motor (through NPN Transistor)
  pinMode(10, OUTPUT);

  // Status LEDs
  pinMode(4, OUTPUT);          // Red LED
  pinMode(3, OUTPUT);          // Green LED
}

//----------------------------------------------------------------------------------------
// Main Program Loop
//----------------------------------------------------------------------------------------

void loop()
{

  //==============================================================================
  // SECTION 1 : AUTOMATIC LIGHT CONTROL USING LDR
  //==============================================================================

  // Read LDR Value
  int val1 = analogRead(LDR);

  // If surrounding light is low
  if (val1 > 500)
  {
    digitalWrite(13, LOW);     // Turn ON Relay (Bulb ON)

    Serial.print("Bulb ON = ");
    Serial.print(val1);
  }

  // If surrounding light is sufficient
  else
  {
    digitalWrite(13, HIGH);    // Turn OFF Relay (Bulb OFF)

    Serial.print("Bulb OFF = ");
    Serial.print(val1);
  }

  //==============================================================================
  // SECTION 2 : MOTION DETECTION USING PIR SENSOR
  //==============================================================================

  // Read PIR Sensor
  sen2Value = digitalRead(9);

  // No Motion Detected
  if (sen2Value == 0)
  {
    digitalWrite(10, LOW);     // Turn OFF Fan (DC Motor)

    digitalWrite(4, HIGH);     // Red LED ON

    digitalWrite(3, LOW);      // Green LED OFF

    Serial.print("     || NO Motion Detected");
  }

  // Motion Detected
  if (sen2Value == 1)
  {
    digitalWrite(10, HIGH);    // Turn ON Fan

    delay(3000);               // Keep Fan Running for 3 Seconds

    digitalWrite(4, LOW);      // Red LED OFF

    digitalWrite(3, HIGH);     // Green LED ON

    Serial.print("     || Motion Detected!");
  }

  delay(300);

  //==============================================================================
  // SECTION 3 : GAS LEAKAGE DETECTION
  //==============================================================================

  // Read MQ Gas Sensor Value
  int val = analogRead(gas_sensor);

  Serial.print(" || Gas Sensor Value = ");
  Serial.print(val);

  // If Gas Level Exceeds Threshold
  if (val > limit)
  {
    tone(8, 650);              // Activate Buzzer
  }

  delay(300);

  // Stop Buzzer
  noTone(8);

  //==============================================================================
  // SECTION 4 : AUTOMATIC DOOR USING ULTRASONIC SENSOR
  //==============================================================================

  // Convert Echo Time into Distance (cm)
  sen1Value = 0.01723 * readUltrasonicDistance(6, 6);

  // Object Detected Near Door
  if (sen1Value < 100)
  {
    servo_7.write(90);         // Open Door

    Serial.print("     || Door Open!  ; Distance = ");
    Serial.print(sen1Value);

    Serial.print("\n");
  }

  // No Object Near Door
  else
  {
    servo_7.write(0);          // Close Door

    Serial.print("     || Door Closed! ; Distance = ");
    Serial.print(sen1Value);

    Serial.print("\n");
  }

  // Small Delay for Stable Operation
  delay(10);
}

/*****************************************************************************************
 *
 *                              END OF PROGRAM
 *
 *----------------------------------------------------------------------------------------
 * Functional Summary:
 *
 * 1. LDR Sensor
 *    -> Automatically controls the room light using a relay.
 *
 * 2. PIR Motion Sensor
 *    -> Detects human movement.
 *    -> Turns ON the fan (DC Motor).
 *    -> Green LED indicates motion.
 *    -> Red LED indicates no motion.
 *
 * 3. MQ Gas Sensor
 *    -> Detects gas leakage.
 *    -> Activates the buzzer when gas level exceeds the threshold.
 *
 * 4. Ultrasonic Sensor
 *    -> Detects nearby objects.
 *    -> Opens the door using a servo motor.
 *    -> Closes the door when no object is nearby.
 *
 *****************************************************************************************/