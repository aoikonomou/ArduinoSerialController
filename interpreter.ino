//Custom Functions

/*
 The SerialEvent occurs when new data arrive at the Arduino from the serial port.  The code runs between each
 loop() execution. Using delay inside the loop will delay response from this code. Multiple bytes of data may be available.
 */

 void serialEvent() {

  while (Serial.available()) {

    char inChar = (char)Serial.read(); // get the new byte and add it to inputString
    inputString += inChar; // if the incoming character is ";" assume input complete. You are expecting 3 words (or arguments). Disregard anything else.

Serial.println(inputString);
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



  for (int i=0;i<numberofCommands;i++){

    if(firstValue == helpText[i]){


      switch (i) {

        case 0:
        status();
        break;

        case 1:
        reset();
        break;

        case 2:
        setBaudRate(secondValue);
        break;

        case 3:
        setDigitalPinMode(secondValue, thirdValue);
        break;

        case 4:
        digitalPinWrite(secondValue, thirdValue);
        break;

        case 5:
        analogWritetoDigitalPin(secondValue, thirdValue);
        break;

        case 6:
        startAnalogRead();
        break;

        case 7:
        stopAnalogRead();
        break;

        case 8:
        startDigitalRead();
        break;

        case 9:
        stopDigitalRead();
        break;

        case 10:
        startAllRead();
        break;

        case 11:
        stopAllRead();
        break;

        case 12:
        mapAnalogtoDigital(secondValue, thirdValue);
        break;

        case 13:
        unMapAnalogtoDigital(secondValue, thirdValue);
        break;

        case 14:
        mapAnalogtoPWM(secondValue, thirdValue);
        break;

        case 15:
        unMapAnalogtoPWM(secondValue, thirdValue);
        break;

        case 16:
        mapAnalogtoServo(secondValue, thirdValue);
        break;

        case 17:
        unMapAnalogtoServo(secondValue, thirdValue);
        break;

        case 18:
        driveServo(secondValue, thirdValue);
        break;

        case 19:
        readServo(secondValue);
        break;

        case 20:
        wirelessConnect();
        break;

        case 21:
        wirelessDisconnect();
        break;

        case 22:
        wirelessWrite();
        break;

        case 23:
        wirelessRead();
        break;

        case 24:
        //Serial.println("I got it");
        printHelp();
        break;

        default:
        //Code to execute if <variable> does not equal the value following any of the cases
        Serial.println("At least I am getting here?");
        break;
      }
    }
  }
}



