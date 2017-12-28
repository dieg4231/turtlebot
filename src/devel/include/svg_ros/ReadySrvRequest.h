// Generated by gencpp from file svg_ros/ReadySrvRequest.msg
// DO NOT EDIT!


#ifndef SVG_ROS_MESSAGE_READYSRVREQUEST_H
#define SVG_ROS_MESSAGE_READYSRVREQUEST_H


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
struct ReadySrvRequest_
{
  typedef ReadySrvRequest_<ContainerAllocator> Type;

  ReadySrvRequest_()
    : ready(0)  {
    }
  ReadySrvRequest_(const ContainerAllocator& _alloc)
    : ready(0)  {
  (void)_alloc;
    }



   typedef int32_t _ready_type;
  _ready_type ready;




  typedef boost::shared_ptr< ::svg_ros::ReadySrvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::svg_ros::ReadySrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ReadySrvRequest_

typedef ::svg_ros::ReadySrvRequest_<std::allocator<void> > ReadySrvRequest;

typedef boost::shared_ptr< ::svg_ros::ReadySrvRequest > ReadySrvRequestPtr;
typedef boost::shared_ptr< ::svg_ros::ReadySrvRequest const> ReadySrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::svg_ros::ReadySrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::svg_ros::ReadySrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::svg_ros::ReadySrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::svg_ros::ReadySrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "291f89bf3c78c525c8b92db5f257f513";
  }

  static const char* value(const ::svg_ros::ReadySrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x291f89bf3c78c525ULL;
  static const uint64_t static_value2 = 0xc8b92db5f257f513ULL;
};

template<class ContainerAllocator>
struct DataType< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "svg_ros/ReadySrvRequest";
  }

  static const char* value(const ::svg_ros::ReadySrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 ready\n\
";
  }

  static const char* value(const ::svg_ros::ReadySrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ready);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReadySrvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::svg_ros::ReadySrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::svg_ros::ReadySrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "ready: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ready);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SVG_ROS_MESSAGE_READYSRVREQUEST_H