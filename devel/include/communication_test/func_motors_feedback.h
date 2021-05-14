// Generated by gencpp from file communication_test/func_motors_feedback.msg
// DO NOT EDIT!


#ifndef COMMUNICATION_TEST_MESSAGE_FUNC_MOTORS_FEEDBACK_H
#define COMMUNICATION_TEST_MESSAGE_FUNC_MOTORS_FEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace communication_test
{
template <class ContainerAllocator>
struct func_motors_feedback_
{
  typedef func_motors_feedback_<ContainerAllocator> Type;

  func_motors_feedback_()
    : Encorder_linearModule(0)
    , Hall_putter_1_left(0)
    , Hall_putter_1_right(0)
    , Hall_putter_2_left(0)
    , Hall_putter_2_right(0)
    , Hall_putter_3_left(0)
    , Hall_putter_3_right(0)  {
    }
  func_motors_feedback_(const ContainerAllocator& _alloc)
    : Encorder_linearModule(0)
    , Hall_putter_1_left(0)
    , Hall_putter_1_right(0)
    , Hall_putter_2_left(0)
    , Hall_putter_2_right(0)
    , Hall_putter_3_left(0)
    , Hall_putter_3_right(0)  {
  (void)_alloc;
    }



   typedef int32_t _Encorder_linearModule_type;
  _Encorder_linearModule_type Encorder_linearModule;

   typedef int32_t _Hall_putter_1_left_type;
  _Hall_putter_1_left_type Hall_putter_1_left;

   typedef int32_t _Hall_putter_1_right_type;
  _Hall_putter_1_right_type Hall_putter_1_right;

   typedef int32_t _Hall_putter_2_left_type;
  _Hall_putter_2_left_type Hall_putter_2_left;

   typedef int32_t _Hall_putter_2_right_type;
  _Hall_putter_2_right_type Hall_putter_2_right;

   typedef int32_t _Hall_putter_3_left_type;
  _Hall_putter_3_left_type Hall_putter_3_left;

   typedef int32_t _Hall_putter_3_right_type;
  _Hall_putter_3_right_type Hall_putter_3_right;





  typedef boost::shared_ptr< ::communication_test::func_motors_feedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::communication_test::func_motors_feedback_<ContainerAllocator> const> ConstPtr;

}; // struct func_motors_feedback_

typedef ::communication_test::func_motors_feedback_<std::allocator<void> > func_motors_feedback;

typedef boost::shared_ptr< ::communication_test::func_motors_feedback > func_motors_feedbackPtr;
typedef boost::shared_ptr< ::communication_test::func_motors_feedback const> func_motors_feedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::communication_test::func_motors_feedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::communication_test::func_motors_feedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace communication_test

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'communication_test': ['/home/ubuntu/xRobot_ws/src/communication_test/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::communication_test::func_motors_feedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::communication_test::func_motors_feedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication_test::func_motors_feedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::communication_test::func_motors_feedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication_test::func_motors_feedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::communication_test::func_motors_feedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::communication_test::func_motors_feedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "71b9c468b90827306b28dd711ec11502";
  }

  static const char* value(const ::communication_test::func_motors_feedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x71b9c468b9082730ULL;
  static const uint64_t static_value2 = 0x6b28dd711ec11502ULL;
};

template<class ContainerAllocator>
struct DataType< ::communication_test::func_motors_feedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "communication_test/func_motors_feedback";
  }

  static const char* value(const ::communication_test::func_motors_feedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::communication_test::func_motors_feedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "    int32 Encorder_linearModule  \n\
    int32 Hall_putter_1_left     \n\
    int32 Hall_putter_1_right   \n\
    int32 Hall_putter_2_left     \n\
    int32 Hall_putter_2_right   \n\
    int32 Hall_putter_3_left     \n\
    int32 Hall_putter_3_right    \n\
";
  }

  static const char* value(const ::communication_test::func_motors_feedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::communication_test::func_motors_feedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Encorder_linearModule);
      stream.next(m.Hall_putter_1_left);
      stream.next(m.Hall_putter_1_right);
      stream.next(m.Hall_putter_2_left);
      stream.next(m.Hall_putter_2_right);
      stream.next(m.Hall_putter_3_left);
      stream.next(m.Hall_putter_3_right);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct func_motors_feedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::communication_test::func_motors_feedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::communication_test::func_motors_feedback_<ContainerAllocator>& v)
  {
    s << indent << "Encorder_linearModule: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Encorder_linearModule);
    s << indent << "Hall_putter_1_left: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Hall_putter_1_left);
    s << indent << "Hall_putter_1_right: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Hall_putter_1_right);
    s << indent << "Hall_putter_2_left: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Hall_putter_2_left);
    s << indent << "Hall_putter_2_right: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Hall_putter_2_right);
    s << indent << "Hall_putter_3_left: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Hall_putter_3_left);
    s << indent << "Hall_putter_3_right: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Hall_putter_3_right);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMUNICATION_TEST_MESSAGE_FUNC_MOTORS_FEEDBACK_H
