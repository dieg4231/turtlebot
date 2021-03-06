// Generated by gencpp from file svg_ros/MVPlannerSrvResponse.msg
// DO NOT EDIT!


#ifndef SVG_ROS_MESSAGE_MVPLANNERSRVRESPONSE_H
#define SVG_ROS_MESSAGE_MVPLANNERSRVRESPONSE_H


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
struct MVPlannerSrvResponse_
{
  typedef MVPlannerSrvResponse_<ContainerAllocator> Type;

  MVPlannerSrvResponse_()
    : param()
    , coord_x(0.0)
    , coord_y(0.0)
    , coord_ang(0.0)
    , flgGUI(0)  {
    }
  MVPlannerSrvResponse_(const ContainerAllocator& _alloc)
    : param(_alloc)
    , coord_x(0.0)
    , coord_y(0.0)
    , coord_ang(0.0)
    , flgGUI(0)  {
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

   typedef int32_t _flgGUI_type;
  _flgGUI_type flgGUI;




  typedef boost::shared_ptr< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MVPlannerSrvResponse_

typedef ::svg_ros::MVPlannerSrvResponse_<std::allocator<void> > MVPlannerSrvResponse;

typedef boost::shared_ptr< ::svg_ros::MVPlannerSrvResponse > MVPlannerSrvResponsePtr;
typedef boost::shared_ptr< ::svg_ros::MVPlannerSrvResponse const> MVPlannerSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace svg_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "be72bb60132118a88a3b78f9e3944767";
  }

  static const char* value(const ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbe72bb60132118a8ULL;
  static const uint64_t static_value2 = 0x8a3b78f9e3944767ULL;
};

template<class ContainerAllocator>
struct DataType< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "svg_ros/MVPlannerSrvResponse";
  }

  static const char* value(const ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string param\n\
float32 coord_x\n\
float32 coord_y\n\
float32 coord_ang\n\
int32 flgGUI\n\
\n\
";
  }

  static const char* value(const ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.param);
      stream.next(m.coord_x);
      stream.next(m.coord_y);
      stream.next(m.coord_ang);
      stream.next(m.flgGUI);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MVPlannerSrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::svg_ros::MVPlannerSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "param: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.param);
    s << indent << "coord_x: ";
    Printer<float>::stream(s, indent + "  ", v.coord_x);
    s << indent << "coord_y: ";
    Printer<float>::stream(s, indent + "  ", v.coord_y);
    s << indent << "coord_ang: ";
    Printer<float>::stream(s, indent + "  ", v.coord_ang);
    s << indent << "flgGUI: ";
    Printer<int32_t>::stream(s, indent + "  ", v.flgGUI);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SVG_ROS_MESSAGE_MVPLANNERSRVRESPONSE_H
