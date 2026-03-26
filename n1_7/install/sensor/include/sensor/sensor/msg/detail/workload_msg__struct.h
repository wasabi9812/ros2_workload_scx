// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sensor:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor/msg/workload_msg.h"


#ifndef SENSOR__MSG__DETAIL__WORKLOAD_MSG__STRUCT_H_
#define SENSOR__MSG__DETAIL__WORKLOAD_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'profile'
// Member 'encoding'
#include "rosidl_runtime_c/string.h"
// Member 'payload'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/WorkloadMsg in the package sensor.
typedef struct sensor__msg__WorkloadMsg
{
  uint64_t seq;
  rosidl_runtime_c__String profile;
  rosidl_runtime_c__String encoding;
  uint32_t width;
  uint32_t height;
  uint32_t element_size;
  rosidl_runtime_c__uint8__Sequence payload;
} sensor__msg__WorkloadMsg;

// Struct for a sequence of sensor__msg__WorkloadMsg.
typedef struct sensor__msg__WorkloadMsg__Sequence
{
  sensor__msg__WorkloadMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sensor__msg__WorkloadMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SENSOR__MSG__DETAIL__WORKLOAD_MSG__STRUCT_H_
