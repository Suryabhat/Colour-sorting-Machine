# Colour-sorting-Machine
# Color Sorting Machine using ESP8266

## Overview
This project is an automated color sorting machine that uses an ESP8266 microcontroller and a TCS3200 color sensor. The system detects the color of objects and sorts them into designated bins using servo motors. Data logging is integrated with ThingSpeak for monitoring the sorting process.

## Components Required
- ESP8266 NodeMCU
- TCS3200 Color Sensor
- Servo Motors (x2)
- Resistors (as per sensor specifications)
- Connecting wires
- Power supply

## Circuit Diagram
![image](https://github.com/user-attachments/assets/6afaf882-efd6-47a8-be45-f22b06daf859)


## Setup and Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/Suryabhat/Home-Automation-using-ESP8266.git
   ```
2. Open the `color_sorting.ino` file in Arduino IDE.
3. Install necessary libraries:
   - Servo.h
   - ESP8266WiFi.h
   - ThingSpeak.h
4. Update WiFi credentials and ThingSpeak API key in the code.
5. Upload the code to ESP8266.
6. Connect the components as per the circuit diagram.
7. Power on the system and monitor sorting operations.

## Functionality
- The TCS3200 sensor reads RGB values of objects.
- Based on predefined RGB thresholds, the system classifies colors (e.g., orange, green, yellow).
- The servos position objects into different bins.
- ThingSpeak logs the count of each sorted object.

## How It Works
1. The system initializes WiFi and ThingSpeak.
2. The color sensor reads RGB values of the object.
3. The microcontroller determines the color based on predefined thresholds.
4. A servo mechanism sorts the object into the corresponding bin.
5. The count of sorted objects is updated on ThingSpeak.

## Example Output (Serial Monitor)
```
R Intensity: 15  G Intensity: 40  B Intensity: 35
Detected: Orange
Updating ThingSpeak...
```

## Future Enhancements
- Improve color accuracy using calibration.
- Implement real-time monitoring using a web dashboard.
- Expand to detect additional colors.

## License
This project is licensed under the MIT License. Feel free to modify and use it as needed.

---

### Contribute
If you want to improve this project, feel free to submit pull requests!

---

### Author
Surya Narayana Bhat

