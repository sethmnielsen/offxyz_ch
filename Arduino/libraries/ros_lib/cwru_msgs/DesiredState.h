#ifndef _ROS_cwru_msgs_DesiredState_h
#define _ROS_cwru_msgs_DesiredState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace cwru_msgs
{

  class DesiredState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _seg_type_type;
      _seg_type_type seg_type;
      typedef uint32_t _seg_number_type;
      _seg_number_type seg_number;
      typedef geometry_msgs::Pose _des_pose_type;
      _des_pose_type des_pose;
      typedef float _des_speed_type;
      _des_speed_type des_speed;
      typedef float _des_rho_type;
      _des_rho_type des_rho;
      typedef float _des_lseg_type;
      _des_lseg_type des_lseg;

    DesiredState():
      header(),
      seg_type(0),
      seg_number(0),
      des_pose(),
      des_speed(0),
      des_rho(0),
      des_lseg(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_seg_type;
      u_seg_type.real = this->seg_type;
      *(outbuffer + offset + 0) = (u_seg_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seg_type);
      *(outbuffer + offset + 0) = (this->seg_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seg_number >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seg_number >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seg_number >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seg_number);
      offset += this->des_pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->des_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->des_rho);
      offset += serializeAvrFloat64(outbuffer + offset, this->des_lseg);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_seg_type;
      u_seg_type.base = 0;
      u_seg_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->seg_type = u_seg_type.real;
      offset += sizeof(this->seg_type);
      this->seg_number =  ((uint32_t) (*(inbuffer + offset)));
      this->seg_number |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seg_number |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seg_number |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->seg_number);
      offset += this->des_pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->des_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->des_rho));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->des_lseg));
     return offset;
    }

    const char * getType(){ return "cwru_msgs/DesiredState"; };
    const char * getMD5(){ return "8a022665b62e846aae599403b4b5aab1"; };

  };

}
#endif