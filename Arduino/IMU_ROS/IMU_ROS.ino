#define USE_TEENSY_HW_SERIAL

#include <ros.h>
#include <sensor_msgs/Imu.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

class NewHardware : public ArduinoHardware
{
  public:
  NewHardware():ArduinoHardware(&Serial2, 115200){}; // Specify which port you want to use
};

Adafruit_BNO055 bno = Adafruit_BNO055(55);
ros::NodeHandle_<NewHardware> nh;

sensor_msgs::Imu imu_msg;
ros::Publisher imu_data("imu/data", &imu_msg);

void setup() {
  nh.initNode();
  nh.advertise(imu_data);

  /* Initialise the sensor */
  if(!bno.begin()) {
    Serial2.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
  }
  bno.setExtCrystalUse(true);

}

void loop() {
  imu_msg.header.frame_id = "camera_link";
  imu_msg.header.stamp = nh.now();

  imu::Quaternion quat = bno.getQuat();
  imu::Vector<3>  gyro = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  imu::Vector<3>  accl = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);

  imu_msg.orientation.x = quat.x();
  imu_msg.orientation.y = quat.y();
  imu_msg.orientation.z = quat.z();
  imu_msg.orientation.w = quat.w();

  imu_msg.angular_velocity.x = gyro.x();
  imu_msg.angular_velocity.y = gyro.y();
  imu_msg.angular_velocity.z = gyro.z();

  imu_msg.linear_acceleration.x = accl.x();
  imu_msg.linear_acceleration.y = accl.y();
  imu_msg.linear_acceleration.z = accl.z();

  imu_data.publish(&imu_msg);
  nh.spinOnce();
  delay(100);
}
