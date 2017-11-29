/* XBee is connected to Serial2 because Serial1 is used
*  by micro USB port.
*  
*  Open the Serial Monitor on computer after programming
*  Teensy with this code, and if the letter 'a' appears
*  repeatedly, then that indicates good communication.
*/
char letter;

void setup() {
  // Set baud rate for sending data
  Serial2.begin(115200); 
}

void loop() {
  Serial2.write('a');
  delay(400);

  // Open Serial Monitor on computer to 
  if(Serial2.available())
  {
    letter=Serial2.read();
    Serial2.print(letter);
  }
}
