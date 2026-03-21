// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from sensorpackage:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

#include "sensorpackage/msg/detail/workload_msg__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_sensorpackage
const rosidl_type_hash_t *
sensorpackage__msg__WorkloadMsg__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x24, 0x0c, 0x41, 0xdd, 0x13, 0xcd, 0x57, 0xcb,
      0xc3, 0xa4, 0x0e, 0xbf, 0x31, 0xc6, 0x93, 0x27,
      0xcf, 0x56, 0x0b, 0x2f, 0x74, 0xfd, 0x4f, 0x23,
      0x0d, 0xcf, 0x9f, 0xd3, 0xa0, 0x47, 0xd1, 0x05,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char sensorpackage__msg__WorkloadMsg__TYPE_NAME[] = "sensorpackage/msg/WorkloadMsg";

// Define type names, field names, and default values
static char sensorpackage__msg__WorkloadMsg__FIELD_NAME__seq[] = "seq";
static char sensorpackage__msg__WorkloadMsg__FIELD_NAME__profile[] = "profile";
static char sensorpackage__msg__WorkloadMsg__FIELD_NAME__encoding[] = "encoding";
static char sensorpackage__msg__WorkloadMsg__FIELD_NAME__width[] = "width";
static char sensorpackage__msg__WorkloadMsg__FIELD_NAME__height[] = "height";
static char sensorpackage__msg__WorkloadMsg__FIELD_NAME__element_size[] = "element_size";
static char sensorpackage__msg__WorkloadMsg__FIELD_NAME__payload[] = "payload";

static rosidl_runtime_c__type_description__Field sensorpackage__msg__WorkloadMsg__FIELDS[] = {
  {
    {sensorpackage__msg__WorkloadMsg__FIELD_NAME__seq, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensorpackage__msg__WorkloadMsg__FIELD_NAME__profile, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensorpackage__msg__WorkloadMsg__FIELD_NAME__encoding, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensorpackage__msg__WorkloadMsg__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensorpackage__msg__WorkloadMsg__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensorpackage__msg__WorkloadMsg__FIELD_NAME__element_size, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {sensorpackage__msg__WorkloadMsg__FIELD_NAME__payload, 7, 7},
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
sensorpackage__msg__WorkloadMsg__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {sensorpackage__msg__WorkloadMsg__TYPE_NAME, 29, 29},
      {sensorpackage__msg__WorkloadMsg__FIELDS, 7, 7},
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
sensorpackage__msg__WorkloadMsg__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {sensorpackage__msg__WorkloadMsg__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 105, 105},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
sensorpackage__msg__WorkloadMsg__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *sensorpackage__msg__WorkloadMsg__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
