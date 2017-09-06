#ifndef _ROS_SERVICE_path_service_message_h
#define _ROS_SERVICE_path_service_message_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/Path.h"

namespace cwru_srv
{

static const char PATH_SERVICE_MESSAGE[] = "cwru_srv/path_service_message";

  class path_service_messageRequest : public ros::Msg
  {
    public:
      typedef nav_msgs::Path _path_type;
      _path_type path;

    path_service_messageRequest():
      path()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PATH_SERVICE_MESSAGE; };
    const char * getMD5(){ return "58d6f138c7de7ef47c75d4b7e5df5472"; };

  };

  class path_service_messageResponse : public ros::Msg
  {
    public:
      typedef bool _resp_type;
      _resp_type resp;

    path_service_messageResponse():
      resp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_resp;
      u_resp.real = this->resp;
      *(outbuffer + offset + 0) = (u_resp.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->resp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_resp;
      u_resp.base = 0;
      u_resp.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->resp = u_resp.real;
      offset += sizeof(this->resp);
     return offset;
    }

    const char * getType(){ return PATH_SERVICE_MESSAGE; };
    const char * getMD5(){ return "e3a98d806e1c4fee01a17d597e27ea8e"; };

  };

  class path_service_message {
    public:
    typedef path_service_messageRequest Request;
    typedef path_service_messageResponse Response;
  };

}
#endif
