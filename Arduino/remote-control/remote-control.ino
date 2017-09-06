#include "remote-control.h"

void setup() {
  configPins();
  configTimers();

  digitalWrite(step, step_state);

  digitalWrite(dir0, 1);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 1);
  digitalWrite(dir3, 1);

  digitalWrite(enab, 1);

  state = STOP;
  Serial2.begin(115200);
}

void loop() {
  if (Serial2.available() > 0) {
    incomingByte = Serial2.read();
    if      (incomingByte == 'W' || incomingByte == 'w') {
      state = FORWARD;
    }
    else if (incomingByte == 'S' || incomingByte == 's') {
      state = REVERSE;
    }
    else if (incomingByte == 'A' || incomingByte == 'a') {
      state = LEFT;
    }
    else if (incomingByte == 'D' || incomingByte == 'd') {
      state = RIGHT;
    }
    else if (incomingByte == 'Q' || incomingByte == 'q') {
      state = ROTATECCW;
    }
    else if (incomingByte == 'E' || incomingByte == 'e') {
      state = ROTATECW;
    }
    stop_cnt = 0;
    digitalWrite(lidr, 1);
  }
  else {
    stop_cnt++;
    if (stop_cnt > 270000) {
      state = STOP;
    }
  }

  switch (state) {
    case FORWARD:
      forward();
      break;
    case REVERSE:
      reverse();
      break;
    case RIGHT:
      right();
      break;
    case LEFT:
      left();
      break;
    case ROTATECW:
      rotatecw();
      break;
    case ROTATECCW:
      rotateccw();
      break;
    case STOP:
      stop();
    break;
  }
}
