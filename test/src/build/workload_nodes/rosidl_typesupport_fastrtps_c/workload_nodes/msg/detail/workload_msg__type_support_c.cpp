// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from workload_nodes:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice
#include "workload_nodes/msg/detail/workload_msg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "workload_nodes/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "workload_nodes/msg/detail/workload_msg__struct.h"
#include "workload_nodes/msg/detail/workload_msg__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // payload
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // payload
#include "rosidl_runtime_c/string.h"  // encoding, profile
#include "rosidl_runtime_c/string_functions.h"  // encoding, profile

// forward declare type support functions


using _WorkloadMsg__ros_msg_type = workload_nodes__msg__WorkloadMsg;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_workload_nodes
bool cdr_serialize_workload_nodes__msg__WorkloadMsg(
  const workload_nodes__msg__WorkloadMsg * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: seq
  {
    cdr << ros_message->seq;
  }

  // Field name: profile
  {
    const rosidl_runtime_c__String * str = &ros_message->profile;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: encoding
  {
    const rosidl_runtime_c__String * str = &ros_message->encoding;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: width
  {
    cdr << ros_message->width;
  }

  // Field name: height
  {
    cdr << ros_message->height;
  }

  // Field name: element_size
  {
    cdr << ros_message->element_size;
  }

  // Field name: payload
  {
    size_t size = ros_message->payload.size;
    auto array_ptr = ros_message->payload.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_workload_nodes
bool cdr_deserialize_workload_nodes__msg__WorkloadMsg(
  eprosima::fastcdr::Cdr & cdr,
  workload_nodes__msg__WorkloadMsg * ros_message)
{
  // Field name: seq
  {
    cdr >> ros_message->seq;
  }

  // Field name: profile
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->profile.data) {
      rosidl_runtime_c__String__init(&ros_message->profile);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->profile,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'profile'\n");
      return false;
    }
  }

  // Field name: encoding
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->encoding.data) {
      rosidl_runtime_c__String__init(&ros_message->encoding);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->encoding,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'encoding'\n");
      return false;
    }
  }

  // Field name: width
  {
    cdr >> ros_message->width;
  }

  // Field name: height
  {
    cdr >> ros_message->height;
  }

  // Field name: element_size
  {
    cdr >> ros_message->element_size;
  }

  // Field name: payload
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->payload.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->payload);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->payload, size)) {
      fprintf(stderr, "failed to create array for field 'payload'");
      return false;
    }
    auto array_ptr = ros_message->payload.data;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_workload_nodes
size_t get_serialized_size_workload_nodes__msg__WorkloadMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WorkloadMsg__ros_msg_type * ros_message = static_cast<const _WorkloadMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: seq
  {
    size_t item_size = sizeof(ros_message->seq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: profile
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->profile.size + 1);

  // Field name: encoding
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->encoding.size + 1);

  // Field name: width
  {
    size_t item_size = sizeof(ros_message->width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: height
  {
    size_t item_size = sizeof(ros_message->height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: element_size
  {
    size_t item_size = sizeof(ros_message->element_size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: payload
  {
    size_t array_size = ros_message->payload.size;
    auto array_ptr = ros_message->payload.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_workload_nodes
size_t max_serialized_size_workload_nodes__msg__WorkloadMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: seq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: profile
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: encoding
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: height
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: element_size
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: payload
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = workload_nodes__msg__WorkloadMsg;
    is_plain =
      (
      offsetof(DataType, payload) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_workload_nodes
bool cdr_serialize_key_workload_nodes__msg__WorkloadMsg(
  const workload_nodes__msg__WorkloadMsg * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: seq
  {
    cdr << ros_message->seq;
  }

  // Field name: profile
  {
    const rosidl_runtime_c__String * str = &ros_message->profile;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: encoding
  {
    const rosidl_runtime_c__String * str = &ros_message->encoding;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: width
  {
    cdr << ros_message->width;
  }

  // Field name: height
  {
    cdr << ros_message->height;
  }

  // Field name: element_size
  {
    cdr << ros_message->element_size;
  }

  // Field name: payload
  {
    size_t size = ros_message->payload.size;
    auto array_ptr = ros_message->payload.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_workload_nodes
size_t get_serialized_size_key_workload_nodes__msg__WorkloadMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WorkloadMsg__ros_msg_type * ros_message = static_cast<const _WorkloadMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: seq
  {
    size_t item_size = sizeof(ros_message->seq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: profile
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->profile.size + 1);

  // Field name: encoding
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->encoding.size + 1);

  // Field name: width
  {
    size_t item_size = sizeof(ros_message->width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: height
  {
    size_t item_size = sizeof(ros_message->height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: element_size
  {
    size_t item_size = sizeof(ros_message->element_size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: payload
  {
    size_t array_size = ros_message->payload.size;
    auto array_ptr = ros_message->payload.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_workload_nodes
size_t max_serialized_size_key_workload_nodes__msg__WorkloadMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: seq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: profile
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: encoding
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: height
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: element_size
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: payload
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = workload_nodes__msg__WorkloadMsg;
    is_plain =
      (
      offsetof(DataType, payload) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _WorkloadMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const workload_nodes__msg__WorkloadMsg * ros_message = static_cast<const workload_nodes__msg__WorkloadMsg *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_workload_nodes__msg__WorkloadMsg(ros_message, cdr);
}

static bool _WorkloadMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  workload_nodes__msg__WorkloadMsg * ros_message = static_cast<workload_nodes__msg__WorkloadMsg *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_workload_nodes__msg__WorkloadMsg(cdr, ros_message);
}

static uint32_t _WorkloadMsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_workload_nodes__msg__WorkloadMsg(
      untyped_ros_message, 0));
}

static size_t _WorkloadMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_workload_nodes__msg__WorkloadMsg(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_WorkloadMsg = {
  "workload_nodes::msg",
  "WorkloadMsg",
  _WorkloadMsg__cdr_serialize,
  _WorkloadMsg__cdr_deserialize,
  _WorkloadMsg__get_serialized_size,
  _WorkloadMsg__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _WorkloadMsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_WorkloadMsg,
  get_message_typesupport_handle_function,
  &workload_nodes__msg__WorkloadMsg__get_type_hash,
  &workload_nodes__msg__WorkloadMsg__get_type_description,
  &workload_nodes__msg__WorkloadMsg__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, workload_nodes, msg, WorkloadMsg)() {
  return &_WorkloadMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
