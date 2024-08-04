# ESP8266 Gas Detection System

This project demonstrates a simple gas detection system using the ESP8266 WiFi module, MQ-135 gas sensor, a buzzer, and an LED. The system reads the gas concentration and triggers an alert when the gas level exceeds a specified threshold. It also serves a web interface to monitor the gas levels remotely.

## Components

- ESP8266 (NodeMCU)
- MQ-135 Gas Sensor
- Buzzer
- LED
- Resistors
- Breadboard and jumper wires

## Circuit Diagram

Connect the components as follows:
- **MQ-135 Gas Sensor**:
  - Analog output pin to A0 on ESP8266
  - VCC to 3.3V on ESP8266
  - GND to GND on ESP8266
- **Buzzer**:
  - Positive pin to D1 on ESP8266
  - Negative pin to GND on ESP8266
- **LED**:
  - Anode to D2 on ESP8266 through a resistor
  - Cathode to GND on ESP8266
