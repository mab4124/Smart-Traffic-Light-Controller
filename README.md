# Arduino-Powered Smart Traffic Light Controller (Enhanced)

## Project Synopsis
This project uses an Arduino UNO and LEDs to simulate a smart 4-way traffic light controller. Its inclusion of emergency vehicle override and pedestrian crossing control brings it closer to practical uses.


## Features: 
- Red, yellow, and green LEDs control four directions;
- Pedestrian crossing with buzzer alert and button input;
- Emergency vehicle override to provide instant green light;
- Simple, modular Arduino code;
- Completely simulated in Tinkercad (no physical hardware required)

## Parts Used: 
Arduino UNO
Twelve LEDs, three in each direction
Twelve 220Ω resistors
One buzzer
Three input switches or buttons (emergency sensor, pedestrian button, and optional reset)
A breadboard (for a clean simulation layout)

## Pin Setup
| Function             | Arduino Pin |
|----------------------|-------------|
| Direction A - Red    | 2           |
| Direction A - Yellow | 3           |
| Direction A - Green  | 4           |
| Direction B - Red    | 5           |
| Direction B - Yellow | 6           |
| Direction B - Green  | 7           |
| Direction C - Red    | 8           |
| Direction C - Yellow | 9           |
| Direction C - Green  | 10          |
| Direction D - Red    | 11          |
| Direction D - Yellow | 12          |
| Direction D - Green  | 13          |
| Pedestrian Button    | A0          |
| Emergency Sensor     | A1          |
| Pedestrian Green LED | A2          |
| Buzzer               | A3          |

## Usage Instructions
1. Open the Arduino code (`Smart_Traffic_Light_Controller_Enhanced.ino`) in Arduino IDE or Tinkercad.
2. Connect LEDs and resistors as per the pin configuration.
3. Use buttons on analog pins A0 and A1 to simulate pedestrian request and emergency override.
4. Run the simulation to observe the traffic light sequence and special modes.

## Extension Ideas
- Add an LCD display for countdown timers
- Implement adaptive traffic timing using sensors
- Integrate IoT to monitor/control via smartphone

## Simulation Link
See `Tinkercad_Link.txt` for the full simulation setup online.
