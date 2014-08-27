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

    
          checkIncomingSerialMessages(firstValue, secondValue.toInt(), thirdValue.toInt());
        
      
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

  if (firstValue == "help;"){
    printHelp();
  }

  if (firstValue == "driveServo"){
    driveServo(secondValue, thirdValue);
  }


  if (firstValue == "readServo"){
    readServo(secondValue);
  }

   if (firstValue == "setBaudRate"){
    setBaudRate(secondValue);
  }


   if (firstValue == "startAnalogRead;"){
    startAnalogRead();
  }

   if (firstValue == "stopAnalogRead;"){
    stopAnalogRead();
  }


 if (firstValue == "mapAnalogtoDigital"){
    mapAnalogtoDigital(secondValue, thirdValue);
  }

  if (firstValue == "unMapAnalogtoDigital"){
    unMapAnalogtoDigital(secondValue, thirdValue);
  }

}


void startAnalogRead(){
analogReading = 1;
}

void stopAnalogRead(){
analogReading = 0;
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

void mapAnalogtoDigital(int analogPin, int digitalPin){

mappedAnalogInput = analogPin;
mappedDigitalOutput = digitalPin;
 
mappedSensor[analogPin] = 1;

}


void unMapAnalogtoDigital(int analogPin, int digitalPin){

// mappedAnalogInput = analoguePin;
// mappedDigitalOutput = digitalPin;
 
mappedSensor[analogPin] = 0;

}

void printHelp(){

  Serial.println();
  Serial.println("// HELP MENU //");
  Serial.println();
  Serial.println("Available commands:");
  Serial.println();
  Serial.println("1. pinMode <digital pin> <value>;");
  Serial.println("2. digitalPinWrite <digital pin> <value>;");
  Serial.println("3. analogPinWrite <digital pin> <value>;");
  Serial.println("4. setBaudRate <value>;");
  Serial.println("5. startAnalogRead;");
  Serial.println("6. stopAnalogRead;");
  Serial.println("7. mapAnalogtoDigital <analogue pin> <Digital Pin>;");
  Serial.println("8. unMapAnalogtoDigital <analogue pin> <digital pin>;");
  Serial.println("9. driveServo <digital pin> <value>;");
  Serial.println("10. readServo <digital pin>;");
  Serial.println("11. help;");
  Serial.println();

}


void driveServo(int pin, int value){

 
  pinMode(pin,OUTPUT);
  servo1.attach(pin); //analog pin 0 ?????
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  servo1.write(value);

}

void readServo(int pin){

  // This is not finished yet
  Serial.println(servo1.read());

}