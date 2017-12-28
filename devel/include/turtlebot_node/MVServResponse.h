// Generated by gencpp from file turtlebot_node/MVServResponse.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_NODE_MESSAGE_MVSERVRESPONSE_H
#define TURTLEBOT_NODE_MESSAGE_MVSERVRESPONSE_H


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
struct MVServResponse_
{
  typedef MVServResponse_<ContainerAllocator> Type;

  MVServResponse_()
    : answer()  {
    }
  MVServResponse_(const ContainerAllocator& _alloc)
    : answer(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _answer_type;
  _answer_type answer;




  typedef boost::shared_ptr< ::turtlebot_node::MVServResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_node::MVServResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MVServResponse_

typedef ::turtlebot_node::MVServResponse_<std::allocator<void> > MVServResponse;

typedef boost::shared_ptr< ::turtlebot_node::MVServResponse > MVServResponsePtr;
typedef boost::shared_ptr< ::turtlebot_node::MVServResponse const> MVServResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlebot_node::MVServResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlebot_node::MVServResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::turtlebot_node::MVServResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_node::MVServResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_node::MVServResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_node::MVServResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_node::MVServResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_node::MVServResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_node::MVServResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d7e708f879c94bb931716d8f4f130f30";
  }

  static const char* value(const ::turtlebot_node::MVServResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd7e708f879c94bb9ULL;
  static const uint64_t static_value2 = 0x31716d8f4f130f30ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_node::MVServResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlebot_node/MVServResponse";
  }

  static const char* value(const ::turtlebot_node::MVServResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_node::MVServResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string answer\n\
\n\
";
  }

  static const char* value(const ::turtlebot_node::MVServResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlebot_node::MVServResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.answer);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MVServResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_node::MVServResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlebot_node::MVServResponse_<ContainerAllocator>& v)
  {
    s << indent << "answer: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.answer);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT_NODE_MESSAGE_MVSERVRESPONSE_H
