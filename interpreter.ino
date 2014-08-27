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
  if (firstValue == "mapAnalogtoPWM"){
    mapAnalogtoPWM(secondValue, thirdValue);
  }
  if (firstValue == "unMapAnalogtoPWM"){
    unMapAnalogtoPWM(secondValue, thirdValue);
  }
  if (firstValue == "mapAnalogtoServo"){
    mapAnalogtoServo(secondValue, thirdValue);
  }
  if (firstValue == "unMapAnalogtoServo"){
    unMapAnalogtoServo(secondValue, thirdValue);
  }
  if (firstValue == "status;"){
    status();
  }
  if (firstValue == "reset;"){
    reset();
  }

}