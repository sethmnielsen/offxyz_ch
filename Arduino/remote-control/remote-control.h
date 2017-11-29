/*
* This file contains the implemenation of all functions, the
* pin assignments, the timer setups, and the variable assignments.
*/

#ifndef DIRECTION_CONTROL_H
#define	DIRECTION_CONTROL_H

#include <Arduino.h>

/***************** PIN ASSIGNMENTS **********************/

// step and enab pins are connected to all four stepper drivers
// each driver has its own dir pin to allow spinning the motors in different directions
#define step   11 // Going from LOW to HIGH makes the stepper motors spin one microstep

#define enab   2  // If LOW, stepper drivers are powered off

// For each direction pin, HIGH is spin forward and LOW is backward
#define dir0   3 // Front left wheel (battery is in back, camera is front)
#define dir1   4 // Back left
#define dir2   5 // Front right
#define dir3   6 // Back right

/************* CREATE VARIABLES AND CONSTANTS *****************/

IntervalTimer step_tmr;  // Timer used to set PWM period
IntervalTimer accel_tmr; // Timer used to speed up or slow down motors
int step_state = HIGH;

/*** PWM frequencies ***/
const int v0 = -1600;       // Slowest speed (inital speed during speedup, final speed in slowdown)
const int vmax = -100;      // Full speed (less negative is faster)
const int accl = 20;        // speedup rate
const int decl = 40;        // slowdown rate

volatile int currentVel = v0;   // used during speedup/slowdown
volatile int targetVel  = 0;    // desired velocity to reach during speedup

volatile int incomingByte = 0;  // data coming in from Serial2 (keyboard input)
unsigned int stop_cnt = 0;      // see remote-control.ino
enum action {FORWARD, REVERSE, RIGHT, LEFT, ROTATECW, ROTATECCW, STOP} state; // the various possible states

/***************** DECLARATIONS **********************/
void stepINT();
void accelINT();
void configPins();
void configTimers();
void speed(int percent);
void stop();
void forward();
void reverse();
void left();
void right();
void rotatecw();
void rotateccw();

/**************** DEFINITIONS ***********************/
void configPins() {
  pinMode(step, OUTPUT);
  pinMode(dir0, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(enab, OUTPUT);
}

void configTimers() {
  interrupts();

  step_tmr.begin(stepINT, v0);
  accel_tmr.begin(accelINT, 10000);
}

void stepINT() {
  if (digitalRead(enab) == 1) {
    if (step_state == LOW) {
      step_state = HIGH;
    }
    else {
      step_state = LOW;
    }
    digitalWrite(step, step_state);
  }
}

void accelINT() {
  if (currentVel < targetVel && state != STOP) {
    currentVel += accl;
  }
  else if (currentVel > v0 && state == STOP) {
    currentVel -= decl;
  }
  step_tmr.begin(stepINT,-currentVel);
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
  if (currentVel <= v0) {
    digitalWrite(enab, 0);
    digitalWrite(step, 0);
  }
}

void forward() {
  digitalWrite(enab, 1);
  digitalWrite(dir0, 1);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 1);
  digitalWrite(dir3, 1);
  speed(100);
}

void reverse() {
  digitalWrite(enab, 1);
  digitalWrite(dir0, 0);
  digitalWrite(dir1, 0);
  digitalWrite(dir2, 0);
  digitalWrite(dir3, 0);
  speed(100);
}

void right() {
  digitalWrite(enab, 1);
  digitalWrite(dir0, 1);
  digitalWrite(dir1, 0);
  digitalWrite(dir2, 0);
  digitalWrite(dir3, 1);
  speed(100);
}

void left() {
  digitalWrite(enab, 1);
  digitalWrite(dir0, 0);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 1);
  digitalWrite(dir3, 0);
  speed(100);
}

void rotatecw() {
  digitalWrite(enab, 1);
  digitalWrite(dir0, 1);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 0);
  digitalWrite(dir3, 0);
  speed(100);
}

void rotateccw() {
  digitalWrite(enab, 1);
  digitalWrite(dir0, 0);
  digitalWrite(dir1, 0);
  digitalWrite(dir2, 1);
  digitalWrite(dir3, 1);
  speed(100);
}

#endif
