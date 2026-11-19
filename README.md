# 🤖 AI-Powered Autonomous Robotic Vacuum Cleaning System

<p align="center">
  <b>An Intelligent Robotics Project for Autonomous Floor Cleaning</b>
</p>

## 📌 Project Overview

The **AI-Powered Autonomous Robotic Vacuum Cleaning System** is designed to automate floor-cleaning operations using robotics, environmental sensing, autonomous movement, and intelligent decision-making.

The robot uses multiple sensors to detect obstacles, identify floor boundaries, and recognize wet surfaces. It automatically adjusts its cleaning operations based on the detected environmental conditions.

The project integrates Arduino Uno, ESP32-CAM, ultrasonic sensors, infrared sensors, DC motors, and a servo-controlled mop mechanism.

It also provides a foundation for future integration of Artificial Intelligence, Machine Learning, Computer Vision, and intelligent navigation.

## 🎯 Objectives

- Develop an autonomous robotic cleaning system.
- Implement obstacle detection and avoidance.
- Detect floor boundaries and prevent falls.
- Identify wet surfaces.
- Automatically control vacuum and mop mechanisms.
- Integrate ESP32-CAM for real-time visual monitoring.
- Explore AI-based object recognition and intelligent navigation.


## 👨‍🏫 Faculty Guide

**Dr. Baskar A.**  
Assistant Professor  
School of Computing, Coimbatore

## 🛠️ Hardware Requirements

| Component | Purpose |
|---|---|
| Arduino Uno | Main controller |
| ESP32-CAM | Visual monitoring |
| HC-SR04 Ultrasonic Sensor | Obstacle detection |
| IR Sensors | Cliff detection |
| Rain Sensor | Wet-surface detection |
| L298N Motor Driver | Motor control |
| DC Motors | Robot movement |
| SG90 Servo Motor | Mop mechanism |
| Relay Module | Vacuum control |
| Battery | Power supply |

## 💻 Software Requirements

- Arduino IDE
- Embedded C/C++
- ESP32-CAM WebServer
- Python (for potential AI development)
- OpenCV (for potential computer vision integration)

## ⚙️ Working Methodology

1. The robot initializes all sensors and hardware components.
2. The vacuum mechanism is activated.
3. The robot moves forward in autonomous mode.
4. The ultrasonic sensor detects nearby obstacles.
5. IR sensors monitor floor boundaries.
6. The robot changes direction when an obstacle is detected.
7. The rain sensor identifies wet surfaces.
8. The vacuum is switched OFF and the mop is deployed when wetness is detected.
9. The ESP32-CAM provides visual monitoring through Wi-Fi.
10. The process continues automatically.

## 🧠 AI and Robotics Concepts

The project explores the following concepts:

- Autonomous Robotics
- Environmental Perception
- Sensor Fusion
- Intelligent Decision-Making
- Computer Vision
- Machine Learning
- Autonomous Navigation

**Note:** Computer vision and machine-learning capabilities are proposed extensions unless separately implemented and tested.

## 🏗️ System Architecture

```text
       ENVIRONMENT
            |
            v
    Sensors + ESP32-CAM
            |
            v
      Data Collection
            |
            v
       Arduino Uno
            |
            v
     Decision Making
            |
       +----+----+
       |         |
       v         v
   Motor       Cleaning
   Control     Control
       |         |
       v         v
    Movement  Vacuum/Mop
       |         |
       +----+----+
            |
            v
    AUTONOMOUS CLEANING
```

## 📂 Repository Structure

```text
AI-Autonomous-Vacuum-Cleaning-Robot/
│
├── Code/
│   ├── Arduino/
│   │   └── vacuum_robot.ino
│   │
│   └── ESP32-CAM/
│       └── camera_stream.ino
│
├── Project-Report/
│   └── Project_Report.pdf
│
├── Project-Video/
│   └── video_link.txt
│
├── Images/
│   └── prototype.jpg
│
└── README.md
```

## 🧪 Testing

The system can be evaluated using the following test cases:

| Test | Expected Behaviour |
|---|---|
| Normal floor | Forward movement |
| Obstacle detected | Stop and turn |
| Cliff detected | Avoid boundary |
| Wet surface | Mop deployment |
| Dry surface | Vacuum operation |
| Camera monitoring | Live video streaming |

## 📸 Project Images

Add your actual prototype photographs here.

```markdown
![Robot Prototype](Images/prototype.jpg)
```

## 🎥 Project Demonstration Video

**Video Link:** [Add your YouTube or Google Drive link here]

## 📄 Project Report

**Download/View Full Project Report:** [Add your PDF link here]

## 🚀 Future Enhancements

- AI-based object detection.
- Computer vision-based navigation.
- SLAM-based environment mapping.
- Machine-learning-based decision-making.
- Mobile application integration.
- Voice-controlled operation.
- Automatic charging and docking.
- Intelligent cleaning path optimization.

## 🏠 Applications

- Smart homes.
- Residential cleaning.
- Office cleaning automation.
- Educational robotics.
- Autonomous service robots.

## 📚 References

1. Arduino Documentation – https://docs.arduino.cc/
2. ESP32 Documentation – https://docs.espressif.com/
3. OpenCV Documentation – https://docs.opencv.org/
4. Artificial Intelligence: A Modern Approach – Stuart Russell and Peter Norvig.
5. Introduction to Robotics – John J. Craig.

---

<p align="center">
  <b>AI-Powered Autonomous Robotic Vacuum Cleaning System</b>
  <br/>
  School of Computing, Coimbatore
  <br/>
  Amrita Vishwa Vidyapeetham
  <br/><br/>
  <i>October 28, 2026</i>
</p>
