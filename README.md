# arduino-f1-dashboard-simulator
*What it does:

A real-time dashboard simulator built around the sensors and actuators  found in motorsport embedded systems.
Three analog inputs feed live data to three coordinated outputs simultaneously mimicking the core loop of 
a race car ECU: read sensors → process data → drive outputs → log telemetry.

*Component / Simulates: 

-Joystick Y-axis / Throttle pedal position sensor 
-Potentiometer / Brake pressure sensor
-Joystick X-axis / Steering angle sensor 
-Servo / Rev counter | gauge needle
-RGB LED / Shift light | zone warning indicator 
-Buzzer / Limit alert (fires once on threshold cross) 
-Serial Monitor / Live telemetry data stream 

*How it works:

The joystick Y-axis is read as throttle (0–100%). That value drives the 
servo from 0° to 180° in real time push throttle up the needle sweeps. 
The rgb led shows the operating zone: green below 30% yellow between 
30–75% red above 75%. The buzzer fires once the moment you cross into 
the red zone  not continuously  and resets when throttle drops back out. 
The potentiometer acts as brake pressure and the joystick X-axis as 
steering angle both streamed live to Serial.
A physical reset button clears the warning state and logs a RESET event 
to Serial simulating a driver acknowledging a dashboard warning.

*What i learned:

First time using a servo as a real-time output driven continuously by 
a sensor rather than moved to fixed positions as well as first time 
using an rgb light which i learn to be very practical.Managing three outputs 
reacting to the same input simultaneously each in a different way  
required thinking about output coordination rather than just input logic. 
The one-shot buzzer trigger with an external reset also introduced the 
idea of persistent state that survives across loop iterations and can 
only be cleared by one only action.

DEMO:
https://github.com/user-attachments/assets/ad471b8a-20d1-4b3e-9a23-35eb180e89cd

