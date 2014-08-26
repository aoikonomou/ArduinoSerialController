// Includes & Variable Declarations

#include "customFunctions.h"
#include <Servo.h>

int baudRate = 9600;

String inputString = "";         // a string to hold incoming serial data
//inputString.reserve(200);  // reserve 200 bytes for the inputString:


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



// Main Functions

void setup() {

  Serial.begin(baudRate); // initialize serial:
  //inputString.reserve(200);  // reserve 200 bytes for the inputString:

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
	}



}





