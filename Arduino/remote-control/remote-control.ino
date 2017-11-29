/*
* This file runs the main loop, which checks for any drive commands
* sent through the XBee (Serial2).
*
* The drive commands are sent by a computer. Using a keyboard, the commands are:
* W = Forward
* A = Left
* S = Reverse
* D = Right
* Q = Rotate Counter-Clockwise
* E = Rotate Clockwise
*
* It is designed to wait for a key to be pressed, begin driving once the key press
* is detected, and then stop once the key is no longer being pressed.
*/
#include "remote-control.h"

void setup() {
  configPins();     // Assigns pins to be OUTPUT
  configTimers();   // Creates one timer for PWM (step), one for accelerating (speed increment)

  digitalWrite(step, step_state); // Initializes stepper motors

  // All steppers intialized with Forward direction
  digitalWrite(dir0, 1);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 1);
  digitalWrite(dir3, 1);

  digitalWrite(enab, 1); // Stepper drivers enable pin HIGH

  state = STOP;          // Initialized to STOP state
  Serial2.begin(115200); // Set baud rate for XBee data transfer
}

void loop() {
  // Checks XBee for any incoming data
  if (Serial2.available() > 0) {
    incomingByte = Serial2.read(); // read incoming data
    // Begin checking if data is any of the recognized keys of WASDQE
    if      (incomingByte == 'W' || incomingByte == 'w') {
      state = FORWARD;
    }
    else if (incomingByte == 'A' || incomingByte == 'a') {
      state = LEFT;
    }
    else if (incomingByte == 'S' || incomingByte == 's') {
        state = REVERSE;
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
    stop_cnt = 0; // stop_cnt is set to zero during keypress
  }
  // If no recognized keys are pressed, then increment stop_cnt
  else {
    /* stop_cnt is set to zero during keypress and begins incrementing once
    *  keypress is no longer detected. Once stop_cnt reaches 270,000 (a very small
    *  time period found through trial and error), then the program considers that
    *  to mean that there is no longer any key being pressed.
    */
    stop_cnt++;
    if (stop_cnt > 270000) {
      state = STOP; // No key is being pressed, so stop driving
    }
  }

  // The state is set above by which key is currently being pressed
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
