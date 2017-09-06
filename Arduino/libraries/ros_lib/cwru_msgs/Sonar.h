#ifndef _ROS_cwru_msgs_Sonar_h
#define _ROS_cwru_msgs_Sonar_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cwru_msgs
{

  class Sonar : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _dist_type;
      _dist_type dist;

    Sonar():
      header(),
      dist(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_dist;
      u_dist.real = this->dist;
      *(outbuffer + offset + 0) = (u_dist.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dist.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dist.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dist.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dist);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_dist;
      u_dist.base = 0;
      u_dist.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dist.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dist.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dist.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dist = u_dist.real;
      offset += sizeof(this->dist);
     return offset;
    }

    const char * getType(){ return "cwru_msgs/Sonar"; };
    const char * getMD5(){ return "32a7fd24a5630b5643e0d1882893197a"; };

  };

}
#endif