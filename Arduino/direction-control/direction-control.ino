#include "direction-control.h"

void setup() {
  configPins();
  configTimers();

  digitalWrite(step, 0);

  digitalWrite(dir0, 1);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 1);
  digitalWrite(dir3, 1);

  digitalWrite(ena0, 1);
  digitalWrite(ena1, 1);
  digitalWrite(ena2, 1);
  digitalWrite(ena3, 1);

  // pos = 64000;
  state = forward;
}

void loop() {
  switch (state) {
    case FORWARD:
      forward(100);
      break;
    case REVERSE:
      reverse(100);
      break;
    case RIGHT:
      right(100);
      break;
    case LEFT:
      left(100);
      break;
    case ROTATECW:
      rotatecw(180);
      break;
    case ROTATECCW:
      rotateccw(180);
      break;
    case STOP:
      stop();
    break;
  }
}
