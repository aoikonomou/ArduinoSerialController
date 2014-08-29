#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
/* ^^ these are the include guards */

/* Prototypes for the functions */

void serialEvent(); // This is an event handler, it is not called by the code anywhere, it responds to serial communication events from the host automatically.
void checkIncomingSerialMessages(String firstValue, int secondValue, int thirdValue);
void status();
void reset();
void setBaudRate(long value);
void setDigitalPinMode(int pin, int mode);

void startAnalogRead();
void stopAnalogRead();
void startDigitalRead();
void stopDigitalRead();
void startAllRead();
void stopAllRead();

void displayDigitalPinModeandValue();

void analogWritetoDigitalPin(int pin, int value);
void digitalPinWrite(int pin, int value);
void mapAnalogtoDigital(int analogPin, int digitalPin);
void unMapAnalogtoDigital(int analogPin, int digitalPin);
void mapAnalogtoPWM(int analogPin, int digitalPin);
void unMapAnalogtoPWM(int analogPin, int digitalPin);
void mapAnalogtoServo(int analogPin, int digitalPin);
void unMapAnalogtoServo(int analogPin, int digitalPin);

void driveServo(int pin, int value);
void readServo(int pin);

void wirelessConnect();
void wirelessDisconnect();
void wirelessWrite();
void wirelessRead();


#endif