// Generated by gencpp from file svg_ros/SensorSrvRequest.msg
// DO NOT EDIT!


#ifndef SVG_ROS_MESSAGE_SENSORSRVREQUEST_H
#define SVG_ROS_MESSAGE_SENSORSRVREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace svg_ros
{
template <class ContainerAllocator>
struct SensorSrvRequest_
{
  typedef SensorSrvRequest_<ContainerAllocator> Type;

  SensorSrvRequest_()
    : coord_x(0.0)
    , coord_y(0.0)
    , coord_ang(0.0)  {
    }
  SensorSrvRequest_(const ContainerAllocator& _alloc)
    : coord_x(0.0)
    , coord_y(0.0)
    , coord_ang(0.0)  {
  (void)_alloc;
    }



   typedef float _coord_x_type;
  _coord_x_type coord_x;

   typedef float _coord_y_type;
  _coord_y_type coord_y;

   typedef float _coord_ang_type;
  _coord_ang_type coord_ang;




  typedef boost::shared_ptr< ::svg_ros::SensorSrvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::svg_ros::SensorSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SensorSrvRequest_

typedef ::svg_ros::SensorSrvRequest_<std::allocator<void> > SensorSrvRequest;

typedef boost::shared_ptr< ::svg_ros::SensorSrvRequest > SensorSrvRequestPtr;
typedef boost::shared_ptr< ::svg_ros::SensorSrvRequest const> SensorSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::svg_ros::SensorSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace svg_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::svg_ros::SensorSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::svg_ros::SensorSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::svg_ros::SensorSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7eb93eecd92959fb5dd28a3a8fff896e";
  }

  static const char* value(const ::svg_ros::SensorSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7eb93eecd92959fbULL;
  static const uint64_t static_value2 = 0x5dd28a3a8fff896eULL;
};

template<class ContainerAllocator>
struct DataType< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "svg_ros/SensorSrvRequest";
  }

  static const char* value(const ::svg_ros::SensorSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 coord_x\n\
float32 coord_y\n\
float32 coord_ang\n\
";
  }

  static const char* value(const ::svg_ros::SensorSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.coord_x);
      stream.next(m.coord_y);
      stream.next(m.coord_ang);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SensorSrvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::svg_ros::SensorSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::svg_ros::SensorSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "coord_x: ";
    Printer<float>::stream(s, indent + "  ", v.coord_x);
    s << indent << "coord_y: ";
    Printer<float>::stream(s, indent + "  ", v.coord_y);
    s << indent << "coord_ang: ";
    Printer<float>::stream(s, indent + "  ", v.coord_ang);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SVG_ROS_MESSAGE_SENSORSRVREQUEST_H
