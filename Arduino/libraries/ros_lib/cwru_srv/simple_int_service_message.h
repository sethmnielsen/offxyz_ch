#ifndef _ROS_SERVICE_simple_int_service_message_h
#define _ROS_SERVICE_simple_int_service_message_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cwru_srv
{

static const char SIMPLE_INT_SERVICE_MESSAGE[] = "cwru_srv/simple_int_service_message";

  class simple_int_service_messageRequest : public ros::Msg
  {
    public:
      typedef int32_t _req_type;
      _req_type req;

    simple_int_service_messageRequest():
      req(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_req;
      u_req.real = this->req;
      *(outbuffer + offset + 0) = (u_req.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_req.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_req.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_req.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->req);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_req;
      u_req.base = 0;
      u_req.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_req.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_req.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_req.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->req = u_req.real;
      offset += sizeof(this->req);
     return offset;
    }

    const char * getType(){ return SIMPLE_INT_SERVICE_MESSAGE; };
    const char * getMD5(){ return "688ec893d5ff2cccc11b9bc8bc41109b"; };

  };

  class simple_int_service_messageResponse : public ros::Msg
  {
    public:
      typedef bool _resp_type;
      _resp_type resp;

    simple_int_service_messageResponse():
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

    const char * getType(){ return SIMPLE_INT_SERVICE_MESSAGE; };
    const char * getMD5(){ return "e3a98d806e1c4fee01a17d597e27ea8e"; };

  };

  class simple_int_service_message {
    public:
    typedef simple_int_service_messageRequest Request;
    typedef simple_int_service_messageResponse Response;
  };

}
#endif
