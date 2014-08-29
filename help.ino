
void printHelp(){

 Serial.println();
 Serial.println("COMMANDS:");
 Serial.println();

  for (int i=0;i<numberofCommands+1;i++){


  if (i == 4 || i == 6 || i == 12 || i == 18 || i == 20 || i == 24){
 Serial.println();

  }

  Serial.print(i);
  Serial.print(". "); 

  strcpy_P(buffer, (char*)pgm_read_word(&(helpText[i]))); // Necessary casts and dereferencing, just copy. 
            Serial.println(buffer);

  }

}

