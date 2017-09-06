#ifndef DIRECTION_CONTROL_H
#define	DIRECTION_CONTROL_H

#include <Arduino.h>

#define step   11

#define dir0   32
#define dir1   33
#define dir2   38
#define dir3   39

#define ena0   30
#define ena1   31
#define ena2   36
#define ena3   37

const int v0 = -1600;
const int vmax = -180;
const int accl = 40;
const int conv_cm = 408;
const int conv_deg = 180;

unsigned int cnt = 0;
unsigned int pos = 0;
int slowdown = -50*accl + 4500;

int currentVel = v0;
int targetVel  = 0;

enum action {FORWARD, REVERSE, RIGHT, LEFT, ROTATECW, ROTATECCW, STOP} state;

// /***************** DECLARATIONS **********************/
void configPins();
void configTimers();
void speed(int percent);
void stop();
void forward(int dist);
void reverse(int dist);
void left(int dist);
void right(int dist);
// void driveDiagFR();
// void driveDiagFL();
// void driveDiagBR();
// void driveDiagBL();
void rotate(int ang);

// /**************** DEFINITIONS ***********************/
void configPins() {
  pinMode(step, OUTPUT);
  pinMode(dir0, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(ena0, OUTPUT);
  pinMode(ena1, OUTPUT);
  pinMode(ena2, OUTPUT);
  pinMode(ena3, OUTPUT);
}

void configTimers() {
  // Timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  // 312.5 ~= 1 rev/sec at 3200 pulse/rev

  // WGM = Wave Generation Mode: control overall mode of the timer
  // CS = Clock Select: control clock prescaler
  TCCR1A |= (1 << COM1A0);
  TCCR1B |= (1 << WGM12) // CTC mode
         |  (1 << CS11);
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt


  // Timer3
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3  = 0;
  OCR3A = 8111;
  TCCR3B |= (1 << WGM32)
         |  (1 << CS30)
         |  (1 << CS31); //64
  TIMSK3 |= (1 << OCIE3A);
}

ISR(TIMER1_COMPA_vect) { // timer compare interrupt service routine
  cnt++;
}

ISR(TIMER3_COMPA_vect) {
  if (cnt < (pos - slowdown)) {
    if (currentVel < targetVel) {
      currentVel += accl;
    }
  }
  else {
    currentVel -= accl;
  }
  OCR1A = -currentVel;
}

/******* DIRECTIONAL DRIVE - ALL DISTANCES IN CM ********/

void speed(int percent) {
  if (percent > 100) {
    percent = 100;
  }
  else if (percent < 0) {
    percent = 0;
  }
  targetVel = ((vmax - v0) / 100)*percent + v0;
}

void stop() {
  digitalWrite(ena0, 0);
  digitalWrite(ena1, 0);
  digitalWrite(ena2, 0);
  digitalWrite(ena3, 0);
}

void forward(int dist) {
  if (cnt == 0) {
    digitalWrite(dir0, 1);
    digitalWrite(dir1, 1);
    digitalWrite(dir2, 1);
    digitalWrite(dir3, 1);
    digitalWrite(ena0, 1);
    digitalWrite(ena1, 1);
    digitalWrite(ena2, 1);
    digitalWrite(ena3, 1);
    speed(100);
    pos = dist*conv_cm;
  }
  else if (cnt >= pos){
    cnt = 0;
    stop();
    state = REVERSE;
  }
}

void reverse(int dist) {
  if (cnt == 0) {
    digitalWrite(dir0, 0);
    digitalWrite(dir1, 0);
    digitalWrite(dir2, 0);
    digitalWrite(dir3, 0);
    digitalWrite(ena0, 1);
    digitalWrite(ena1, 1);
    digitalWrite(ena2, 1);
    digitalWrite(ena3, 1);
    speed(100);
    pos = dist*conv_cm;
  }
  else if (cnt >= pos){
    cnt = 0;
    stop();
    state = RIGHT;
  }
}

void right(int dist) {
  if (cnt == 0) {
    digitalWrite(ena0, 1);
    digitalWrite(ena1, 1);
    digitalWrite(ena2, 1);
    digitalWrite(ena3, 1);
    digitalWrite(dir0, 0);
    digitalWrite(dir1, 1);
    digitalWrite(dir2, 1);
    digitalWrite(dir3, 0);
    speed(100);
    pos = dist*conv_cm;
  }
  else if (cnt >= pos){
    cnt = 0;
    stop();
    state = LEFT;
  }
}

void left(int dist) {
  if (cnt == 0) {
    digitalWrite(ena0, 1);
    digitalWrite(ena1, 1);
    digitalWrite(ena2, 1);
    digitalWrite(ena3, 1);
    digitalWrite(dir0, 1);
    digitalWrite(dir1, 0);
    digitalWrite(dir2, 0);
    digitalWrite(dir3, 1);
    speed(100);
    pos = dist*conv_cm;
  }
  else if (cnt >= pos){
    cnt = 0;
    stop();
    state = STOP;
  }
}

void rotatecw(int ang) {
  if (cnt == 0) {
    digitalWrite(dir0, 1);
    digitalWrite(dir1, 1);
    digitalWrite(dir2, 0);
    digitalWrite(dir3, 0);
    digitalWrite(ena0, 1);
    digitalWrite(ena1, 1);
    digitalWrite(ena2, 1);
    digitalWrite(ena3, 1);
    speed(100);
    pos = ang*conv_deg;
  }
  else if (cnt >= pos){
    cnt = 0;
    state = ROTATECCW;
  }
}

void rotateccw(int ang) {
  if (cnt == 0) {
    digitalWrite(dir0, 0);
    digitalWrite(dir1, 0);
    digitalWrite(dir2, 1);
    digitalWrite(dir3, 1);
    digitalWrite(ena0, 1);
    digitalWrite(ena1, 1);
    digitalWrite(ena2, 1);
    digitalWrite(ena3, 1);
    speed(100);
    pos = ang*conv_deg;
  }
  else if (cnt >= pos){
    cnt = 0;
    state = STOP;
  }
}

//
// void driveDiagFR() {
//
// }
//
// void driveDiagFL() {
//
// }
//
// void driveDiagBR () {
//
// }
//
// void driveDiagBL() {
//
// }
//

#endif
