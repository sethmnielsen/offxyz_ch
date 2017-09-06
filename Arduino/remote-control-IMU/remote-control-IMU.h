#ifndef DIRECTION_CONTROL_H
#define	DIRECTION_CONTROL_H

#define USE_TEENSY_HW_SERIAL


#include <Arduino.h>
#include <ros.h>
#include <sensor_msgs/Imu.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


#define step   11
#define lidr   12

#define enab   2
#define dir0   3
#define dir1   4
#define dir2   5
#define dir3   6

// ROS
class NewHardware : public ArduinoHardware
{
  public:
  NewHardware():ArduinoHardware(&Serial2, 115200){}; // Specify which port you want to use
};

Adafruit_BNO055 bno = Adafruit_BNO055(55);
ros::NodeHandle_<NewHardware> nh;

sensor_msgs::Imu imu_msg;
ros::Publisher imu_data("imu_data", &imu_msg);
// end ROS


IntervalTimer step_tmr;
IntervalTimer accel_tmr;
// IntervalTimer imu_tmr;
int step_state = HIGH;

const int v0 = -1600;
const int vmax = -100;
const int accl = 20;
const int decl = 40;
const int conv_cm = 408;
const int conv_deg = 180;

volatile unsigned int pos = 0;

volatile int currentVel = v0;
volatile int targetVel  = 0;

volatile int incomingByte = 0;
unsigned int stop_cnt = 0;
enum action {FORWARD, REVERSE, RIGHT, LEFT, ROTATECW, ROTATECCW, STOP} state;

// /***************** DECLARATIONS **********************/
void stepINT();
void accelINT();
// void imuINT();
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

// /**************** DEFINITIONS ***********************/
void configPins() {
  pinMode(lidr, OUTPUT);
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
  // imu_tmr.begin(imuINT, 1111111);
}

void stepINT() {
  if (digitalRead(enab) == 1) {
    if (step_state == LOW) {
      step_state = HIGH;
      pos++;
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

// void imuINT() {
  // imu_msg.header.frame_id = "base_link_frame";
  // imu_msg.header.stamp = nh.now();
  //
  // imu::Quaternion quat = bno.getQuat();
  // imu::Vector<3>  gyro = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  // imu::Vector<3>  accl = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  //
  // imu_msg.orientation.x = quat.x();
  // imu_msg.orientation.y = quat.y();
  // imu_msg.orientation.z = quat.z();
  // imu_msg.orientation.w = quat.w();
  //
  // imu_msg.angular_velocity.x = gyro.x();
  // imu_msg.angular_velocity.y = gyro.y();
  // imu_msg.angular_velocity.z = gyro.z();
  //
  // imu_msg.linear_acceleration.x = accl.x();
  // imu_msg.linear_acceleration.y = accl.y();
  // imu_msg.linear_acceleration.z = accl.z();
  //
  // imu_data.publish(&imu_msg);
  // nh.spinOnce();
// }

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
    pos = 0;
    digitalWrite(lidr, 0);
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
