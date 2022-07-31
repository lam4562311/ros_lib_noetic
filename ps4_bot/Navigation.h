#ifndef _ROS_SERVICE_navigation_h
#define _ROS_SERVICE_navigation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geographic_msgs/BoundingBox.h"
#include "geographic_msgs/GeoPoint.h"
#include "ps4_bot/vertices.h"

namespace ps4_bot
{

static const char NAVIGATION[] = "ps4_bot/navigation";

  class navigationRequest : public ros::Msg
  {
    public:
      typedef geographic_msgs::GeoPoint _start_type;
      _start_type start;
      typedef geographic_msgs::GeoPoint _goal_type;
      _goal_type goal;
      typedef geographic_msgs::BoundingBox _boundary_type;
      _boundary_type boundary;
      typedef geographic_msgs::GeoPoint _center_type;
      _center_type center;
      uint32_t polygons_length;
      typedef ps4_bot::vertices _polygons_type;
      _polygons_type st_polygons;
      _polygons_type * polygons;
      typedef bool _navigation_status_type;
      _navigation_status_type navigation_status;

    navigationRequest():
      start(),
      goal(),
      boundary(),
      center(),
      polygons_length(0), st_polygons(), polygons(nullptr),
      navigation_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      offset += this->boundary.serialize(outbuffer + offset);
      offset += this->center.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->polygons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->polygons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->polygons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->polygons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->polygons_length);
      for( uint32_t i = 0; i < polygons_length; i++){
      offset += this->polygons[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_navigation_status;
      u_navigation_status.real = this->navigation_status;
      *(outbuffer + offset + 0) = (u_navigation_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->navigation_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      offset += this->boundary.deserialize(inbuffer + offset);
      offset += this->center.deserialize(inbuffer + offset);
      uint32_t polygons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->polygons_length);
      if(polygons_lengthT > polygons_length)
        this->polygons = (ps4_bot::vertices*)realloc(this->polygons, polygons_lengthT * sizeof(ps4_bot::vertices));
      polygons_length = polygons_lengthT;
      for( uint32_t i = 0; i < polygons_length; i++){
      offset += this->st_polygons.deserialize(inbuffer + offset);
        memcpy( &(this->polygons[i]), &(this->st_polygons), sizeof(ps4_bot::vertices));
      }
      union {
        bool real;
        uint8_t base;
      } u_navigation_status;
      u_navigation_status.base = 0;
      u_navigation_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->navigation_status = u_navigation_status.real;
      offset += sizeof(this->navigation_status);
     return offset;
    }

    virtual const char * getType() override { return NAVIGATION; };
    virtual const char * getMD5() override { return "135fcffa3e2b8bd004214e3d13184e74"; };

  };

  class navigationResponse : public ros::Msg
  {
    public:
      typedef ps4_bot::vertices _polylines_type;
      _polylines_type polylines;

    navigationResponse():
      polylines()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->polylines.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->polylines.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return NAVIGATION; };
    virtual const char * getMD5() override { return "e395a9670e57edfa54d085ef61bac472"; };

  };

  class navigation {
    public:
    typedef navigationRequest Request;
    typedef navigationResponse Response;
  };

}
#endif
