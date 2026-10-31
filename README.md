# Integrated IoT-based Aquatic Debris Collection System

- An IoT-based system utilizing the ESP32 Dev Board and ESP32-CAM, designed to enable efficient floating-waste collection in ponds, canals, and waterways.
- A smart solution that supports real-time environmental monitoring, remote navigation, and automated system alerts (including obstacle detection, waste-bin status, and battery percentage).

🏆 **1st Winner Award — Technological University Hmawbi Project Show 2026**  
🎓 **Keystone Project — Computer Engineering and Information Technology**

## Key Features

- **Live Video Monitoring** using ESP32-CAM  
- **Remote Navigation and Control** through a mobile application  
- **Waste-Bin Status Alerts** using a buzzer notification system and web dashboard  
- **Obstacle and Collision Detection** near canal walls  
- **Battery Monitoring** with low-battery warnings  
- **Web Dashboard** for real-time system-status monitoring  
- **Sustainable Design** to support cleaner waterways  

## System Architecture

```
[ESP32-CAM] ──── Wi-Fi ────> [Mobile App]
     │                           │
     ├── Live Video Feed ────────┘
     └── Collection Control ─────┘

[ESP32 Dev Board] ──── Wi-Fi ────> [Web Dashboard]
     │
     ├── Ultrasonic Sensor
     ├── Battery Voltage Sensor
     └── Buzzer
```

## Hardware Components

| Component | Function |
|---|---|
| ESP32-CAM | Live video streaming, remote monitoring, navigation, and control |
| ESP32 Dev Board | Sensor processing, alerts, and web dashboard communication |
| Ultrasonic Sensor | Obstacle and collision detection |
| Battery Voltage Sensor | Battery percentage and low-battery detection |
| Buzzer | Waste-bin fullness and warning alerts |
| DC Motors / Motor Driver | System movement and navigation |
| Waste Collection Mechanism | Floating debris collection |
| Wi-Fi Module | Internet connectivity for remote operation |

## Technologies Used

- Embedded C / C++  
- Arduino IDE  
- ESP32-CAM  
- ESP32 Dev Board  
- IoT and Wi-Fi communication  
- Sensor integration  
- Web dashboard development  
- Mobile application integration  
- Hardware-software integration  

## How It Works

1. The system connects to a Wi-Fi network.  
2. The ESP32-CAM provides a live video feed through the mobile application.  
3. The user remotely navigates the system to collect floating waste.  
4. The ultrasonic sensor detects obstacles and helps prevent collisions.  
5. The ESP32 Dev Board monitors battery level and waste-bin status.  
6. The buzzer provides alerts when the bin is nearly full or the battery is low.  
7. The web dashboard displays real-time system information.  

## Project Demonstration

![System Design](docs/System%20Design.PNG)
📄 [View Flowchart, App Interface, Web Dashboard, System Photos and Diagrams]
(docs/Flowchart%2C%20App%20Interface%2C%20Web%20Dashboard%2C%20and%20System%20Diagrams.docx)

## Achievement

This project received the **Keystone Project Winner of the Computer Engineering and Information Technology major at the Technological University Hmawbi Project Show 2026**.

## License and Source Code

Copyright © 2026 [Eant Hpone Maung (Group-I,V-CEIT)].  
All rights reserved.

This repository is shared for **portfolio and demonstration purposes only**. Selected portions of the source code are included; the complete implementation is not publicly available to protect the originality and intellectual property of the project.

No part of this code, documentation, design, or project material may be copied, modified, distributed, or used for commercial purposes without prior written permission from the author.
