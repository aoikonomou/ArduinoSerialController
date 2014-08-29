/* 
Arduino Serial Controller v 0.1
Control your Arduino Uno by sending text commands to it down the serial port
Code is free for any use. Use at your own risk. It is experimental and may destroy your hardware
Written by Andreas Oikonomou 2014. Some code (e.g. serialEvent) adapted from examples online.

Warning: Do not exceed 75% of Arduino's memory (as reported on PC) or 57% (as reported on Mac) or strange things happen with the variables and the code doesn't work as expected!
*/

// Includes & Variable Declarations

#include "customFunctions.h"
#include "help.h"
#include "interpreter.h"
#include <Servo.h>
#include <avr/pgmspace.h>

int baudRate = 9600;

String inputString = "";         // a string to hold incoming serial data

const int numberofAnalogPins = 6;
const int numberofDigitalPins = 14;
const int numberofCommands = 29;

String helpText[numberofCommands]={"status;","reset;","setBaudRate;","pinMode","digitalWrite","analogWrite","startAnalogRead;","stopAnalogRead;","startDigitalRead;","stopDigitalRead;","startAllRead;","stopAllRead;","mapAnalogtoDigital","unMapAnalogtoDigital","mapAnalogtoPWM","unMapAnalogtoPWM","mapAnalogtoServo","unMapAnalogtoServo","driveServo","readServo","wirelessConnect;","wirelessDisconnect;","wirelessWrite","wirelessRead","help;"};

//String analogPinName[numberofAnalogPins]={"A0","A1","A2","A3","A4","A5"};


prog_char string_0[] PROGMEM = "A0"; 
prog_char string_1[] PROGMEM = "A1";
prog_char string_2[] PROGMEM = "A2";
prog_char string_3[] PROGMEM = "A3";
prog_char string_4[] PROGMEM = "A4";
prog_char string_5[] PROGMEM = "A5";

// Then set up a table to refer to your strings.

PROGMEM const char *analogPinName[] = 	   // change "string_table" name to suit
{   
  string_0,
  string_1,
  string_2,
  string_3,
  string_4,
  string_5 };

char buffer[4];    // make sure this is large enough for the largest string it must hold




	int analogPinValue[numberofAnalogPins];

	//String digitalPinName[numberofDigitalPins]={
	//	"D00", "D01","D02","D03","D04","D05","D06","D07","D08","D09","D10","D11","D11","D13"};


String digitalPinName[numberofDigitalPins]={};


		int digitalPinValue[numberofDigitalPins];
		int digitalPinMode[numberofDigitalPins];  // Where is that used?

		bool analogReading = 0; // Continuous analog reading happens in the main loop. A flag needs to be set to control start and stop.

		Servo servo[numberofDigitalPins];
		int ServoMapping[numberofDigitalPins][numberofDigitalPins]; // Maps servos and attached analog input for each servo

		Servo myservo;  // This is a test variable. I blew a servo I think and that's why my other solution with the matrix didn't work. Need to check.


		int mappedSensor[numberofAnalogPins]; // Where is this used?
		int mappedSensorPWM[numberofAnalogPins];  // Where is this used?

		int mappedAnalogInput, mappedDigitalOutput, mappedAnalogValue;  // Where are these things used?

		//int mappedServo

// Main Functions

void setup() {

  Serial.begin(baudRate); // initialize serial:
  inputString.reserve(200);  // reserve 200 bytes for the inputString:

}

void loop() {

	if (analogReading){

		for (int i=0;i<numberofAnalogPins;i++){
			analogPinValue[i]=analogRead(i);
			
			strcpy_P(buffer, (char*)pgm_read_word(&(analogPinName[i]))); // Necessary casts and dereferencing, just copy. 
    Serial.print( buffer );


			//Serial.print(analogPinName[i]);
			Serial.print(":");
			Serial.print(analogPinValue[i]);
			Serial.print(" ");
		}

		Serial.println();
	}

	if (mappedSensor[mappedAnalogInput]){
		mappedAnalogValue = analogRead(mappedAnalogInput);
		analogWrite(mappedDigitalOutput, mappedAnalogValue);
	}

	if (mappedSensorPWM[mappedAnalogInput]){
		mappedAnalogValue = analogRead(mappedAnalogInput);
		analogWrite(mappedDigitalOutput, mappedAnalogValue/4);
	}

	
	for (int i=0;i<numberofDigitalPins;i++){
		if (ServoMapping[i]){

			//int val = analogRead(ServoMapping[i][- analog sensor goes here? ]);
			int val = map(val, 0, 1023, 0, 180);
			//servo[i].write(val);
			// servo[i].write(analogRead(analogPin));
		}
	}

}



