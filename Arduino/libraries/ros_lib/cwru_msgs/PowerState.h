#ifndef _ROS_cwru_msgs_PowerState_h
#define _ROS_cwru_msgs_PowerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cwru_msgs
{

  class PowerState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _battery_voltage_type;
      _battery_voltage_type battery_voltage;
      typedef float _cRIO_voltage_type;
      _cRIO_voltage_type cRIO_voltage;
      typedef float _v13_8_voltage_type;
      _v13_8_voltage_type v13_8_voltage;
      typedef float _motor_voltage_type;
      _motor_voltage_type motor_voltage;

    PowerState():
      header(),
      battery_voltage(0),
      cRIO_voltage(0),
      v13_8_voltage(0),
      motor_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.real = this->battery_voltage;
      *(outbuffer + offset + 0) = (u_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_cRIO_voltage;
      u_cRIO_voltage.real = this->cRIO_voltage;
      *(outbuffer + offset + 0) = (u_cRIO_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cRIO_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cRIO_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cRIO_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cRIO_voltage);
      union {
        float real;
        uint32_t base;
      } u_v13_8_voltage;
      u_v13_8_voltage.real = this->v13_8_voltage;
      *(outbuffer + offset + 0) = (u_v13_8_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v13_8_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v13_8_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v13_8_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v13_8_voltage);
      union {
        float real;
        uint32_t base;
      } u_motor_voltage;
      u_motor_voltage.real = this->motor_voltage;
      *(outbuffer + offset + 0) = (u_motor_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.base = 0;
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_voltage = u_battery_voltage.real;
      offset += sizeof(this->battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_cRIO_voltage;
      u_cRIO_voltage.base = 0;
      u_cRIO_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cRIO_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cRIO_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cRIO_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cRIO_voltage = u_cRIO_voltage.real;
      offset += sizeof(this->cRIO_voltage);
      union {
        float real;
        uint32_t base;
      } u_v13_8_voltage;
      u_v13_8_voltage.base = 0;
      u_v13_8_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v13_8_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v13_8_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v13_8_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v13_8_voltage = u_v13_8_voltage.real;
      offset += sizeof(this->v13_8_voltage);
      union {
        float real;
        uint32_t base;
      } u_motor_voltage;
      u_motor_voltage.base = 0;
      u_motor_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor_voltage = u_motor_voltage.real;
      offset += sizeof(this->motor_voltage);
     return offset;
    }

    const char * getType(){ return "cwru_msgs/PowerState"; };
    const char * getMD5(){ return "28d9736fc054adc56d7b67c1f71a6b0d"; };

  };

}
#endif