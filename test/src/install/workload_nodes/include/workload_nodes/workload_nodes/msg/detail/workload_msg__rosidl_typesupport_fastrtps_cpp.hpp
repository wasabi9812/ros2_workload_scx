// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from workload_nodes:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

#ifndef WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "workload_nodes/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "workload_nodes/msg/detail/workload_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace workload_nodes
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_workload_nodes
cdr_serialize(
  const workload_nodes::msg::WorkloadMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_workload_nodes
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  workload_nodes::msg::WorkloadMsg & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_workload_nodes
get_serialized_size(
  const workload_nodes::msg::WorkloadMsg & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_workload_nodes
max_serialized_size_WorkloadMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_workload_nodes
cdr_serialize_key(
  const workload_nodes::msg::WorkloadMsg & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_workload_nodes
get_serialized_size_key(
  const workload_nodes::msg::WorkloadMsg & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_workload_nodes
max_serialized_size_key_WorkloadMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace workload_nodes

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_workload_nodes
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, workload_nodes, msg, WorkloadMsg)();

#ifdef __cplusplus
}
#endif

#endif  // WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
