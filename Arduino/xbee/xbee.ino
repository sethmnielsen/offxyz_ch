char letter;

void setup() {
  Serial2.begin(115200);
}

void loop() {
  Serial2.write('a');
  delay(400);

  if(Serial2.available())
  {
    letter=Serial2.read();
    Serial2.print(letter);
  }
}
