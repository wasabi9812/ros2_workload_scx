// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from sensor:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice
#include "sensor/msg/detail/workload_msg__rosidl_typesupport_fastrtps_cpp.hpp"
#include "sensor/msg/detail/workload_msg__functions.h"
#include "sensor/msg/detail/workload_msg__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace sensor
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor
cdr_serialize(
  const sensor::msg::WorkloadMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: seq
  cdr << ros_message.seq;

  // Member: profile
  cdr << ros_message.profile;

  // Member: encoding
  cdr << ros_message.encoding;

  // Member: width
  cdr << ros_message.width;

  // Member: height
  cdr << ros_message.height;

  // Member: element_size
  cdr << ros_message.element_size;

  // Member: payload
  {
    cdr << ros_message.payload;
  }

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sensor::msg::WorkloadMsg & ros_message)
{
  // Member: seq
  cdr >> ros_message.seq;

  // Member: profile
  cdr >> ros_message.profile;

  // Member: encoding
  cdr >> ros_message.encoding;

  // Member: width
  cdr >> ros_message.width;

  // Member: height
  cdr >> ros_message.height;

  // Member: element_size
  cdr >> ros_message.element_size;

  // Member: payload
  {
    cdr >> ros_message.payload;
  }

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor
get_serialized_size(
  const sensor::msg::WorkloadMsg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: seq
  {
    size_t item_size = sizeof(ros_message.seq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: profile
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.profile.size() + 1);

  // Member: encoding
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.encoding.size() + 1);

  // Member: width
  {
    size_t item_size = sizeof(ros_message.width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: height
  {
    size_t item_size = sizeof(ros_message.height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: element_size
  {
    size_t item_size = sizeof(ros_message.element_size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: payload
  {
    size_t array_size = ros_message.payload.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.payload[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor
max_serialized_size_WorkloadMsg(
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

  // Member: seq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: profile
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
  // Member: encoding
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
  // Member: width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: height
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: element_size
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: payload
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
    using DataType = sensor::msg::WorkloadMsg;
    is_plain =
      (
      offsetof(DataType, payload) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor
cdr_serialize_key(
  const sensor::msg::WorkloadMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: seq
  cdr << ros_message.seq;

  // Member: profile
  cdr << ros_message.profile;

  // Member: encoding
  cdr << ros_message.encoding;

  // Member: width
  cdr << ros_message.width;

  // Member: height
  cdr << ros_message.height;

  // Member: element_size
  cdr << ros_message.element_size;

  // Member: payload
  {
    cdr << ros_message.payload;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor
get_serialized_size_key(
  const sensor::msg::WorkloadMsg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: seq
  {
    size_t item_size = sizeof(ros_message.seq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: profile
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.profile.size() + 1);

  // Member: encoding
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.encoding.size() + 1);

  // Member: width
  {
    size_t item_size = sizeof(ros_message.width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: height
  {
    size_t item_size = sizeof(ros_message.height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: element_size
  {
    size_t item_size = sizeof(ros_message.element_size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: payload
  {
    size_t array_size = ros_message.payload.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.payload[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sensor
max_serialized_size_key_WorkloadMsg(
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

  // Member: seq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: profile
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

  // Member: encoding
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

  // Member: width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: height
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: element_size
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: payload
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
    using DataType = sensor::msg::WorkloadMsg;
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
  auto typed_message =
    static_cast<const sensor::msg::WorkloadMsg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _WorkloadMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<sensor::msg::WorkloadMsg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _WorkloadMsg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const sensor::msg::WorkloadMsg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _WorkloadMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_WorkloadMsg(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _WorkloadMsg__callbacks = {
  "sensor::msg",
  "WorkloadMsg",
  _WorkloadMsg__cdr_serialize,
  _WorkloadMsg__cdr_deserialize,
  _WorkloadMsg__get_serialized_size,
  _WorkloadMsg__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _WorkloadMsg__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_WorkloadMsg__callbacks,
  get_message_typesupport_handle_function,
  &sensor__msg__WorkloadMsg__get_type_hash,
  &sensor__msg__WorkloadMsg__get_type_description,
  &sensor__msg__WorkloadMsg__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace sensor

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_sensor
const rosidl_message_type_support_t *
get_message_type_support_handle<sensor::msg::WorkloadMsg>()
{
  return &sensor::msg::typesupport_fastrtps_cpp::_WorkloadMsg__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sensor, msg, WorkloadMsg)() {
  return &sensor::msg::typesupport_fastrtps_cpp::_WorkloadMsg__handle;
}

#ifdef __cplusplus
}
#endif
