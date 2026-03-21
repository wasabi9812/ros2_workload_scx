// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sensor:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sensor/msg/detail/workload_msg__rosidl_typesupport_introspection_c.h"
#include "sensor/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sensor/msg/detail/workload_msg__functions.h"
#include "sensor/msg/detail/workload_msg__struct.h"


// Include directives for member types
// Member `profile`
// Member `encoding`
#include "rosidl_runtime_c/string_functions.h"
// Member `payload`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sensor__msg__WorkloadMsg__init(message_memory);
}

void sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_fini_function(void * message_memory)
{
  sensor__msg__WorkloadMsg__fini(message_memory);
}

size_t sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__size_function__WorkloadMsg__payload(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__get_const_function__WorkloadMsg__payload(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__get_function__WorkloadMsg__payload(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__fetch_function__WorkloadMsg__payload(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__get_const_function__WorkloadMsg__payload(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__assign_function__WorkloadMsg__payload(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__get_function__WorkloadMsg__payload(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__resize_function__WorkloadMsg__payload(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_message_member_array[7] = {
  {
    "seq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor__msg__WorkloadMsg, seq),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "profile",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor__msg__WorkloadMsg, profile),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "encoding",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor__msg__WorkloadMsg, encoding),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor__msg__WorkloadMsg, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor__msg__WorkloadMsg, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "element_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor__msg__WorkloadMsg, element_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "payload",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sensor__msg__WorkloadMsg, payload),  // bytes offset in struct
    NULL,  // default value
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__size_function__WorkloadMsg__payload,  // size() function pointer
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__get_const_function__WorkloadMsg__payload,  // get_const(index) function pointer
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__get_function__WorkloadMsg__payload,  // get(index) function pointer
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__fetch_function__WorkloadMsg__payload,  // fetch(index, &value) function pointer
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__assign_function__WorkloadMsg__payload,  // assign(index, value) function pointer
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__resize_function__WorkloadMsg__payload  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_message_members = {
  "sensor__msg",  // message namespace
  "WorkloadMsg",  // message name
  7,  // number of fields
  sizeof(sensor__msg__WorkloadMsg),
  false,  // has_any_key_member_
  sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_message_member_array,  // message members
  sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_message_type_support_handle = {
  0,
  &sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_message_members,
  get_message_typesupport_handle_function,
  &sensor__msg__WorkloadMsg__get_type_hash,
  &sensor__msg__WorkloadMsg__get_type_description,
  &sensor__msg__WorkloadMsg__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sensor
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor, msg, WorkloadMsg)() {
  if (!sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_message_type_support_handle.typesupport_identifier) {
    sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sensor__msg__WorkloadMsg__rosidl_typesupport_introspection_c__WorkloadMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
