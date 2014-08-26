//Custom Functions

/*
 The SerialEvent occurs when new data arrive at the Arduino from the serial port.  The code runs between each
 loop() execution. Using delay inside the loop will delay response from this code. Multiple bytes of data may be available.
 */

 void serialEvent() {

  while (Serial.available()) {

    char inChar = (char)Serial.read(); // get the new byte and add it to inputString
    inputString += inChar; // if the incoming character is ";" assume input complete. You are expecting 3 words (or arguments). Disregard anything else.

    if (inChar == ';') {

      int i=0;

      int firstCommaIndex;
      int secondCommaIndex;

      while(i<inputString.length()){

        firstCommaIndex = inputString.indexOf(' ');
        secondCommaIndex = inputString.indexOf(' ', firstCommaIndex+1); //  Search for the next comma just after the first
        i++;

      }


      String firstValue = inputString.substring(0, firstCommaIndex);
      String secondValue = inputString.substring(firstCommaIndex+1, secondCommaIndex);
      String thirdValue = inputString.substring(secondCommaIndex);

      if (firstValue == "help;"){

        printHelp();

        } else {
          checkIncomingSerialMessages(firstValue, secondValue.toInt(), thirdValue.toInt());
        }
      
      // clear the input string to be ready for next serial input:
      inputString = "";

    } 
  }
}



void checkIncomingSerialMessages(String firstValue, int secondValue, int thirdValue) {

  if (firstValue == "pinMode"){
    setDigitalPinMode(secondValue, thirdValue);
  }

  if (firstValue == "digitalPinWrite"){
    digitalPinWrite(secondValue, thirdValue);
  }

  if (firstValue == "analogPinWrite"){
    analogWritetoDigitalPin(secondValue, thirdValue);
  }

  if (firstValue == "help"){
    printHelp();
  }

  if (firstValue == "driveServo"){
    driveServo(secondValue, thirdValue);
  }

   if (firstValue == "setBaudRate"){
    setBaudRate(secondValue);
  }


   if (firstValue == "startAnalogRead"){
    startAnalogRead();
  }

}



void startAnalogRead(){
analogReading = 1;
}


void displayDigitalPinModeandValue(){

  for (int i=0;i<numberofDigitalPins;i++){
    digitalPinValue[i]=digitalRead(i);
    Serial.print(digitalPinName[i]);
    Serial.print("(M");
      Serial.print(digitalPinMode[i]);
      Serial.print("):");
      Serial.print(digitalPinValue[i]);
      Serial.print(" ");
    }

  }

  void setDigitalPinMode(int pin, int mode){

    for (int i=0;i<numberofDigitalPins;i++){
      if (mode == 1){
        pinMode(i,OUTPUT);
        digitalPinMode[i]=1;
      }

    }

  }



  void setBaudRate(int value){

  Serial.end(); // Close serial before resetting speed
  baudRate = value;
  Serial.begin(baudRate); // initialize serial

  Serial.println();
  Serial.println("Baud rate changed.");
  Serial.println();
}


void analogWritetoDigitalPin(int pin, int value){


  if (value > -1 & value < 256){
  analogWrite(pin, value);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  } else {


   Serial.println();
   Serial.println("Value sent to digital pin for writing is out of bounds 0-255 bound.");
   Serial.println();

 }

}

void digitalPinWrite(int pin, int value){

 digitalWrite(pin, value);    

}

void connectAnalogInputtoDigitalOutput(int analoguePin, int digitalPin){

  int analogValue;
  analogValue = analogRead(analoguePin);
  analogWrite(digitalPin, analogValue);

}

void printHelp(){

  Serial.println();
  Serial.println("// HELP MENU //");
  Serial.println();
  Serial.println("Available commands (typical format:action destination value):");
  Serial.println();
  Serial.println("1. pinMode 13 1;               // Sets digital pin 13 to output");
  Serial.println("2. digitalPinWrite 13 1;       // Sends 5V to pin 13");
  Serial.println("3. analogPinWrite 13 255;      // Sends 5V to pin 13");
  Serial.println("4. setBaudRate 19200;          // Sets baud rate to 19200");
  Serial.println("5. startAnalogRead;            // Starts transmitting data read from analog sensors");
  Serial.println("6. stopAnalogRead;             // Stops transmitting data read from analog sensors");
  Serial.println("7. mapAnalogtoDigital 1 13;    // Maps analog input 1 to digital output pin 13");
  Serial.println("8. unMapAnalogtoDigital 1 13;  // Unmaps analog input 1 from digital output pin 13");
  Serial.println("9. driveServo 1 100;           // Sets digital pin 1 to servo mode and rotates servo to 100 degrees");
  Serial.println("10. driveServo 1;              // Transmits the position (angles) of a servo attached to digital pin 1 via serial");
  Serial.println("11. help;                      // This menu");
  Serial.println();

}


void driveServo(int pin, int value){

  Servo servo1;
  pinMode(pin,OUTPUT);
  servo1.attach(pin); //analog pin 0 ?????
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  servo1.write(value);

}

void readServo(){

  // Don't forget to write this one
}