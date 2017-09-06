#ifndef _ROS_cwru_msgs_ErrorCode_h
#define _ROS_cwru_msgs_ErrorCode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cwru_msgs
{

  class ErrorCode : public ros::Msg
  {
    public:
      typedef int32_t _val_type;
      _val_type val;
      enum { PLANNING_FAILED = -1 };
      enum { SUCCESS = 1 };

    ErrorCode():
      val(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_val;
      u_val.real = this->val;
      *(outbuffer + offset + 0) = (u_val.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_val.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_val.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_val.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->val);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_val;
      u_val.base = 0;
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->val = u_val.real;
      offset += sizeof(this->val);
     return offset;
    }

    const char * getType(){ return "cwru_msgs/ErrorCode"; };
    const char * getMD5(){ return "c82f63c84d402abe94fbefc7f5feebf6"; };

  };

}
#endif