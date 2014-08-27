/* 
Arduino Serial Controller v 0.1
Control your Arduino Uno by sending text commands to it down the serial port
Code is free for any use. Use at your own risk. It is experimental and may destroy your hardware
Written by Andreas Oikonomou 2014. Some code (e.g. serialEvent) adapted from examples online.

Warning: Do not exceed 75% of Arduino's memory or strange things happen with the variables and the code doesn't work as expected!
*/

// Includes & Variable Declarations

#include "customFunctions.h"
#include <Servo.h>

int baudRate = 9600;

String inputString = "";         // a string to hold incoming serial data

const int numberofAnalogPins = 6;
const int numberofDigitalPins = 14;

String analogPinName[numberofAnalogPins]={
	"A0","A1","A2","A3","A4","A5"};

int analogPinValue[numberofAnalogPins];

String digitalPinName[numberofDigitalPins]={
		"D00", "D01","D02","D03","D04","D05","D06","D07","D08","D09","D10","D11","D11","D13"};

int digitalPinValue[numberofDigitalPins];
int digitalPinMode[numberofDigitalPins];

bool analogReading = 0;

Servo servo1, servo2, servo3, servo4, servo5, servo6, servo7, servo8, servo9, servo10, servo11, servo12, servo13;

bool mappedSensor = 0;
int mappedAnalogInput, mappedDigitalOutput, mappedAnalogValue;

// Main Functions

void setup() {

  Serial.begin(baudRate); // initialize serial:
  inputString.reserve(200);  // reserve 200 bytes for the inputString:

}

void loop() {

	if (analogReading){

		for (int i=0;i<numberofAnalogPins;i++){
			analogPinValue[i]=analogRead(i);
			Serial.print(analogPinName[i]);
			Serial.print(":");
			Serial.print(analogPinValue[i]);
			Serial.print(" ");
		}

		Serial.println();
	}

  if (mappedSensor){
 mappedAnalogValue = analogRead(mappedAnalogInput);
 analogWrite(mappedDigitalOutput, mappedAnalogValue);
  }

}



