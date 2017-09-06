#ifndef _ROS_cwru_msgs_cRIOSensors_h
#define _ROS_cwru_msgs_cRIOSensors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cwru_msgs
{

  class cRIOSensors : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _left_wheel_encoder_type;
      _left_wheel_encoder_type left_wheel_encoder;
      typedef int32_t _right_wheel_encoder_type;
      _right_wheel_encoder_type right_wheel_encoder;
      typedef int32_t _left_motor_encoder_type;
      _left_motor_encoder_type left_motor_encoder;
      typedef int32_t _right_motor_encoder_type;
      _right_motor_encoder_type right_motor_encoder;
      typedef int16_t _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      typedef int16_t _yaw_temp_type;
      _yaw_temp_type yaw_temp;
      typedef int16_t _yaw_ref_type;
      _yaw_ref_type yaw_ref;

    cRIOSensors():
      header(),
      left_wheel_encoder(0),
      right_wheel_encoder(0),
      left_motor_encoder(0),
      right_motor_encoder(0),
      yaw_rate(0),
      yaw_temp(0),
      yaw_ref(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_left_wheel_encoder;
      u_left_wheel_encoder.real = this->left_wheel_encoder;
      *(outbuffer + offset + 0) = (u_left_wheel_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_wheel_encoder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_wheel_encoder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_wheel_encoder.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_wheel_encoder);
      union {
        int32_t real;
        uint32_t base;
      } u_right_wheel_encoder;
      u_right_wheel_encoder.real = this->right_wheel_encoder;
      *(outbuffer + offset + 0) = (u_right_wheel_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_wheel_encoder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_wheel_encoder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_wheel_encoder.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_wheel_encoder);
      union {
        int32_t real;
        uint32_t base;
      } u_left_motor_encoder;
      u_left_motor_encoder.real = this->left_motor_encoder;
      *(outbuffer + offset + 0) = (u_left_motor_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_motor_encoder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_motor_encoder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_motor_encoder.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_motor_encoder);
      union {
        int32_t real;
        uint32_t base;
      } u_right_motor_encoder;
      u_right_motor_encoder.real = this->right_motor_encoder;
      *(outbuffer + offset + 0) = (u_right_motor_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_motor_encoder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_motor_encoder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_motor_encoder.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_motor_encoder);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_rate;
      u_yaw_rate.real = this->yaw_rate;
      *(outbuffer + offset + 0) = (u_yaw_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_rate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_rate);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_temp;
      u_yaw_temp.real = this->yaw_temp;
      *(outbuffer + offset + 0) = (u_yaw_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_temp.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_temp);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_ref;
      u_yaw_ref.real = this->yaw_ref;
      *(outbuffer + offset + 0) = (u_yaw_ref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_ref.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_ref);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_left_wheel_encoder;
      u_left_wheel_encoder.base = 0;
      u_left_wheel_encoder.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_wheel_encoder.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_wheel_encoder.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_wheel_encoder.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_wheel_encoder = u_left_wheel_encoder.real;
      offset += sizeof(this->left_wheel_encoder);
      union {
        int32_t real;
        uint32_t base;
      } u_right_wheel_encoder;
      u_right_wheel_encoder.base = 0;
      u_right_wheel_encoder.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_wheel_encoder.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_wheel_encoder.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_wheel_encoder.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_wheel_encoder = u_right_wheel_encoder.real;
      offset += sizeof(this->right_wheel_encoder);
      union {
        int32_t real;
        uint32_t base;
      } u_left_motor_encoder;
      u_left_motor_encoder.base = 0;
      u_left_motor_encoder.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_motor_encoder.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_motor_encoder.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_motor_encoder.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_motor_encoder = u_left_motor_encoder.real;
      offset += sizeof(this->left_motor_encoder);
      union {
        int32_t real;
        uint32_t base;
      } u_right_motor_encoder;
      u_right_motor_encoder.base = 0;
      u_right_motor_encoder.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_motor_encoder.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_motor_encoder.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_motor_encoder.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_motor_encoder = u_right_motor_encoder.real;
      offset += sizeof(this->right_motor_encoder);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_rate;
      u_yaw_rate.base = 0;
      u_yaw_rate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_rate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw_rate = u_yaw_rate.real;
      offset += sizeof(this->yaw_rate);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_temp;
      u_yaw_temp.base = 0;
      u_yaw_temp.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_temp.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw_temp = u_yaw_temp.real;
      offset += sizeof(this->yaw_temp);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_ref;
      u_yaw_ref.base = 0;
      u_yaw_ref.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_ref.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw_ref = u_yaw_ref.real;
      offset += sizeof(this->yaw_ref);
     return offset;
    }

    const char * getType(){ return "cwru_msgs/cRIOSensors"; };
    const char * getMD5(){ return "210acf44f8ca85255cab84f619fb4f26"; };

  };

}
#endif