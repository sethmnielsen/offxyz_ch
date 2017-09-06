#ifndef _ROS_cwru_msgs_PathSegment_h
#define _ROS_cwru_msgs_PathSegment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Twist.h"

namespace cwru_msgs
{

  class PathSegment : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _seg_type_type;
      _seg_type_type seg_type;
      typedef uint32_t _seg_number_type;
      _seg_number_type seg_number;
      typedef float _seg_length_type;
      _seg_length_type seg_length;
      typedef geometry_msgs::Point _ref_point_type;
      _ref_point_type ref_point;
      typedef geometry_msgs::Quaternion _init_tan_angle_type;
      _init_tan_angle_type init_tan_angle;
      typedef float _curvature_type;
      _curvature_type curvature;
      typedef geometry_msgs::Twist _max_speeds_type;
      _max_speeds_type max_speeds;
      typedef geometry_msgs::Twist _min_speeds_type;
      _min_speeds_type min_speeds;
      typedef float _accel_limit_type;
      _accel_limit_type accel_limit;
      typedef float _decel_limit_type;
      _decel_limit_type decel_limit;
      enum { LINE =  1 };
      enum { ARC =  2 };
      enum { SPIN_IN_PLACE =  3 };

    PathSegment():
      header(),
      seg_type(0),
      seg_number(0),
      seg_length(0),
      ref_point(),
      init_tan_angle(),
      curvature(0),
      max_speeds(),
      min_speeds(),
      accel_limit(0),
      decel_limit(0)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->seg_length);
      offset += this->ref_point.serialize(outbuffer + offset);
      offset += this->init_tan_angle.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->curvature);
      offset += this->max_speeds.serialize(outbuffer + offset);
      offset += this->min_speeds.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_limit);
      offset += serializeAvrFloat64(outbuffer + offset, this->decel_limit);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->seg_length));
      offset += this->ref_point.deserialize(inbuffer + offset);
      offset += this->init_tan_angle.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->curvature));
      offset += this->max_speeds.deserialize(inbuffer + offset);
      offset += this->min_speeds.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_limit));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->decel_limit));
     return offset;
    }

    const char * getType(){ return "cwru_msgs/PathSegment"; };
    const char * getMD5(){ return "5c807f5cea06f40555a1d9f2a31b3c69"; };

  };

}
#endif