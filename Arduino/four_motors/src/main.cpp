#include "four_motors.h"

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(chanB[i], INPUT);
    pinMode(S[i], OUTPUT);
    pinMode(D[i], OUTPUT);
    pos[i] = 0;
  }
  pinMode(chanA[0], INPUT_PULLUP);
  attachInterrupt(3, encoder, RISING);

  state = FORWARD;
  delay(2000);
  Serial.begin(9600);
}

void loop() {
  switch (state) {
    case FORWARD:
      forward(200);
      // Serial.print(pos[0]);
      // Serial.print("\n\r");
      break;
    case REVERSE:
      reverse(200);
      break;
    case RIGHT:
      right(200);
      break;
    case LEFT:
      left(200);
      break;
    case ROTATE:
      break;
    case STOP:
    // Serial.print("******************STOP**********************");
    // Serial.print("\r\n");
    stop();
    break;
  }
}

void encoder() {
  pos[0]++;
}
