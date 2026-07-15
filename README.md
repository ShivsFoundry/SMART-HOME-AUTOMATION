# 🏠 Smart Home Automation System using Arduino UNO

A beginner-friendly Arduino project that demonstrates how multiple sensors and actuators can work together to automate common household tasks. The system continuously monitors its surroundings and automatically controls appliances such as lights, fans, alarms, and doors based on real-time sensor input.

Built using **Arduino UNO** and simulated in **Tinkercad Circuits**, this project is ideal for students, hobbyists, and anyone learning embedded systems and home automation fundamentals.

---

## Table of Contents

- [Features](#-features)
- [Components Used](#-components-used)
- [Arduino Pin Connections](#-arduino-pin-connections)
- [System Modules](#-system-modules)
- [Working Principle](#️-working-principle)
- [Software Requirements](#-software-requirements)
- [Library Used](#-library-used)
- [Building the Circuit in Tinkercad](#-building-the-circuit-in-tinkercad)
- [Running the Project](#️-how-to-run-the-project)
- [Testing the System](#-testing-the-system)
- [Troubleshooting](#-troubleshooting)
- [Applications](#-applications)

---

## ✨ Features

- 💡 Automatic room light control based on ambient light
- 🚶 Automatic fan control using motion detection
- 🔥 Gas leakage detection with audible alarm
- 🚪 Automatic smart door using an ultrasonic sensor
- 🟢🔴 Status indication using LEDs
- 📟 Real-time sensor monitoring through the Serial Monitor
- 🎓 Beginner-friendly implementation using Arduino UNO

---

## 🛠 Components Used

| Component | Quantity | Real-Life Representation |
|---|---|---|
| Arduino UNO | 1 | Main Smart Home Controller |
| LDR Sensor | 1 | Automatic Room/Street Light Sensor |
| MQ-2 Gas Sensor | 1 | Kitchen Gas Leakage Detector |
| PIR Motion Sensor | 1 | Motion Detection Sensor |
| HC-SR04 Ultrasonic Sensor | 1 | Visitor Detection Near Door |
| Servo Motor | 1 | Automatic Door |
| Relay Module | 1 | Smart Light Switch |
| DC Motor | 1 | Ceiling/Table Fan |
| Piezo Buzzer | 1 | Emergency Alarm |
| Green LED | 1 | Motion Detected Indicator |
| Red LED | 1 | No Motion Indicator |
| NPN Transistor | 1 | Electronic Switch for DC Motor |
| 10kΩ Resistor | 1 | LDR Voltage Divider |
| 220Ω Resistor | 2 | LED Current Limiting |
| Breadboard | 1 | Circuit Assembly |
| Jumper Wires | As Required | Electrical Connections |

---

## 🔌 Arduino Pin Connections

| Arduino Pin | Connected Component |
|---|---|
| A0 | LDR Sensor |
| A1 | MQ-2 Gas Sensor |
| D3 | Green LED |
| D4 | Red LED |
| D6 | HC-SR04 Trigger & Echo |
| D7 | Servo Motor |
| D8 | Piezo Buzzer |
| D9 | PIR Motion Sensor |
| D10 | DC Motor (via NPN Transistor) |
| D13 | Relay Module |

---

## 🏡 System Modules

### 💡 Automatic Light Control
**Components:** LDR Sensor, Relay Module, Bulb

Functions like an automatic room or street light. The LDR continuously measures ambient light intensity. When the environment becomes dark, the Arduino activates the relay to switch the light ON; when sufficient light is available, the relay switches it OFF.

### 🚶 Motion-Based Fan Control
**Components:** PIR Motion Sensor, DC Motor, NPN Transistor, Red LED, Green LED

Represents an automatic room fan. The PIR sensor detects human movement inside the room. When motion is detected, the Arduino turns the DC motor ON and lights the Green LED. When no motion is present, the Red LED turns ON instead.

### 🔥 Gas Leakage Detection
**Components:** MQ-2 Gas Sensor, Piezo Buzzer

Simulates a kitchen gas leakage detection system. The MQ-2 sensor continuously monitors combustible gas concentration. If the level exceeds a predefined safety threshold, the Arduino activates the buzzer to alert nearby users.

### 🚪 Automatic Smart Door
**Components:** HC-SR04 Ultrasonic Sensor, Servo Motor

Represents an automatic entrance door, similar to those found in malls, hospitals, airports, and office buildings. The ultrasonic sensor continuously measures the distance to nearby objects. When a person approaches within range, the servo motor rotates to open the door; once they move away, it returns to its original position, closing the door.

---

## ⚙️ Working Principle

The Arduino continuously reads data from all connected sensors and performs actions based on their outputs:

- The **LDR Sensor** automatically controls the room light.
- The **PIR Motion Sensor** detects movement and operates the fan.
- The **MQ-2 Gas Sensor** monitors gas leakage and activates the buzzer when necessary.
- The **Ultrasonic Sensor** detects nearby objects and controls the automatic door via the servo motor.

Each module operates independently, allowing the complete system to perform multiple home automation tasks simultaneously.

---

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- [Tinkercad Circuits](https://www.tinkercad.com/)

---

## 📚 Library Used

```cpp
#include <Servo.h>
```

The **Servo** library is used to control the servo motor for the automatic door system.

---

## 🔧 Building the Circuit in Tinkercad

### Step 1: Create a New Circuit
1. Open **Tinkercad** and navigate to **Circuits**.
2. Click **Create New Circuit**.
3. Drag an **Arduino UNO** onto the workspace.
4. Place a **large breadboard** beside the Arduino.

### Step 2: Power Distribution
- Connect the **5V** pin of the Arduino to the **positive (+) rail** of the breadboard.
- Connect one **GND** pin of the Arduino to the **negative (–) rail** of the breadboard.

All components requiring 5V should connect to the positive rail; all grounds should connect to the negative rail.

### Step 3: Connect the LDR (Light System)
- One terminal of the LDR → **5V**
- Other terminal of the LDR → **A0**
- 10kΩ resistor between **A0** and **GND**

This forms a voltage divider used to measure ambient light intensity.

### Step 4: Connect the MQ-2 Gas Sensor
- VCC → **5V**
- GND → **GND**
- Analog Output → **A1**

### Step 5: Connect the PIR Motion Sensor
- VCC → **5V**
- GND → **GND**
- OUT → **D9**

### Step 6: Connect the Ultrasonic Sensor
- VCC → **5V**
- GND → **GND**
- Trigger → **D6**
- Echo → **D6**

> **Note:** This project intentionally uses the same Arduino pin (D6) for both Trigger and Echo, matching the provided sketch.

### Step 7: Connect the Servo Motor
- Signal → **D7**
- VCC → **5V**
- GND → **GND**

### Step 8: Connect the Relay Module
- VCC → **5V**
- GND → **GND**
- IN → **D13**

### Step 9: Connect the DC Motor
Driven via an **NPN transistor**:
- Arduino **D10** → Base of transistor (through a resistor)
- Emitter → GND
- Collector → Negative terminal of DC motor
- Positive terminal of motor → 5V

> **Recommended:** Add a flyback diode across the motor terminals to protect the transistor from voltage spikes.

### Step 10: Connect the LEDs
**Green LED:** Anode → D3 · Cathode → 220Ω resistor → GND
**Red LED:** Anode → D4 · Cathode → 220Ω resistor → GND

### Step 11: Connect the Piezo Buzzer
- Positive terminal → **D8**
- Negative terminal → **GND**

### Step 12: Verify All Connections
Confirm the wiring matches the pin table below before running the simulation.

| Arduino Pin | Connected Component |
|---|---|
| A0 | LDR |
| A1 | MQ-2 Gas Sensor |
| D3 | Green LED |
| D4 | Red LED |
| D6 | HC-SR04 Trigger & Echo |
| D7 | Servo Motor |
| D8 | Piezo Buzzer |
| D9 | PIR Motion Sensor |
| D10 | DC Motor (via NPN Transistor) |
| D13 | Relay Module |

### Step 13: Upload the Program
1. Copy the Arduino code from this repository.
2. Open the **Code** panel in Tinkercad and select **Text Mode**.
3. Replace the existing code with the project code.
4. Click **Start Simulation**.

---

## ▶️ How to Run the Project

1. Open the project in **Arduino IDE**.
2. Assemble the circuit according to the pin connections listed above.
3. Select **Arduino UNO** from the **Boards** menu.
4. Upload the program to the board.
5. Open the **Serial Monitor** and set the baud rate to **9600**.
6. Test each module individually (see [Testing the System](#-testing-the-system) below).

---

## 🧪 Testing the System

| Module | Test | Expected Result |
|---|---|---|
| 💡 Light Automation | Move the LDR slider to simulate day/night | Relay switches bulb ON/OFF automatically |
| 🚶 Motion Detection | Trigger the PIR sensor | DC motor turns ON, Green LED ON, Red LED OFF |
| 🔥 Gas Detection | Increase gas concentration on MQ-2 | Buzzer activates past threshold |
| 🚪 Automatic Door | Move an object near the ultrasonic sensor | Servo opens door; closes when object moves away |

---

## 🐞 Troubleshooting

If a module isn't working as expected:

- Verify all wiring connections against the pin table.
- Check that every component shares a common ground.
- Confirm the correct Arduino pins are used in both the circuit and the code.
- Ensure the `Servo.h` library is included in the sketch.
- Restart the Tinkercad simulation after modifying the circuit.

---

## 📌 Applications

- Smart home automation
- Automatic lighting systems
- Motion-controlled appliances
- Kitchen gas safety systems
- Automatic door systems
- Educational Arduino projects
- Embedded systems learning
- Engineering mini-projects

---

## 📄 License

This project is open-source and available for educational and personal use. Feel free to fork, modify, and build upon it.
