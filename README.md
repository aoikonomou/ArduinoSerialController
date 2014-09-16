ArduinoSerialController
=======================

Control your arduino through your serial via text commands

Andreas Oikonomou 2014. 

This software is free for any use. Use it at your own risk (may damage your servos or other electronics). It is purely experimental. Use at your own risk.

Here is what is available. Type these commands from any serial monitor connected to your Arduino: 

// HELP MENU //

Available commands (typical format:action destination value):");

1. pinMode 13 1;               // Sets digital pin 13 to output
2. digitalPinWrite 13 1;       // Sends 5V to pin 13
3. analogPinWrite 13 255;      // Sends 5V to pin 13
4. setBaudRate 19200;          // Sets baud rate to 19200
5. startAnalogRead;            // Starts transmitting data read from analog sensors
6. stopAnalogRead;             // Stops transmitting data read from analog sensors
7. mapAnalogtoDigital 1 13;    // Maps analog input 1 to digital output pin 13
8. unMapAnalogtoDigital 1 13;  // Unmaps analog input 1 from digital output pin 13
9. driveServo 1 100;           // Sets digital pin 1 to servo mode and rotates servo to 100 degrees
10. driveServo 1;              // Transmits the position (angles) of a servo attached to digital pin 1 via serial
11. help;                      // This menu");

//Updated Commands

status			      -- ???
reset			      -- Sets all digital pins to output 
setBaudRate		      -- Needs work. Works but could be improved
pinMode			      -- Works
digitalWrite          -- Works
analogWrite           -- Works
startAnalogRead       -- Works
stopAnalogRead        -- Works
startDigitalRead      -- Works
stopDigitalRead		  -- Works
startAllRead          -- Works
stopAllRead           -- Works
mapAnalogtoDigital    -- Works
unMapAnalogtoDigital  -- Works
mapAnalogtoPWM        -- Works
unMapAnalogtoPWM      -- Works
mapAnalogtoServo      -- ???
unMapAnalogtoServo    -- ???
driveServo            -- ???
readServo             -- ???
wirelessConnect       -- No
wirelessDisconnect    -- No
wirelessWrite         -- No
wirelessRead          -- No
help                  -- Works
