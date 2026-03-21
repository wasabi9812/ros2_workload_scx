// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from sensor:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

#include "sensor/msg/detail/workload_msg__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_sensor
const rosidl_type_hash_t *
sensor__msg__WorkloadMsg__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb5, 0xd0, 0x24, 0x71, 0x54, 0xf5, 0xb4, 0xa0,
      0xa3, 0x5f, 0x3c, 0x58, 0xa8, 0xfb, 0x29, 0xa8,
      0xb7, 0xd7, 0xa8, 0x6b, 0x1b, 0x1d, 0xf7, 0x07,
      0x89, 0x87, 0xd5, 0x25, 0xa6, 0x08, 0xee, 0xe4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char sensor__msg__WorkloadMsg__TYPE_NAME[] = "sensor/msg/WorkloadMsg";

// Define type names, field names, and default values
static char sensor__msg__WorkloadMsg__FIELD_NAME__seq[] = "seq";
static char sensor__msg__WorkloadMsg__FIELD_NAME__profile[] = "profile";
static char sensor__msg__WorkloadMsg__FIELD_NAME__encoding[] = "encoding";
static char sensor__msg__WorkloadMsg__FIELD_NAME__width[] = "width";
static char sensor__msg__WorkloadMsg__FIELD_NAME__height[] = "height";
static char sensor__msg__WorkloadMsg__FIELD_NAME__element_size[] = "element_size";
static char sensor__msg__WorkloadMsg__FIELD_NAME__payload[] = "payload";

static rosidl_runtime_c__type_description__Field sensor__msg__WorkloadMsg__FIELDS[] = {
  {
    {sensor__msg__WorkloadMsg__FIELD_NAME__seq, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensor__msg__WorkloadMsg__FIELD_NAME__profile, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensor__msg__WorkloadMsg__FIELD_NAME__encoding, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensor__msg__WorkloadMsg__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensor__msg__WorkloadMsg__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensor__msg__WorkloadMsg__FIELD_NAME__element_size, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensor__msg__WorkloadMsg__FIELD_NAME__payload, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
sensor__msg__WorkloadMsg__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {sensor__msg__WorkloadMsg__TYPE_NAME, 22, 22},
      {sensor__msg__WorkloadMsg__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint64 seq\n"
  "string profile\n"
  "string encoding\n"
  "uint32 width\n"
  "uint32 height\n"
  "uint32 element_size\n"
  "uint8[] payload";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
sensor__msg__WorkloadMsg__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {sensor__msg__WorkloadMsg__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 105, 105},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
sensor__msg__WorkloadMsg__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *sensor__msg__WorkloadMsg__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
