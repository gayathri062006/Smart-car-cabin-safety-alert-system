# Smart car safety alert system

## Overview
IoT‑inspired smart car cabin safety system using a temperature sensor and PIR motion sensor to detect human presence and dangerous heat inside a parked car.
Built with Arduino Uno and fully simulated on Wokwi (no physical hardware required).

## Features
Continuously monitors cabin temperature.
Detects if a person is present inside the car using a PIR sensor.
Uses Green / Yellow / Red LEDs to indicate SAFE / WARNING / DANGER states.
Activates buzzer with different beep patterns for warning and danger.
Can be extended later to add GSM / cloud alerts for real‑time notifications.

## Hardware Used
Arduino Uno
PIR motion sensor (human presence detection)
DS18B20 digital temperature sensor (or DHT11 if you choose)
3 × LEDs (Green, Yellow, Red)
3 × 220 Ω resistors (for LEDs)
1 × Buzzer (active or passive)
Jumper wires and breadboard (virtual, in Wokwi)

## Simulation
Wokwi project link:
https://wokwi.com/projects/451236774044868609
Main file: smart_car_cabin_safety.ino
Circuit image: smart_car_cabin_safety.png
