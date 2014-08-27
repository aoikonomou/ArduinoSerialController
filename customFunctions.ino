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
 
mappedSensor[analogPin] = 0;

}


void mapAnalogtoPWM(int analogPin, int digitalPin){

mappedAnalogInput = analogPin;
mappedDigitalOutput = digitalPin;
 
mappedSensorPWM[analogPin] = 1;

}


void unMapAnalogtoPWM(int analogPin, int digitalPin){
 
mappedSensorPWM[analogPin] = 0;

}

void printHelp(){

  Serial.println();
  Serial.println("COMMANDS:");
  Serial.println();
  Serial.println("1. status;");
  Serial.println("2. reset;");
  Serial.println("3. pinMode <dpin> <val>;");
  Serial.println("4. digitalWrite <dpin> <val>;");
  Serial.println("5. analogWrite <dpin> <val>;");
  Serial.println("6. setBaudRate <value>;");
  Serial.println("7. startAnalogRead;");
  Serial.println("8. stopAnalogRead;");
  Serial.println("9. startDigitalRead;");
  Serial.println("10. stopDigitalRead;");
  Serial.println("11. startAllRead;");
  Serial.println("12. stopAllRead;");
  Serial.println("13. mapAnalogtoDigital <apin> <dpin>;");
  Serial.println("14. unMapAnalogtoDigital <apin> <dpin>;");
  Serial.println("15. mapAnalogtoPWM <apin> <dpin>;");
  Serial.println("16. unMapAnalogtoPWM <apin> <dpin>;");
  Serial.println("17. mapAnalogtoServo <apin> <dpin>;");
  Serial.println("18. unMapAnalogtoServo <apin> <dpin>;");
  Serial.println("19. servoWrite <dpin> <val>;");
  Serial.println("20. servoRead <dpin>;");
  Serial.println("21. help;");
  Serial.println();

}



void mapAnalogtoServo(int analogPin, int digitalPin){

  pinMode(analogPin,OUTPUT);
  servo[analogPin].attach(digitalPin); //analog pin 0 ?????
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

   servo[analogPin].write(analogRead(analogPin));

}
void unMapAnalogtoServo(int analogPin, int digitalPin){

}



void driveServo(int pin, int value){

 
  pinMode(pin,OUTPUT);
  
 // myservo.attach(6);
  servo[pin].attach(pin); //analog pin 0 ?????
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  servo[pin].write(value);
  //myservo.write(70);
  Serial.println(pin);
  Serial.println(value);

}

void readServo(int pin){

  // This is not finished yet
  Serial.println( servo[pin].read());

}



void status(){

 for (int i=0;i<numberofDigitalPins;i++){

  // show me the pinmode for all the digital pins
  Serial.println("D00s");
  // show me the current values of those pins
 }

}
void reset(){

  for (int i=0;i<numberofDigitalPins;i++){

    pinMode(i, 1);
    Serial.println();
    Serial.println("All digital pins set to output.");
    Serial.println();
    // Need to reset any other variables here


  }

}