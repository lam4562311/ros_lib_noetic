#ifndef _ROS_SERVICE_processing_nav_h
#define _ROS_SERVICE_processing_nav_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Empty.h"
#include "geographic_msgs/GeoPoint.h"

namespace ps4_bot
{

static const char PROCESSING_NAV[] = "ps4_bot/processing_nav";

  class processing_navRequest : public ros::Msg
  {
    public:
      typedef geographic_msgs::GeoPoint _center_type;
      _center_type center;
      typedef int64_t _half_of_size_x_type;
      _half_of_size_x_type half_of_size_x;
      typedef int64_t _half_of_size_y_type;
      _half_of_size_y_type half_of_size_y;
      typedef int64_t _width_type;
      _width_type width;
      typedef int64_t _height_type;
      _height_type height;
      uint32_t matrix_length;
      typedef uint8_t _matrix_type;
      _matrix_type st_matrix;
      _matrix_type * matrix;
      uint32_t path_length;
      typedef int64_t _path_type;
      _path_type st_path;
      _path_type * path;

    processing_navRequest():
      center(),
      half_of_size_x(0),
      half_of_size_y(0),
      width(0),
      height(0),
      matrix_length(0), st_matrix(), matrix(nullptr),
      path_length(0), st_path(), path(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->center.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_half_of_size_x;
      u_half_of_size_x.real = this->half_of_size_x;
      *(outbuffer + offset + 0) = (u_half_of_size_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_half_of_size_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_half_of_size_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_half_of_size_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_half_of_size_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_half_of_size_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_half_of_size_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_half_of_size_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->half_of_size_x);
      union {
        int64_t real;
        uint64_t base;
      } u_half_of_size_y;
      u_half_of_size_y.real = this->half_of_size_y;
      *(outbuffer + offset + 0) = (u_half_of_size_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_half_of_size_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_half_of_size_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_half_of_size_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_half_of_size_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_half_of_size_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_half_of_size_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_half_of_size_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->half_of_size_y);
      union {
        int64_t real;
        uint64_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_width.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_width.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_width.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_width.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->width);
      union {
        int64_t real;
        uint64_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->matrix_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->matrix_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->matrix_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->matrix_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->matrix_length);
      for( uint32_t i = 0; i < matrix_length; i++){
      *(outbuffer + offset + 0) = (this->matrix[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->matrix[i]);
      }
      *(outbuffer + offset + 0) = (this->path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_length);
      for( uint32_t i = 0; i < path_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_pathi;
      u_pathi.real = this->path[i];
      *(outbuffer + offset + 0) = (u_pathi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pathi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pathi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pathi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pathi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pathi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pathi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pathi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->path[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->center.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_half_of_size_x;
      u_half_of_size_x.base = 0;
      u_half_of_size_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_half_of_size_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_half_of_size_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_half_of_size_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_half_of_size_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_half_of_size_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_half_of_size_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_half_of_size_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->half_of_size_x = u_half_of_size_x.real;
      offset += sizeof(this->half_of_size_x);
      union {
        int64_t real;
        uint64_t base;
      } u_half_of_size_y;
      u_half_of_size_y.base = 0;
      u_half_of_size_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_half_of_size_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_half_of_size_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_half_of_size_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_half_of_size_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_half_of_size_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_half_of_size_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_half_of_size_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->half_of_size_y = u_half_of_size_y.real;
      offset += sizeof(this->half_of_size_y);
      union {
        int64_t real;
        uint64_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_width.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        int64_t real;
        uint64_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->height = u_height.real;
      offset += sizeof(this->height);
      uint32_t matrix_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      matrix_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      matrix_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      matrix_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->matrix_length);
      if(matrix_lengthT > matrix_length)
        this->matrix = (uint8_t*)realloc(this->matrix, matrix_lengthT * sizeof(uint8_t));
      matrix_length = matrix_lengthT;
      for( uint32_t i = 0; i < matrix_length; i++){
      this->st_matrix =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_matrix);
        memcpy( &(this->matrix[i]), &(this->st_matrix), sizeof(uint8_t));
      }
      uint32_t path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->path_length);
      if(path_lengthT > path_length)
        this->path = (int64_t*)realloc(this->path, path_lengthT * sizeof(int64_t));
      path_length = path_lengthT;
      for( uint32_t i = 0; i < path_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_path;
      u_st_path.base = 0;
      u_st_path.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_path.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_path.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_path.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_path.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_path.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_path.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_path.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_path = u_st_path.real;
      offset += sizeof(this->st_path);
        memcpy( &(this->path[i]), &(this->st_path), sizeof(int64_t));
      }
     return offset;
    }

    virtual const char * getType() override { return PROCESSING_NAV; };
    virtual const char * getMD5() override { return "7307218b869e7c7e3251c645c123d534"; };

  };

  class processing_navResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Empty _response_type;
      _response_type response;

    processing_navResponse():
      response()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->response.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->response.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PROCESSING_NAV; };
    virtual const char * getMD5() override { return "f624545799d912fd57177cf7069e330d"; };

  };

  class processing_nav {
    public:
    typedef processing_navRequest Request;
    typedef processing_navResponse Response;
  };

}
#endif
