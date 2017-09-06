#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/* This driver uses the Adafruit unified sensor library (Adafruit_Sensor),
   which provides a common 'type' for sensor data and some helper functions.

   To use this driver you will also need to download the Adafruit_Sensor
   library and include it in your libraries folder.

   You should also assign a unique ID to this sensor for use with
   the Adafruit Sensor API so that you can identify this particular
   sensor in any data logs, etc.  To assign a unique ID, simply
   provide an appropriate value in the constructor below (12345
   is used by default in this example).

   Connections
   ===========
   Connect SCL to analog 5
   Connect SDA to analog 4
   Connect VDD to 3.3-5V DC
   Connect GROUND to common ground

   History
   =======
   2015/MAR/03  - First release (KTOWN)
*/

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)

Adafruit_BNO055 bno = Adafruit_BNO055(55);

/**************************************************************************/
/*
    Displays some basic information on this sensor from the unified
    sensor API sensor_t type (see Adafruit_Sensor for more information)
*/
/**************************************************************************/
void displaySensorDetails(void)
{
  sensor_t sensor;
  bno.getSensor(&sensor);
  Serial2.println("------------------------------------");
  Serial2.print  ("Sensor:       "); Serial2.println(sensor.name);
  Serial2.print  ("Driver Ver:   "); Serial2.println(sensor.version);
  Serial2.print  ("Unique ID:    "); Serial2.println(sensor.sensor_id);
  Serial2.print  ("Max Value:    "); Serial2.print(sensor.max_value); Serial2.println(" xxx");
  Serial2.print  ("Min Value:    "); Serial2.print(sensor.min_value); Serial2.println(" xxx");
  Serial2.print  ("Resolution:   "); Serial2.print(sensor.resolution); Serial2.println(" xxx");
  Serial2.println("------------------------------------");
  Serial2.println("");
  delay(500);
}

/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void)
{
  Serial2.begin(115200);
  Serial2.println("Orientation Sensor Test"); Serial2.println("");

  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial2.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  /* Use external crystal for better accuracy */
  bno.setExtCrystalUse(true);

  /* Display some basic information on this sensor */
  displaySensorDetails();
}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void)
{
  /* Get a new sensor event */
  sensors_event_t event;
  bno.getEvent(&event);

  /* Board layout:
         +----------+
         |         *| RST   PITCH  ROLL  HEADING
     ADR |*        *| SCL
     INT |*        *| SDA     ^            /->
     PS1 |*        *| GND     |            |
     PS0 |*        *| 3VO     Y    Z-->    \-X
         |         *| VIN
         +----------+
  */

  /* The processing sketch expects data as roll, pitch, heading */
  Serial2.print(F("Orientation: "));
  Serial2.print((float)event.orientation.x);
  Serial2.print(F(" "));
  Serial2.print((float)event.orientation.y);
  Serial2.print(F(" "));
  Serial2.print((float)event.orientation.z);
  Serial2.println(F(""));

  /* Also send calibration data for each sensor. */
  uint8_t sys, gyro, accel, mag = 0;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
  Serial2.print(F("Calibration: "));
  Serial2.print(sys, DEC);
  Serial2.print(F(" "));
  Serial2.print(gyro, DEC);
  Serial2.print(F(" "));
  Serial2.print(accel, DEC);
  Serial2.print(F(" "));
  Serial2.println(mag, DEC);

  delay(BNO055_SAMPLERATE_DELAY_MS);
}
