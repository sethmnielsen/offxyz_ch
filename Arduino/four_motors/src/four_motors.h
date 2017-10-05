#ifndef FOUR_MOTORS_H
#define	FOUR_MOTORS_H

#include <Arduino.h>

//Motor pins
int S[] = {2, 3, 4, 5};     //Speed control PWM {Front-Left, Back-L, FR, BR}
int D[] = {32, 33, 34, 35}; //Direction Control

//encoder pins
int encON[] = {12, 0, 0, 0};
int chanA[] = {20, 24, 26, 28};
int chanB[] = {21, 25, 27, 29};
int chanALast[] = {LOW, LOW, LOW, LOW};
int n[] = {LOW, LOW, LOW, LOW};
volatile int pos[] = {0, 0, 0, 0};
int posmag = 0;
int initpos = 0;

bool accel_flag = false;
bool decel_flag = false;

enum action {FORWARD, REVERSE, RIGHT, LEFT, ROTATE, STOP} state;

const int conv_factor = 16;

const int v1 = 30;
const int v2 = 40;
const int v3 = 50;
const int v4 = 60;
const int v5 = 70;

const int d1 = 50;
const int d2 = 100;
const int d3 = 150;
const int d4 = 200;

/***************** DECLARATIONS **********************/
void encoder();
void changeDir();
void accel();
void decel();
void accelDiag(int M0, int M1, int M2, int M3);
void decelDiag(int M0, int M1, int M2, int M3);
// void readPosition();
// void readEncoder(int i);
void setSpeed(int i, int percent);
int speed(int percent);
void stop();
void forward(int dist);
void reverse(int dist);
void left(int dist);
void right(int dist);
void driveDiagFR();
void driveDiagFL();
void driveDiagBR();
void driveDiagBL();
void rotate(int ang);

/**************** DEFINITIONS ***********************/
// void readPosition() {
    // readEncoder(0);
// }

// void readEncoder(int i) {
  // if (i == 0) {
    // Serial.print(digitalRead(chanA[1]));
  // }
  // n[i] = digitalRead(chanA[i]);
  // if ((chanALast[i] == LOW) && (n[i] == HIGH)) {
    // if (digitalRead(chanB[i]) == LOW) {
      //  pos[i]--;
    // }
    // else {
      //  pos[i]++;
    // }
  // }
  // chanALast[i] = n[i];
// }

void setSpeed(int p, int percent) {
  analogWrite(p, speed(percent));
}

int speed(int percent) {
  return (percent * 2.00)/1;
}

/******* DIRECTIONAL DRIVE - ALL DISTANCES IN CM ********/
void changeDir() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(D[i], !digitalRead(D[i]));
    pos[i] = 0;
  }
}

void accel() {
  posmag = abs(pos[0]);
  for (int i = 0; i < 4; i++) {
    if      (posmag >= 0  && posmag < d1) {
      setSpeed(S[i], v1);
    }
    else if (posmag >= d1 && posmag < d2) {
      setSpeed(S[i], v2);
    }
    else if (posmag >= d2 && posmag < d3) {
      setSpeed(S[i], v3);
    }
    else if (posmag >= d3 && posmag < d4) {
      setSpeed(S[i], v4);
    }
    else if (posmag >= d4) {
      setSpeed(S[i], v5);
      accel_flag = false;
    }
  }
}

void decel() {
  if (initpos == 0) {
    initpos = abs(pos[0]);
  }
  posmag = abs(pos[0]) - initpos;
  for (int i = 0; i < 4; i++) {
    if      (posmag >= 0 && posmag < d1) {
      setSpeed(S[i], v4);
    }
    else if (posmag >= d1 && posmag < d2) {
      setSpeed(S[i], v3);
    }
    else if (posmag >= d2 && posmag < d3) {
      setSpeed(S[i], v2);
    }
    else if (posmag >= d3 && posmag < d4) {
      setSpeed(S[i], v1);
    }
    else if (posmag >= d4) {
      stop();
      decel_flag = false;
    }
  }
}

void accelDiag(int M0, int M1, int M2, int M3) {
  int posmag = abs(pos[0]);
  int M[] = {M0, M1, M2, M3};
  for (int i = 0; i < 4; i++) {
    if (M[i] == 1) {
      if      (posmag >= 0  && posmag < 25) {
        setSpeed(S[i], 20);
      }
      else if (posmag >= 25 && posmag < 50) {
        setSpeed(S[i], 40);
      }
      else if (posmag >= 50 && posmag < 75) {
        setSpeed(S[i], 60);
      }
      else if (posmag >= 75 && posmag < 100) {
        setSpeed(S[i], 80);
      }
      else if (posmag >= 100) {
        setSpeed(S[i], 100);
      }
    }
  }
}

void decelDiag(int M0, int M1, int M2, int M3) {
  posmag = abs(pos[0]);
  int M[] = {M0, M1, M2, M3};
  for (int i = 0; i < 4; i++) {
    if (M[i] == 1) {
      if      (posmag >= 900 && posmag < 925) {
        setSpeed(S[i], 80);
      }
      else if (posmag >= 925 && posmag < 950) {
        setSpeed(S[i], 60);
      }
      else if (posmag >= 950 && posmag < 975) {
        setSpeed(S[i], 40);
      }
      else if (posmag >= 975 && posmag < 1000) {
        setSpeed(S[i], 20);
      }
      else if (posmag >= 1000) {
        stop();
      }
    }
  }
}

void stop() {
  for (int i = 0; i < 4; i++) {
    setSpeed(S[i], 0);
  }
}

void forward(int dist) {
  if (pos[0] < 2) {
    initpos = 0;
    accel_flag = true;
    for (int i = 0; i < 4; i++) {
      digitalWrite(D[i], 1);
    }
  }
  if (accel_flag == true) {
    accel();
  }
  else if (pos[0] >= (dist*conv_factor - d4)) {
    if (initpos == 0 && decel_flag == false) {
      decel_flag = true;
    }
    if (decel_flag == true) {
      decel();
    }
    else {
      pos[0] = 0;
      state = REVERSE;
    }
  }
}

void reverse(int dist) {
  if (pos[0] < 2) {
    initpos = 0;
    accel_flag = true;
    for (int i = 0; i < 4; i++) {
      digitalWrite(D[i], 0);
    }
  }
  if (accel_flag == true) {
    accel();
  }
  else if (pos[0] >= (dist*conv_factor - d4)) {
    if (initpos == 0 && decel_flag == false) {
      decel_flag = true;
    }
    if (decel_flag == true) {
      decel();
    }
    else {
      pos[0] = 0;
      state = RIGHT;
    }
  }
}

void right(int dist) {
  if (pos[0] < 2) {
    initpos = 0;
    accel_flag = true;
    digitalWrite(D[0], 0);
    digitalWrite(D[3], 0);
    digitalWrite(D[1], 0);
    digitalWrite(D[2], 1);
  }
  if (accel_flag == true) {
    accel();
  }
  else if (pos[0] >= (dist*conv_factor - d4)) {
    if (initpos == 0 && decel_flag == false) {
      decel_flag = true;
    }
    if (decel_flag == true) {
      decel();
    }
    else {
      pos[0] = 0;
      state = LEFT;
    }
  }
}

void left(int dist) {
  if (pos[0] < 2) {
    initpos = 0;
    accel_flag = true;
    digitalWrite(D[0], 0);
    digitalWrite(D[3], 1);
    digitalWrite(D[1], 0);
    digitalWrite(D[2], 0);
  }
  if (accel_flag == true) {
    accel();
  }
  else if (pos[0] >= (dist*conv_factor - d4)) {
    if (initpos == 0 && decel_flag == false) {
      decel_flag = true;
    }
    if (decel_flag == true) {
      decel();
    }
    else {
      pos[0] = 0;
      state = STOP;
    }
  }
}

void driveDiagFR() {

}

void driveDiagFL() {

}

void driveDiagBR () {

}

void driveDiagBL() {

}

void rotate(int ang) {

}


#endif
