// Generated by gencpp from file svg_ros/InputsPlannerSrvResponse.msg
// DO NOT EDIT!


#ifndef SVG_ROS_MESSAGE_INPUTSPLANNERSRVRESPONSE_H
#define SVG_ROS_MESSAGE_INPUTSPLANNERSRVRESPONSE_H


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
struct InputsPlannerSrvResponse_
{
  typedef InputsPlannerSrvResponse_<ContainerAllocator> Type;

  InputsPlannerSrvResponse_()
    : origin_x(0.0)
    , origin_y(0.0)
    , origin_angRob(0.0)
    , dest_x(0.0)
    , dest_y(0.0)
    , sensorBool()
    , num_sensorsInt(0)
    , angle_sensor_orig(0.0)
    , range_angleRob(0.0)
    , radiusRob(0.0)
    , advance(0.0)
    , max_angle(0.0)
    , num_steps(0)
    , select(0)
    , largest_sensor(0.0)
    , pathNAme()
    , fileNAme()
    , flgGUI(0)
    , flg_noise(0)
    , flg_real_environment(0)  {
    }
  InputsPlannerSrvResponse_(const ContainerAllocator& _alloc)
    : origin_x(0.0)
    , origin_y(0.0)
    , origin_angRob(0.0)
    , dest_x(0.0)
    , dest_y(0.0)
    , sensorBool(_alloc)
    , num_sensorsInt(0)
    , angle_sensor_orig(0.0)
    , range_angleRob(0.0)
    , radiusRob(0.0)
    , advance(0.0)
    , max_angle(0.0)
    , num_steps(0)
    , select(0)
    , largest_sensor(0.0)
    , pathNAme(_alloc)
    , fileNAme(_alloc)
    , flgGUI(0)
    , flg_noise(0)
    , flg_real_environment(0)  {
  (void)_alloc;
    }



   typedef double _origin_x_type;
  _origin_x_type origin_x;

   typedef double _origin_y_type;
  _origin_y_type origin_y;

   typedef double _origin_angRob_type;
  _origin_angRob_type origin_angRob;

   typedef double _dest_x_type;
  _dest_x_type dest_x;

   typedef double _dest_y_type;
  _dest_y_type dest_y;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _sensorBool_type;
  _sensorBool_type sensorBool;

   typedef int32_t _num_sensorsInt_type;
  _num_sensorsInt_type num_sensorsInt;

   typedef double _angle_sensor_orig_type;
  _angle_sensor_orig_type angle_sensor_orig;

   typedef double _range_angleRob_type;
  _range_angleRob_type range_angleRob;

   typedef double _radiusRob_type;
  _radiusRob_type radiusRob;

   typedef double _advance_type;
  _advance_type advance;

   typedef double _max_angle_type;
  _max_angle_type max_angle;

   typedef int32_t _num_steps_type;
  _num_steps_type num_steps;

   typedef int32_t _select_type;
  _select_type select;

   typedef double _largest_sensor_type;
  _largest_sensor_type largest_sensor;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _pathNAme_type;
  _pathNAme_type pathNAme;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _fileNAme_type;
  _fileNAme_type fileNAme;

   typedef int32_t _flgGUI_type;
  _flgGUI_type flgGUI;

   typedef int32_t _flg_noise_type;
  _flg_noise_type flg_noise;

   typedef int32_t _flg_real_environment_type;
  _flg_real_environment_type flg_real_environment;




  typedef boost::shared_ptr< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct InputsPlannerSrvResponse_

typedef ::svg_ros::InputsPlannerSrvResponse_<std::allocator<void> > InputsPlannerSrvResponse;

typedef boost::shared_ptr< ::svg_ros::InputsPlannerSrvResponse > InputsPlannerSrvResponsePtr;
typedef boost::shared_ptr< ::svg_ros::InputsPlannerSrvResponse const> InputsPlannerSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d759259a9c48e22d7e4bb3b06715da4c";
  }

  static const char* value(const ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd759259a9c48e22dULL;
  static const uint64_t static_value2 = 0x7e4bb3b06715da4cULL;
};

template<class ContainerAllocator>
struct DataType< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "svg_ros/InputsPlannerSrvResponse";
  }

  static const char* value(const ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 origin_x\n\
float64 origin_y\n\
float64 origin_angRob\n\
float64 dest_x\n\
float64 dest_y\n\
string sensorBool\n\
int32 num_sensorsInt\n\
float64 angle_sensor_orig\n\
float64 range_angleRob\n\
float64 radiusRob\n\
float64 advance\n\
float64 max_angle\n\
int32 num_steps\n\
int32 select\n\
float64 largest_sensor\n\
string pathNAme\n\
string fileNAme\n\
int32 flgGUI\n\
int32 flg_noise\n\
int32 flg_real_environment\n\
\n\
";
  }

  static const char* value(const ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.origin_x);
      stream.next(m.origin_y);
      stream.next(m.origin_angRob);
      stream.next(m.dest_x);
      stream.next(m.dest_y);
      stream.next(m.sensorBool);
      stream.next(m.num_sensorsInt);
      stream.next(m.angle_sensor_orig);
      stream.next(m.range_angleRob);
      stream.next(m.radiusRob);
      stream.next(m.advance);
      stream.next(m.max_angle);
      stream.next(m.num_steps);
      stream.next(m.select);
      stream.next(m.largest_sensor);
      stream.next(m.pathNAme);
      stream.next(m.fileNAme);
      stream.next(m.flgGUI);
      stream.next(m.flg_noise);
      stream.next(m.flg_real_environment);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct InputsPlannerSrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::svg_ros::InputsPlannerSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "origin_x: ";
    Printer<double>::stream(s, indent + "  ", v.origin_x);
    s << indent << "origin_y: ";
    Printer<double>::stream(s, indent + "  ", v.origin_y);
    s << indent << "origin_angRob: ";
    Printer<double>::stream(s, indent + "  ", v.origin_angRob);
    s << indent << "dest_x: ";
    Printer<double>::stream(s, indent + "  ", v.dest_x);
    s << indent << "dest_y: ";
    Printer<double>::stream(s, indent + "  ", v.dest_y);
    s << indent << "sensorBool: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.sensorBool);
    s << indent << "num_sensorsInt: ";
    Printer<int32_t>::stream(s, indent + "  ", v.num_sensorsInt);
    s << indent << "angle_sensor_orig: ";
    Printer<double>::stream(s, indent + "  ", v.angle_sensor_orig);
    s << indent << "range_angleRob: ";
    Printer<double>::stream(s, indent + "  ", v.range_angleRob);
    s << indent << "radiusRob: ";
    Printer<double>::stream(s, indent + "  ", v.radiusRob);
    s << indent << "advance: ";
    Printer<double>::stream(s, indent + "  ", v.advance);
    s << indent << "max_angle: ";
    Printer<double>::stream(s, indent + "  ", v.max_angle);
    s << indent << "num_steps: ";
    Printer<int32_t>::stream(s, indent + "  ", v.num_steps);
    s << indent << "select: ";
    Printer<int32_t>::stream(s, indent + "  ", v.select);
    s << indent << "largest_sensor: ";
    Printer<double>::stream(s, indent + "  ", v.largest_sensor);
    s << indent << "pathNAme: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.pathNAme);
    s << indent << "fileNAme: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.fileNAme);
    s << indent << "flgGUI: ";
    Printer<int32_t>::stream(s, indent + "  ", v.flgGUI);
    s << indent << "flg_noise: ";
    Printer<int32_t>::stream(s, indent + "  ", v.flg_noise);
    s << indent << "flg_real_environment: ";
    Printer<int32_t>::stream(s, indent + "  ", v.flg_real_environment);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SVG_ROS_MESSAGE_INPUTSPLANNERSRVRESPONSE_H
