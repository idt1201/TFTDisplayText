/*
void getUserInput()
{
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    if (rx_byte != '\n') {
      rx_str += rx_byte;
    }
    else {
      // end of string
      maxLed=rx_str.toInt();
      rx_str = "";                // clear the string for reuse
      if(maxLed <50) { maxLed=50; }
      if(maxLed > 250) { maxLed=250;}
    }
  }
}
//---------------------------------------------------------------------------------------------------------------
void serialMenu(){
  menu[1]="1. Change minimum LED output (" + String(minLed) + ")";
  menu[2]="2. Change maximum LED output (" + String(maxLed) + ")";
  menu[3]="Enter 1 or 2 :";
  Serial.println(menu[1]);
  Serial.println(menu[2]);
  Serial.println(menu[3]);
}
*/
