// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from workload_nodes:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "workload_nodes/msg/workload_msg.hpp"


#ifndef WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__TRAITS_HPP_
#define WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "workload_nodes/msg/detail/workload_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace workload_nodes
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

}  // namespace workload_nodes

namespace rosidl_generator_traits
{

[[deprecated("use workload_nodes::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const workload_nodes::msg::WorkloadMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  workload_nodes::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use workload_nodes::msg::to_yaml() instead")]]
inline std::string to_yaml(const workload_nodes::msg::WorkloadMsg & msg)
{
  return workload_nodes::msg::to_yaml(msg);
}

template<>
inline const char * data_type<workload_nodes::msg::WorkloadMsg>()
{
  return "workload_nodes::msg::WorkloadMsg";
}

template<>
inline const char * name<workload_nodes::msg::WorkloadMsg>()
{
  return "workload_nodes/msg/WorkloadMsg";
}

template<>
struct has_fixed_size<workload_nodes::msg::WorkloadMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<workload_nodes::msg::WorkloadMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<workload_nodes::msg::WorkloadMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__TRAITS_HPP_
