# 🏠 Smart Home Automation System using Arduino UNO

> An intelligent home automation system built using **Arduino UNO**, integrating multiple sensors and actuators to automate lighting, ventilation, gas leakage detection, and door access. This project demonstrates the practical implementation of embedded systems, sensor interfacing, and real-time automation in a modular and scalable architecture.

<br>

## Smart Home Automation System

![Platform](https://img.shields.io/badge/Platform-Arduino%20UNO-00979D?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge)
![IDE](https://img.shields.io/badge/IDE-Arduino%20IDE-00979D?style=for-the-badge)
![Architecture](https://img.shields.io/badge/Architecture-Embedded%20Systems-blueviolet?style=for-the-badge)
![Simulation](https://img.shields.io/badge/Simulation-Tinkercad-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-success?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)

---

# 📖 Project Overview

The **Smart Home Automation System** is an embedded systems project that demonstrates how multiple sensors and actuators can be integrated to automate common household operations using a single microcontroller.

The system continuously monitors environmental conditions and performs automatic actions without requiring manual intervention. Individual modules work together to provide intelligent control over home lighting, ventilation, safety monitoring, and door access while remaining independent enough to be understood, tested, or expanded individually.

Designed with a modular architecture, the project emphasizes simplicity, reliability, and practical implementation, making it an excellent educational project for students, hobbyists, and anyone interested in embedded systems and home automation.

> [!NOTE]
> This repository is intended for educational purposes and demonstrates the fundamentals of embedded systems, sensor interfacing, actuator control, and real-time automation using the Arduino UNO platform.

---

# ✨ Key Highlights

- Modular embedded system architecture
- Automatic home lighting based on ambient light intensity
- Motion-controlled fan operation using a PIR sensor
- Real-time gas leakage monitoring with audible alerts
- Automatic door access using ultrasonic distance measurement
- Real-time system monitoring through the Serial Monitor
- Simple and expandable hardware design
- Beginner-friendly implementation with clear program structure
- Suitable for simulation and physical hardware implementation

---

# 🚀 Features

### 💡 Automatic Lighting Control

Automatically switches lighting based on surrounding light intensity detected by an LDR sensor, improving energy efficiency.

### 🌬 Motion-Based Fan Automation

Uses a PIR motion sensor to detect human presence and automatically operates a DC motor representing a ceiling fan.

### 🔥 Gas Leakage Detection

Continuously monitors combustible gas concentration using an MQ-2 sensor and activates a buzzer whenever the configured safety threshold is exceeded.

### 🚪 Automatic Door Controller

Detects approaching objects using an HC-SR04 ultrasonic sensor and automatically opens or closes a servo-operated door.

### 📊 Real-Time Monitoring

Displays sensor readings, system states, and operational messages through the Arduino Serial Monitor for debugging and observation.

### 🧩 Modular Design

Each subsystem has been designed independently, allowing individual testing, maintenance, and future expansion without affecting other modules.

---

# 🛠 Technology Stack

| Category | Technology |
|------------|------------|
| Programming Language | C++ |
| Microcontroller | Arduino UNO |
| Development Environment | Arduino IDE |
| Simulation Platform | Tinkercad Circuits |
| Programming Model | Embedded Programming |
| Communication | Serial UART |
| Architecture | Sensor-Based Automation |

---

# 📂 Repository Structure

```text
Smart-Home-Automation-System/
│
├── Arduino_Code/
│   └── Smart_Home_Automation.ino
│
├── Circuit_Diagram/
│
├── Documentation/
│
├── LICENSE
├── CONTRIBUTING.md
└── README.md
```

> [!TIP]
> Organizing project resources into dedicated folders improves maintainability and makes the repository easier to navigate.

---

# 📑 Table of Contents

- Project Overview
- Key Highlights
- Features
- Technology Stack
- Repository Structure
- Hardware Components
- Software Requirements
- Pin Configuration
- Hardware Architecture
- System Workflow
- Working Principle
- Installation Guide
- Building the Circuit
- Uploading the Program
- Testing Procedure
- Troubleshooting
- Applications
- Future Improvements
- Contributing
- License
- Author

---

> [!IMPORTANT]
> The following sections provide detailed information about the hardware design, software implementation, circuit connections, and complete working methodology of the Smart Home Automation System.
# 🛠 Hardware Components

The Smart Home Automation System is built using commonly available electronic components that demonstrate fundamental embedded system concepts such as sensing, control, automation, and real-time monitoring.

The following table summarizes all hardware components used in the project.

| Component | Quantity | Purpose |
|-----------|:--------:|---------|
| Arduino UNO | 1 | Main microcontroller responsible for processing sensor data and controlling all peripherals |
| LDR Sensor | 1 | Detects ambient light intensity for automatic lighting control |
| PIR Motion Sensor | 1 | Detects human motion for fan automation |
| MQ-2 Gas Sensor | 1 | Detects combustible gases and smoke |
| HC-SR04 Ultrasonic Sensor | 1 | Measures distance for automatic door control |
| SG90 Servo Motor | 1 | Opens and closes the automatic door |
| DC Motor | 1 | Represents the room ventilation fan |
| Relay Module | 1 | Controls the lighting load |
| Buzzer | 1 | Generates an audible gas leakage alarm |
| LEDs | 2 | Indicates system status and operation |
| Breadboard | 1 | Circuit prototyping |
| Jumper Wires | As Required | Electrical connections |
| USB Cable | 1 | Programming and power supply |

---

# 💻 Software Requirements

The project is developed using the Arduino ecosystem and requires only a few software tools for programming, testing, and debugging.

| Software | Purpose |
|----------|---------|
| Arduino IDE | Writing, compiling, and uploading the program |
| Arduino AVR Boards Package | Arduino UNO board support |
| Serial Monitor | Real-time debugging and monitoring |
| Tinkercad Circuits *(Optional)* | Circuit simulation and testing |

> [!TIP]
> Always use the latest stable version of the Arduino IDE to ensure compatibility with the required libraries.

---

# 📚 Required Libraries

This project primarily uses standard Arduino libraries.

| Library | Purpose |
|----------|---------|
| Servo.h | Controls the SG90 servo motor |
| Arduino Core Libraries | GPIO, ADC, PWM, Serial Communication |

No additional third-party libraries are required.

---

# 🔌 Arduino Pin Configuration

The following table lists all hardware connections used in the project.

| Arduino Pin | Connected Device | Function |
|-------------|------------------|----------|
| A0 | LDR Sensor | Ambient Light Detection |
| A1 | MQ-2 Gas Sensor | Gas Concentration Measurement |
| D3 | Green LED | Motion Detection Indicator |
| D4 | Red LED | System Status Indicator |
| D6 | HC-SR04 Trigger | Distance Measurement Trigger |
| D7 | HC-SR04 Echo | Distance Measurement Echo |
| D8 | Buzzer | Gas Leakage Alarm |
| D9 | PIR Sensor | Motion Detection |
| D10 | DC Motor | Fan Control |
| D11 | Servo Motor | Automatic Door Control |
| D13 | Relay Module | Light Switching |

> [!NOTE]
> Verify the pin assignments before uploading the program. If different hardware connections are used, update the pin definitions accordingly in the source code.

---

# 🏗 Hardware Architecture

The project follows a centralized embedded system architecture in which the Arduino UNO functions as the primary controller.

All sensors continuously provide environmental information to the microcontroller. Based on predefined decision logic, the controller activates the appropriate output devices without requiring manual intervention.

```text
                     +----------------------+
                     |     Arduino UNO      |
                     +----------+-----------+
                                |
      ---------------------------------------------------------
      |            |            |            |                |
      |            |            |            |                |
    LDR         PIR Sensor    MQ-2       HC-SR04        Serial Monitor
      |            |            |            |
      |            |            |            |
      |            |            |            |
    Relay       DC Motor      Buzzer      Servo Motor
      |
    Lighting
```

---

# 🧩 System Modules

The complete automation system is divided into independent functional modules, making the project easier to understand, test, and expand.

| Module | Input | Output | Description |
|---------|--------|---------|-------------|
| Lighting Automation | LDR Sensor | Relay | Controls room lighting according to ambient light intensity |
| Fan Automation | PIR Sensor | DC Motor | Operates the fan only when human motion is detected |
| Gas Safety System | MQ-2 Sensor | Buzzer | Generates an alarm when combustible gases exceed the predefined threshold |
| Automatic Door System | HC-SR04 Sensor | Servo Motor | Opens and closes the door based on object distance |
| Monitoring Module | All Sensors | Serial Monitor | Displays sensor readings and system status for debugging |

---

# ⚙ Design Philosophy

The project has been designed with simplicity, modularity, and scalability as its primary objectives.

Each subsystem performs a dedicated task while operating under the supervision of a single microcontroller. This modular approach improves readability, simplifies debugging, and allows additional automation features to be integrated in future without major modifications to the existing architecture.

> [!IMPORTANT]
> Each subsystem can be developed and tested independently before integrating the complete automation system. This significantly reduces debugging complexity and improves overall system reliability.

# ⚙️ System Workflow

The Smart Home Automation System continuously monitors environmental conditions and responds automatically based on predefined decision logic.

```text
          Power ON
              │
              ▼
    Initialize Arduino UNO
              │
              ▼
    Configure Sensors & Outputs
              │
              ▼
      Read Sensor Values
              │
              ▼
 ┌───────────────────────────────────┐
 │                                   │
 │  LDR → Lighting Automation        │
 │  PIR → Fan Automation             │
 │  MQ-2 → Gas Leakage Detection     │
 │  HC-SR04 → Door Automation        │
 │                                   │
 └───────────────────────────────────┘
              │
              ▼
      Update Output Devices
              │
              ▼
 Display System Status on Serial Monitor
              │
              ▼
          Repeat Forever
```

> [!NOTE]
> Every subsystem operates independently while sharing the same Arduino UNO controller. This modular approach improves maintainability and simplifies debugging.

---

# 🔄 Working Principle

The Arduino continuously executes the main program loop, reading sensor data and making decisions based on predefined thresholds.

Each subsystem performs a dedicated automation task without interfering with the operation of other modules.

---

## 💡 Lighting Automation

The LDR continuously measures ambient light intensity.

- Low light intensity → Relay switches **ON**
- High light intensity → Relay switches **OFF**

This simulates an automatic room lighting system.

---

## 🌬 Motion-Based Fan Automation

The PIR sensor detects human movement inside the monitored area.

When motion is detected:

- DC Motor turns ON
- Green LED illuminates

When no motion is detected:

- DC Motor turns OFF
- Red LED illuminates

---

## 🔥 Gas Leakage Detection

The MQ-2 sensor continuously measures combustible gas concentration.

If the measured value exceeds the predefined threshold:

- Buzzer activates
- Alarm remains active until the gas concentration returns to a safe level

---

## 🚪 Automatic Door Controller

The HC-SR04 ultrasonic sensor continuously measures the distance to nearby objects.

When an object enters the predefined detection range:

- Servo motor rotates
- Door opens automatically

When the object moves away:

- Servo returns to its default position
- Door closes automatically

---

# 📡 System Communication

The project uses direct hardware interfacing between the Arduino UNO and connected peripherals.

| Interface | Purpose |
|-----------|---------|
| Analog Input | LDR and MQ-2 Sensor |
| Digital Input | PIR Motion Sensor |
| Digital Output | Relay, LEDs, Buzzer |
| PWM Output | Servo Motor |
| UART | Serial Monitor |

---

# 🔋 Power Requirements

| Component | Operating Voltage |
|-----------|------------------:|
| Arduino UNO | 5V |
| LDR Module | 5V |
| MQ-2 Sensor | 5V |
| PIR Sensor | 5V |
| HC-SR04 | 5V |
| SG90 Servo | 5V |
| Relay Module | 5V |
| LEDs | 5V |
| Buzzer | 5V |

> [!TIP]
> For reliable operation, use a stable 5V power supply and ensure that all components share a common ground (GND).

---

# 📂 Source Code Structure

The Arduino sketch is organized into logical sections to improve readability and maintenance.

```text
Program Initialization
│
├── Library Inclusion
├── Pin Definitions
├── Global Variables
├── setup()
│
└── loop()
    │
    ├── Read LDR
    ├── Read PIR
    ├── Read MQ-2
    ├── Read Ultrasonic Sensor
    ├── Control Relay
    ├── Control DC Motor
    ├── Control Servo
    ├── Activate Buzzer
    └── Serial Monitoring
```

---

# ✅ Functional Summary

| Module | Sensor | Actuator | Purpose |
|---------|---------|----------|---------|
| Lighting | LDR | Relay | Automatic Light Control |
| Ventilation | PIR | DC Motor | Motion-Based Fan Control |
| Safety | MQ-2 | Buzzer | Gas Leakage Alert |
| Access Control | HC-SR04 | Servo Motor | Automatic Door Operation |
| Monitoring | All Sensors | Serial Monitor | Real-Time System Status |

> [!IMPORTANT]
> Each automation module has been implemented independently, allowing the system to be expanded with additional sensors or actuators without requiring major modifications to the existing program structure.

# 🚀 Getting Started

This section explains how to set up the development environment, assemble the hardware, upload the program, and run the Smart Home Automation System.

---

# 📋 Prerequisites

Before starting, ensure you have the following:

### Hardware

- Arduino UNO
- USB Type-B Cable
- Breadboard
- Jumper Wires
- LDR Sensor
- MQ-2 Gas Sensor
- PIR Motion Sensor
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Relay Module
- DC Motor
- LEDs
- Piezo Buzzer

### Software

- Arduino IDE
- Arduino AVR Boards Package
- USB Driver (if required)

---

# 📥 Clone the Repository

Clone the repository using Git.

```bash
git clone https://github.com/<your-username>/Smart-Home-Automation-System.git
```

Or simply download the project as a ZIP file from GitHub.

> [!TIP]
> If you are a beginner, downloading the repository as a ZIP file is the quickest way to get started.

---

# 💻 Arduino IDE Setup

1. Install the latest version of the Arduino IDE.
2. Launch the IDE.
3. Open the project sketch (`.ino` file).
4. Connect the Arduino UNO to your computer using a USB cable.
5. Select **Arduino UNO** from:

```
Tools → Board → Arduino AVR Boards → Arduino UNO
```

6. Select the correct COM Port from:

```
Tools → Port
```

---

# 📚 Install Required Library

Open:

```
Sketch → Include Library → Manage Libraries
```

Search for:

```
Servo
```

Install the official Arduino Servo library if it is not already installed.

> [!NOTE]
> Most Arduino IDE installations already include the Servo library by default.

---

# 🔌 Hardware Assembly

Assemble the circuit according to the pin configuration provided in the previous section.

Before powering the circuit, verify that:

- All VCC connections are correct
- All GND connections share a common ground
- Sensor outputs are connected to the correct Arduino pins
- Servo motor polarity is correct
- Relay module is wired properly

> [!WARNING]
> Incorrect wiring may prevent the project from functioning correctly and can potentially damage electronic components.

---

# ⬆️ Upload the Program

Once the hardware has been assembled:

1. Open the Arduino sketch.
2. Click **Verify** to compile the program.
3. Resolve any compilation errors if present.
4. Click **Upload**.
5. Wait until the upload completes successfully.

Arduino IDE should display:

```text
Done uploading.
```

---

# ▶️ Running the Project

After uploading:

1. Keep the Arduino connected.
2. Open the Serial Monitor.
3. Set the baud rate specified in the source code.
4. Observe live sensor values and system messages.

The system immediately begins monitoring all connected sensors and controlling the respective output devices automatically.

---

# 🧪 Functional Testing

Test each subsystem independently before testing the complete automation system.

| Test Case | Action | Expected Result |
|-----------|--------|-----------------|
| Lighting | Reduce ambient light | Relay switches ON |
| Lighting | Increase ambient light | Relay switches OFF |
| Motion Detection | Trigger PIR Sensor | DC Motor starts and Green LED turns ON |
| Motion Detection | Remove motion | DC Motor stops and Red LED turns ON |
| Gas Detection | Increase MQ-2 gas value | Buzzer activates |
| Door Automation | Place object near HC-SR04 | Servo opens the door |
| Door Automation | Remove object | Servo returns to default position |

---

# ✅ Expected Behaviour

When operating correctly, the system should:

- Automatically control room lighting.
- Detect human motion and operate the fan.
- Trigger an audible alarm during gas leakage.
- Automatically open and close the door.
- Display system information through the Serial Monitor.
- Execute all automation tasks continuously without manual intervention.

---

# 📝 Troubleshooting Checklist

If the project does not operate as expected:

- Verify all wiring connections.
- Confirm that the correct Arduino board is selected.
- Ensure the correct COM Port is selected.
- Check that the Servo library is installed.
- Verify the baud rate of the Serial Monitor.
- Confirm that all sensors receive a stable 5V supply.
- Ensure every component shares a common ground.
- Re-upload the sketch after making hardware changes.

> [!TIP]
> Test one subsystem at a time instead of debugging the complete circuit simultaneously. This approach makes identifying issues significantly easier.

# 🌍 Applications

The Smart Home Automation System demonstrates several fundamental concepts of embedded systems and can be adapted for a wide range of educational and practical applications.

| Application | Description |
|-------------|-------------|
| Smart Home Automation | Automatic control of household appliances based on environmental conditions |
| Energy Management | Reduces unnecessary power consumption through automated lighting and ventilation |
| Safety Monitoring | Detects combustible gas leakage and generates an audible alert |
| Access Control | Demonstrates automated door operation using distance sensing |
| Embedded Systems Education | Practical learning platform for sensor interfacing and actuator control |
| Engineering Projects | Suitable for laboratory experiments, mini projects, and academic demonstrations |

---

# ⭐ Project Advantages

The project has been designed with simplicity, modularity, and ease of understanding in mind while still demonstrating essential embedded systems concepts.

### Key Advantages

- Modular hardware architecture
- Easy to understand and maintain
- Beginner-friendly implementation
- Real-time automation
- Low-cost hardware components
- Expandable system architecture
- Supports both simulation and physical implementation
- Demonstrates multiple sensor interfacing techniques
- Suitable for academic and learning environments

---

# ⚠️ Current Limitations

Although the project successfully demonstrates home automation concepts, it is intentionally designed as a standalone embedded system.

Current limitations include:

- No wireless communication
- No IoT connectivity
- No mobile application support
- No cloud-based monitoring
- No remote device control
- Limited number of automation modules
- Single microcontroller architecture

> [!NOTE]
> These limitations are intentional to keep the project simple, beginner-friendly, and focused on core embedded systems concepts.

---

# 🚀 Future Improvements

The modular architecture allows additional functionality to be integrated with minimal hardware modifications.

Possible future enhancements include:

- Wi-Fi based home automation
- Mobile application integration
- MQTT communication
- Voice assistant compatibility
- Smart energy monitoring
- LCD or OLED status display
- RFID-based door access
- Password-protected security system
- Fire detection system
- Water level monitoring
- Smart irrigation support
- AI-based automation logic
- Raspberry Pi integration
- ESP32 cloud connectivity
- Home Assistant integration

---

# 📚 Learning Outcomes

After completing this project, users will gain practical experience in:

- Embedded systems development
- Arduino programming
- Sensor interfacing
- Actuator control
- Digital and analog input processing
- Serial communication
- Hardware debugging
- Real-time automation
- Embedded system design methodology
- Circuit prototyping
- System integration

---

# 🤝 Contributing

Contributions are always welcome.

If you would like to improve this project:

1. Fork the repository.
2. Create a new feature branch.
3. Implement your changes.
4. Commit your modifications.
5. Submit a Pull Request.

Please ensure that:

- Code follows a consistent coding style.
- Existing functionality remains unaffected.
- Changes are properly documented.
- Pull requests contain meaningful commit messages.

---

# 📄 License

This project is released under the **MIT License**.

You are free to use, modify, distribute, and improve this project for educational and personal purposes.

Refer to the **LICENSE** file for complete licensing information.

---

# 🙏 Acknowledgements

Special thanks to the open-source community and the Arduino ecosystem for providing accessible tools, libraries, and documentation that make embedded systems learning more approachable.

This project was developed as an educational implementation to demonstrate the fundamentals of home automation using Arduino UNO.

---

# ⭐ Support the Project

If you found this repository useful, consider supporting the project by:

- ⭐ Starring the repository
- 🍴 Forking the project
- 🛠️ Contributing improvements
- 🐞 Reporting bugs
- 💡 Suggesting new features

Community support helps improve the project and encourages future development.

---

# 📬 Feedback

Suggestions, ideas, and constructive feedback are always appreciated.

If you discover any issues or have recommendations for improvements, feel free to open an Issue or submit a Pull Request through GitHub.

---

> [!TIP]
> If you build this project or create an improved version, consider sharing your implementation with the community. Open-source collaboration helps everyone learn and build better embedded systems.

---

# 📈 Project Status

| Status | Details |
|----------|---------|
| Development | Completed |
| Repository Status | Actively Maintained |
| Hardware Verification | Tested |
| Simulation | Supported |
| Documentation | Complete |
| License | MIT |

---

# 🗺️ Roadmap

The following enhancements are planned for future releases of this project.

- [ ] Wireless IoT Connectivity
- [ ] Mobile Application Integration
- [ ] Cloud-Based Monitoring
- [ ] OLED Display Support
- [ ] Smart Energy Analytics
- [ ] Voice Assistant Integration
- [ ] MQTT Communication
- [ ] ESP32-Based Wireless Version
- [ ] Home Assistant Compatibility
- [ ] Improved Hardware Enclosure

---

# 📖 Documentation

The repository has been organized to simplify learning, experimentation, and future development.

| Document | Description |
|----------|-------------|
| README.md | Complete project documentation |
| LICENSE | Project license information |
| CONTRIBUTING.md | Contribution guidelines |
| Source Code | Arduino implementation |
| Circuit Diagram | Hardware connections |

Future versions of the repository may include additional documentation such as hardware schematics, PCB layouts, and simulation files.

---

# 🤝 Contributing

Contributions are welcome and appreciated.

If you would like to improve this project:

1. Fork this repository.
2. Create a new feature branch.
3. Commit your changes with clear commit messages.
4. Push your branch to GitHub.
5. Open a Pull Request.

Please ensure that all submitted changes:

- Follow clean coding practices.
- Maintain compatibility with the existing project.
- Include appropriate documentation where necessary.
- Do not introduce breaking changes without explanation.

---

# 🐞 Reporting Issues

If you encounter a bug or have suggestions for improvements, please open a GitHub Issue.

When reporting an issue, include:

- Hardware configuration
- Arduino IDE version
- Error messages (if any)
- Steps to reproduce the issue
- Expected behavior
- Actual behavior

Providing detailed information helps improve troubleshooting and project maintenance.

---

# 💡 Project Inspiration

This project was developed as an educational implementation to demonstrate the practical application of embedded systems in home automation.

The objective was to create a modular automation system that is simple to understand, affordable to build, and suitable for both simulation and physical implementation while introducing key concepts such as sensor interfacing, actuator control, and real-time embedded programming.

---

# 📚 References

The following resources were used during the development of this project.

- Arduino Official Documentation
- Arduino IDE Documentation
- Servo Library Documentation
- Tinkercad Circuits Documentation
- Component Datasheets (LDR, MQ-2, PIR, HC-SR04, SG90)

---

# 👨‍💻 Maintainer

Developed and maintained by **ShivsFoundry**

If you find this repository helpful, consider supporting the project by:

- ⭐ Starring the repository
- 🍴 Forking the project
- 🛠️ Contributing improvements
- 🐞 Reporting bugs
- 💬 Sharing feedback

Open-source collaboration helps improve projects and benefits the embedded systems community.

---

# 📄 License

This project is licensed under the **MIT License**.

You are free to use, modify, distribute, and extend this project in accordance with the terms of the license.

See the **LICENSE** file for more information.

---

# ⭐ If You Like This Project

If this repository helped you learn something new or inspired your own implementation, consider giving it a **Star** on GitHub.

Your support encourages the continued development of educational embedded systems projects.

---

<div align="center">

### Built with ❤️ using Arduino UNO

**ShivsFoundry**

*Embedded Systems • Robotics • IoT • Open Source*

---

**Thank you for visiting this repository.**

</div>
---

# 👨‍💻 About the Developer

<div align="center">

## ShivsFoundry

**Embedded Systems • IoT • Robotics • Open Source**

Building practical embedded systems through thoughtful engineering, continuous learning, and open-source collaboration.

</div>

---

## 💡 Engineering Philosophy

This repository reflects a hands-on approach to learning embedded systems by transforming theoretical concepts into practical implementations.

Every project published under **ShivsFoundry** is developed with the goal of maintaining:

- Clean and maintainable code
- Modular hardware architecture
- Well-structured documentation
- Reproducible implementations
- Beginner-friendly learning resources
- Open-source collaboration

The objective is not only to build working prototypes, but also to create repositories that help others understand the complete engineering workflow—from circuit design to software implementation and documentation.

---

# 🌐 Connect with ShivsFoundry

Stay connected and follow future embedded systems and hardware projects.

- 💼 GitHub: **https://github.com/ShivsFoundry**

> [!NOTE]
> Additional platforms such as LinkedIn, Portfolio Website, YouTube, or Hackster.io can be added here in the future.

---

# ⭐ Repository Support

If you found this repository useful, please consider supporting the project.

You can help by:

- ⭐ Starring the repository
- 🍴 Forking the project
- 🛠️ Contributing improvements
- 🐞 Reporting bugs
- 💬 Sharing suggestions
- 📢 Recommending the repository to others

Every contribution, no matter how small, helps improve the project and supports future open-source development.

---

# 📊 Repository Information

| Property | Details |
|----------|---------|
| Repository Type | Embedded Systems Project |
| Difficulty Level | Beginner to Intermediate |
| Programming Language | C++ |
| Platform | Arduino UNO |
| Documentation | Markdown |
| License | MIT |
| Maintainer | ShivsFoundry |

---

# ❤️ Acknowledgements

Special thanks to the open-source community whose libraries, documentation, and educational resources continue to make embedded systems development more accessible.

This project would not have been possible without the excellent ecosystem provided by:

- Arduino
- Tinkercad
- Open-source contributors
- Embedded systems community

---

# 📈 Project Evolution

This repository is intended to evolve over time.

Future updates may include:

- Improved code optimization
- Additional automation modules
- Hardware revisions
- Better documentation
- Performance enhancements
- PCB implementation
- IoT-enabled version
- Mobile application support

---

# 📜 Citation

If this repository contributes to your learning or project development, please consider referencing it appropriately and linking back to the original repository.

---

<div align="center">

# ⭐ Thank You for Visiting ⭐

### If you found this project useful, don't forget to leave a ⭐ on the repository.

---

### Built with dedication to Embedded Systems and Open Source.

## **ShivsFoundry**

*Design • Develop • Debug • Deliver*

</div>
