#ifndef _ROS_cwru_msgs_Path_h
#define _ROS_cwru_msgs_Path_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cwru_msgs/PathSegment.h"

namespace cwru_msgs
{

  class Path : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t segs_length;
      typedef cwru_msgs::PathSegment _segs_type;
      _segs_type st_segs;
      _segs_type * segs;

    Path():
      header(),
      segs_length(0), segs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->segs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->segs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->segs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->segs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->segs_length);
      for( uint32_t i = 0; i < segs_length; i++){
      offset += this->segs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t segs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      segs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      segs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      segs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->segs_length);
      if(segs_lengthT > segs_length)
        this->segs = (cwru_msgs::PathSegment*)realloc(this->segs, segs_lengthT * sizeof(cwru_msgs::PathSegment));
      segs_length = segs_lengthT;
      for( uint32_t i = 0; i < segs_length; i++){
      offset += this->st_segs.deserialize(inbuffer + offset);
        memcpy( &(this->segs[i]), &(this->st_segs), sizeof(cwru_msgs::PathSegment));
      }
     return offset;
    }

    const char * getType(){ return "cwru_msgs/Path"; };
    const char * getMD5(){ return "61997cac25b65fbf8f9034286f94085e"; };

  };

}
#endif