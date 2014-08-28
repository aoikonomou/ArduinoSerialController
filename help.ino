
void printHelp(){

 Serial.println();
 Serial.println("COMMANDS:");
 Serial.println();

  for (int i=0;i<numberofCommands;i++){

  Serial.print(i);
  Serial.print(". "); 
  Serial.println(helpText[i]);
  
}

}

