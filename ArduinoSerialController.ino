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


prog_char analogPinName_0[] PROGMEM = "A0"; 
prog_char analogPinName_1[] PROGMEM = "A1";
prog_char analogPinName_2[] PROGMEM = "A2";
prog_char analogPinName_3[] PROGMEM = "A3";
prog_char analogPinName_4[] PROGMEM = "A4";
prog_char analogPinName_5[] PROGMEM = "A5";

// Then set up a table to refer to your strings.

PROGMEM const char *analogPinName[] = 	   // change "analogPinName_table" name to suit
{   
  analogPinName_0,
  analogPinName_1,
  analogPinName_2,
  analogPinName_3,
  analogPinName_4,
  analogPinName_5 
};

char buffer[4];    // make sure this is large enough for the largest string it must hold




	int analogPinValue[numberofAnalogPins];

	//String digitalPinName[numberofDigitalPins]={
	//	"D00", "D01","D02","D03","D04","D05","D06","D07","D08","D09","D10","D11","D11","D13"};

prog_char digitalPinName_0[] PROGMEM = "D00";
prog_char digitalPinName_1[] PROGMEM = "D01";
prog_char digitalPinName_2[] PROGMEM = "D02";
prog_char digitalPinName_3[] PROGMEM = "D03";
prog_char digitalPinName_4[] PROGMEM = "D04";
prog_char digitalPinName_5[] PROGMEM = "D05";
prog_char digitalPinName_6[] PROGMEM = "D06";
prog_char digitalPinName_7[] PROGMEM = "D07";
prog_char digitalPinName_8[] PROGMEM = "D08";
prog_char digitalPinName_9[] PROGMEM = "D09";
prog_char digitalPinName_10[] PROGMEM = "D10";
prog_char digitalPinName_11[] PROGMEM = "D11";
prog_char digitalPinName_12[] PROGMEM = "D12";
prog_char digitalPinName_13[] PROGMEM = "D13";

PROGMEM const char *digitalPinName[] = 	   // change "analogPinName_table" name to suit
{ 

 digitalPinName_0,
 digitalPinName_1,
 digitalPinName_2,
 digitalPinName_3,
 digitalPinName_4,
 digitalPinName_5,
 digitalPinName_6,
 digitalPinName_7,
 digitalPinName_8,
 digitalPinName_9,
 digitalPinName_10,
 digitalPinName_11,
 digitalPinName_12,
 digitalPinName_13

};


//String digitalPinName[numberofDigitalPins]={};


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



