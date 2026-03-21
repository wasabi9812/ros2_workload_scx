// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensorpackage:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensorpackage/msg/workload_msg.hpp"


#ifndef SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__TRAITS_HPP_
#define SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sensorpackage/msg/detail/workload_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sensorpackage
{

namespace msg
{

inline void to_flow_style_yaml(
  const WorkloadMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: seq
  {
    out << "seq: ";
    rosidl_generator_traits::value_to_yaml(msg.seq, out);
    out << ", ";
  }

  // member: profile
  {
    out << "profile: ";
    rosidl_generator_traits::value_to_yaml(msg.profile, out);
    out << ", ";
  }

  // member: encoding
  {
    out << "encoding: ";
    rosidl_generator_traits::value_to_yaml(msg.encoding, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: element_size
  {
    out << "element_size: ";
    rosidl_generator_traits::value_to_yaml(msg.element_size, out);
    out << ", ";
  }

  // member: payload
  {
    if (msg.payload.size() == 0) {
      out << "payload: []";
    } else {
      out << "payload: [";
      size_t pending_items = msg.payload.size();
      for (auto item : msg.payload) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WorkloadMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: seq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seq: ";
    rosidl_generator_traits::value_to_yaml(msg.seq, out);
    out << "\n";
  }

  // member: profile
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "profile: ";
    rosidl_generator_traits::value_to_yaml(msg.profile, out);
    out << "\n";
  }

  // member: encoding
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "encoding: ";
    rosidl_generator_traits::value_to_yaml(msg.encoding, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: element_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "element_size: ";
    rosidl_generator_traits::value_to_yaml(msg.element_size, out);
    out << "\n";
  }

  // member: payload
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.payload.size() == 0) {
      out << "payload: []\n";
    } else {
      out << "payload:\n";
      for (auto item : msg.payload) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WorkloadMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace sensorpackage

namespace rosidl_generator_traits
{

[[deprecated("use sensorpackage::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sensorpackage::msg::WorkloadMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  sensorpackage::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sensorpackage::msg::to_yaml() instead")]]
inline std::string to_yaml(const sensorpackage::msg::WorkloadMsg & msg)
{
  return sensorpackage::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sensorpackage::msg::WorkloadMsg>()
{
  return "sensorpackage::msg::WorkloadMsg";
}

template<>
inline const char * name<sensorpackage::msg::WorkloadMsg>()
{
  return "sensorpackage/msg/WorkloadMsg";
}

template<>
struct has_fixed_size<sensorpackage::msg::WorkloadMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensorpackage::msg::WorkloadMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sensorpackage::msg::WorkloadMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__TRAITS_HPP_
