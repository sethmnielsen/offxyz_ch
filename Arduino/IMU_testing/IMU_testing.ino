#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup(void)
{
  Serial2.begin(115200);
  Serial2.println("Orientation Sensor Test"); Serial2.println("");

  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial2.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
  }

  delay(1000);

  bno.setExtCrystalUse(true);
}

void loop(void)
{
  /* Get a new sensor event */
  // sensors_event_t event;
  // bno.getEvent(&event);
  //
  // /* Display the floating point data */
  // Serial2.print("X: ");
  // Serial2.print(event.orientation.x, 4);
  // Serial2.print("\tY: ");
  // Serial2.print(event.orientation.y, 4);
  // Serial2.print("\tZ: ");
  // Serial2.print(event.orientation.z, 4);
  // Serial2.println("");

  imu::Quaternion quat = bno.getQuat();

  /* Display the quat data */
  Serial2.print(" qW: ");
  Serial2.print(quat.w(), 4);
  Serial2.print(" qX: ");
  Serial2.print(quat.y(), 4);
  Serial2.print(" qY: ");
  Serial2.print(quat.x(), 4);
  Serial2.print(" qZ: ");
  Serial2.print(quat.z(), 4);
  Serial2.println("");

  delay(100);
}
