
void printHelp(){

  Serial.println();
  Serial.println("COMMANDS:");
  Serial.println();
  Serial.println("1. status;");
  Serial.println("2. reset;");
  Serial.println("3. setBaudRate <value>;");
  Serial.println("4. pinMode <dpin> <val>;");
  Serial.println();
  Serial.println("5. digitalWrite <dpin> <val>;");
  Serial.println("6. analogWrite <dpin> <val>;");
  Serial.println();
  Serial.println("7. startAnalogRead;");
  Serial.println("8. stopAnalogRead;");
  Serial.println("9. startDigitalRead;");
  Serial.println("10. stopDigitalRead;");
  Serial.println("11. startAllAnalogRead;");
  Serial.println("12. stopAllAnalogRead;");
  Serial.println("13. startAllDigitalRead;");
  Serial.println("14. stopAllDigitalRead;");
  Serial.println("15. startAllRead;");
  Serial.println("16. stopAllRead;");
  Serial.println();
  Serial.println("17. mapAnalogtoDigital <apin> <dpin>;");
  Serial.println("18. unMapAnalogtoDigital <apin> <dpin>;");
  Serial.println("19. mapAnalogtoPWM <apin> <dpin>;");
  Serial.println("20. unMapAnalogtoPWM <apin> <dpin>;");
  Serial.println("21. mapAnalogtoServo <apin> <dpin>;");
  Serial.println("22. unMapAnalogtoServo <apin> <dpin>;");
  Serial.println();
  Serial.println("23. servoWrite <dpin> <val>;");
  Serial.println("24. servoRead <dpin>;");
  Serial.println();
  Serial.println("25. wirelessConnect;");
  Serial.println("26. wirelessDisconnect;");
  Serial.println("27. wirelessWrite;");
  Serial.println("28. wirelessRead;");
  Serial.println();
  Serial.println("29. help;");
  Serial.println();

}

