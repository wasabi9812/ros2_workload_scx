// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from sensorpackage:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice
#ifndef SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "sensorpackage/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "sensorpackage/msg/detail/workload_msg__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensorpackage
bool cdr_serialize_sensorpackage__msg__WorkloadMsg(
  const sensorpackage__msg__WorkloadMsg * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensorpackage
bool cdr_deserialize_sensorpackage__msg__WorkloadMsg(
  eprosima::fastcdr::Cdr &,
  sensorpackage__msg__WorkloadMsg * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensorpackage
size_t get_serialized_size_sensorpackage__msg__WorkloadMsg(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensorpackage
size_t max_serialized_size_sensorpackage__msg__WorkloadMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensorpackage
bool cdr_serialize_key_sensorpackage__msg__WorkloadMsg(
  const sensorpackage__msg__WorkloadMsg * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensorpackage
size_t get_serialized_size_key_sensorpackage__msg__WorkloadMsg(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensorpackage
size_t max_serialized_size_key_sensorpackage__msg__WorkloadMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sensorpackage
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensorpackage, msg, WorkloadMsg)();

#ifdef __cplusplus
}
#endif

#endif  // SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
