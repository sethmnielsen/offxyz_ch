#ifndef _ROS_cwru_msgs_Pose_h
#define _ROS_cwru_msgs_Pose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cwru_msgs
{

  class Pose : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _theta_type;
      _theta_type theta;
      typedef float _vel_type;
      _vel_type vel;
      typedef float _omega_type;
      _omega_type omega;
      typedef float _x_var_type;
      _x_var_type x_var;
      typedef float _y_var_type;
      _y_var_type y_var;
      typedef float _theta_var_type;
      _theta_var_type theta_var;
      typedef float _vel_var_type;
      _vel_var_type vel_var;
      typedef float _omega_var_type;
      _omega_var_type omega_var;

    Pose():
      header(),
      x(0),
      y(0),
      theta(0),
      vel(0),
      omega(0),
      x_var(0),
      y_var(0),
      theta_var(0),
      vel_var(0),
      omega_var(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_theta;
      u_theta.real = this->theta;
      *(outbuffer + offset + 0) = (u_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta);
      union {
        float real;
        uint32_t base;
      } u_vel;
      u_vel.real = this->vel;
      *(outbuffer + offset + 0) = (u_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel);
      union {
        float real;
        uint32_t base;
      } u_omega;
      u_omega.real = this->omega;
      *(outbuffer + offset + 0) = (u_omega.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_omega.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_omega.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_omega.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->omega);
      union {
        float real;
        uint32_t base;
      } u_x_var;
      u_x_var.real = this->x_var;
      *(outbuffer + offset + 0) = (u_x_var.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_var.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_var.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_var.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_var);
      union {
        float real;
        uint32_t base;
      } u_y_var;
      u_y_var.real = this->y_var;
      *(outbuffer + offset + 0) = (u_y_var.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_var.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_var.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_var.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_var);
      union {
        float real;
        uint32_t base;
      } u_theta_var;
      u_theta_var.real = this->theta_var;
      *(outbuffer + offset + 0) = (u_theta_var.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_var.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_var.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_var.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta_var);
      union {
        float real;
        uint32_t base;
      } u_vel_var;
      u_vel_var.real = this->vel_var;
      *(outbuffer + offset + 0) = (u_vel_var.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel_var.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel_var.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel_var.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_var);
      union {
        float real;
        uint32_t base;
      } u_omega_var;
      u_omega_var.real = this->omega_var;
      *(outbuffer + offset + 0) = (u_omega_var.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_omega_var.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_omega_var.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_omega_var.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->omega_var);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_theta;
      u_theta.base = 0;
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->theta = u_theta.real;
      offset += sizeof(this->theta);
      union {
        float real;
        uint32_t base;
      } u_vel;
      u_vel.base = 0;
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel = u_vel.real;
      offset += sizeof(this->vel);
      union {
        float real;
        uint32_t base;
      } u_omega;
      u_omega.base = 0;
      u_omega.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_omega.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_omega.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_omega.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->omega = u_omega.real;
      offset += sizeof(this->omega);
      union {
        float real;
        uint32_t base;
      } u_x_var;
      u_x_var.base = 0;
      u_x_var.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_var.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_var.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_var.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_var = u_x_var.real;
      offset += sizeof(this->x_var);
      union {
        float real;
        uint32_t base;
      } u_y_var;
      u_y_var.base = 0;
      u_y_var.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_var.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_var.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_var.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_var = u_y_var.real;
      offset += sizeof(this->y_var);
      union {
        float real;
        uint32_t base;
      } u_theta_var;
      u_theta_var.base = 0;
      u_theta_var.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta_var.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta_var.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta_var.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->theta_var = u_theta_var.real;
      offset += sizeof(this->theta_var);
      union {
        float real;
        uint32_t base;
      } u_vel_var;
      u_vel_var.base = 0;
      u_vel_var.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel_var.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel_var.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel_var.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel_var = u_vel_var.real;
      offset += sizeof(this->vel_var);
      union {
        float real;
        uint32_t base;
      } u_omega_var;
      u_omega_var.base = 0;
      u_omega_var.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_omega_var.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_omega_var.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_omega_var.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->omega_var = u_omega_var.real;
      offset += sizeof(this->omega_var);
     return offset;
    }

    const char * getType(){ return "cwru_msgs/Pose"; };
    const char * getMD5(){ return "7ce3d88c4d07be05d54abf722834318f"; };

  };

}
#endif