// Generated by gencpp from file turtlebot_node/MVServRequest.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_NODE_MESSAGE_MVSERVREQUEST_H
#define TURTLEBOT_NODE_MESSAGE_MVSERVREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace turtlebot_node
{
template <class ContainerAllocator>
struct MVServRequest_
{
  typedef MVServRequest_<ContainerAllocator> Type;

  MVServRequest_()
    : param()
    , coord_x(0.0)
    , coord_y(0.0)
    , coord_ang(0.0)  {
    }
  MVServRequest_(const ContainerAllocator& _alloc)
    : param(_alloc)
    , coord_x(0.0)
    , coord_y(0.0)
    , coord_ang(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _param_type;
  _param_type param;

   typedef float _coord_x_type;
  _coord_x_type coord_x;

   typedef float _coord_y_type;
  _coord_y_type coord_y;

   typedef float _coord_ang_type;
  _coord_ang_type coord_ang;




  typedef boost::shared_ptr< ::turtlebot_node::MVServRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_node::MVServRequest_<ContainerAllocator> const> ConstPtr;

}; // struct MVServRequest_

typedef ::turtlebot_node::MVServRequest_<std::allocator<void> > MVServRequest;

typedef boost::shared_ptr< ::turtlebot_node::MVServRequest > MVServRequestPtr;
typedef boost::shared_ptr< ::turtlebot_node::MVServRequest const> MVServRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlebot_node::MVServRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlebot_node::MVServRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace turtlebot_node

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_node::MVServRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_node::MVServRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_node::MVServRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_node::MVServRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_node::MVServRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_node::MVServRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_node::MVServRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d3cc9a10efcfe8293203cd968ed57a1b";
  }

  static const char* value(const ::turtlebot_node::MVServRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd3cc9a10efcfe829ULL;
  static const uint64_t static_value2 = 0x3203cd968ed57a1bULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_node::MVServRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlebot_node/MVServRequest";
  }

  static const char* value(const ::turtlebot_node::MVServRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_node::MVServRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string param\n\
float32 coord_x\n\
float32 coord_y\n\
float32 coord_ang\n\
";
  }

  static const char* value(const ::turtlebot_node::MVServRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlebot_node::MVServRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.param);
      stream.next(m.coord_x);
      stream.next(m.coord_y);
      stream.next(m.coord_ang);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MVServRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_node::MVServRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlebot_node::MVServRequest_<ContainerAllocator>& v)
  {
    s << indent << "param: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.param);
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

#endif // TURTLEBOT_NODE_MESSAGE_MVSERVREQUEST_H