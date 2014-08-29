


void status(){

 for (int i=0;i<numberofDigitalPins;i++){

  // show me the pinmode for all the digital pins
  //Serial.println("D00s");
  // show me the current values of those pins
}

}
void reset(){

  for (int i=0;i<numberofDigitalPins;i++){

    pinMode(i, 1);
    Serial.println();
    //Serial.println("All digital pins set to output.");
    Serial.println();
    // Need to reset any other variables here

  }

}

void setBaudRate(int value){

  Serial.end(); // Close serial before resetting speed
  baudRate = value;
  Serial.begin(baudRate); // initialize serial

  Serial.println();
  //Serial.println("Baud rate changed.");
  Serial.println();
}


void setDigitalPinMode(int pin, int mode){

  for (int i=0;i<numberofDigitalPins;i++){
    if (mode == 1){
      pinMode(i,OUTPUT);
      digitalPinMode[i]=1;
    }

  }

}

///////////////////////////////////////////////  

void startAnalogRead(){
  analogReading = 1;
}

void stopAnalogRead(){
  analogReading = 0;
}

void startDigitalRead(){
digitalReading = 1;
}

void stopDigitalRead(){
digitalReading = 0;
}

void startAllRead(){
allReading = 1;
}

void stopAllRead(){
analogReading = 0;
digitalReading = 0;
allReading = 0;
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


  void analogWritetoDigitalPin(int pin, int value){

    if (value > -1 & value < 256){
  analogWrite(pin, value);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  } else {

   Serial.println();
   //Serial.println("Value sent to digital pin for writing is out of bounds 0-255 bound.");
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
  
  myservo.attach(6);
  
  //servo[pin].attach(pin); //analog pin 0 ?????
  
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  //servo[pin].write(value);
  myservo.write(70);
  Serial.println(pin);
  Serial.println(value);

}

void readServo(int pin){

  // This is not finished yet
  Serial.println( servo[pin].read());

}

void wirelessConnect(){};
void wirelessDisconnect(){};
void wirelessWrite(){};
void wirelessRead(){};

