// Generated by gencpp from file turtlebot_node/MVServ.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_NODE_MESSAGE_MVSERV_H
#define TURTLEBOT_NODE_MESSAGE_MVSERV_H

#include <ros/service_traits.h>


#include <turtlebot_node/MVServRequest.h>
#include <turtlebot_node/MVServResponse.h>


namespace turtlebot_node
{

struct MVServ
{

typedef MVServRequest Request;
typedef MVServResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MVServ
} // namespace turtlebot_node


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::turtlebot_node::MVServ > {
  static const char* value()
  {
    return "a5027d7394e6db0c454d58003c11ba06";
  }

  static const char* value(const ::turtlebot_node::MVServ&) { return value(); }
};

template<>
struct DataType< ::turtlebot_node::MVServ > {
  static const char* value()
  {
    return "turtlebot_node/MVServ";
  }

  static const char* value(const ::turtlebot_node::MVServ&) { return value(); }
};


// service_traits::MD5Sum< ::turtlebot_node::MVServRequest> should match 
// service_traits::MD5Sum< ::turtlebot_node::MVServ > 
template<>
struct MD5Sum< ::turtlebot_node::MVServRequest>
{
  static const char* value()
  {
    return MD5Sum< ::turtlebot_node::MVServ >::value();
  }
  static const char* value(const ::turtlebot_node::MVServRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlebot_node::MVServRequest> should match 
// service_traits::DataType< ::turtlebot_node::MVServ > 
template<>
struct DataType< ::turtlebot_node::MVServRequest>
{
  static const char* value()
  {
    return DataType< ::turtlebot_node::MVServ >::value();
  }
  static const char* value(const ::turtlebot_node::MVServRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::turtlebot_node::MVServResponse> should match 
// service_traits::MD5Sum< ::turtlebot_node::MVServ > 
template<>
struct MD5Sum< ::turtlebot_node::MVServResponse>
{
  static const char* value()
  {
    return MD5Sum< ::turtlebot_node::MVServ >::value();
  }
  static const char* value(const ::turtlebot_node::MVServResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlebot_node::MVServResponse> should match 
// service_traits::DataType< ::turtlebot_node::MVServ > 
template<>
struct DataType< ::turtlebot_node::MVServResponse>
{
  static const char* value()
  {
    return DataType< ::turtlebot_node::MVServ >::value();
  }
  static const char* value(const ::turtlebot_node::MVServResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TURTLEBOT_NODE_MESSAGE_MVSERV_H
