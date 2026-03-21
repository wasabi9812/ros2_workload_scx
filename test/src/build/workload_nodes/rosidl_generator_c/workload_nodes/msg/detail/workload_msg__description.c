// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from workload_nodes:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

#include "workload_nodes/msg/detail/workload_msg__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_workload_nodes
const rosidl_type_hash_t *
workload_nodes__msg__WorkloadMsg__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x70, 0xbc, 0x6c, 0xbc, 0x04, 0xc9, 0x16, 0x37,
      0xa8, 0x09, 0x9e, 0x1a, 0x15, 0xee, 0x84, 0x9a,
      0x27, 0x93, 0xf8, 0x10, 0x69, 0x8b, 0x86, 0xed,
      0xa4, 0xf1, 0x80, 0x36, 0x38, 0x1c, 0xbf, 0xc3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char workload_nodes__msg__WorkloadMsg__TYPE_NAME[] = "workload_nodes/msg/WorkloadMsg";

// Define type names, field names, and default values
static char workload_nodes__msg__WorkloadMsg__FIELD_NAME__seq[] = "seq";
static char workload_nodes__msg__WorkloadMsg__FIELD_NAME__profile[] = "profile";
static char workload_nodes__msg__WorkloadMsg__FIELD_NAME__encoding[] = "encoding";
static char workload_nodes__msg__WorkloadMsg__FIELD_NAME__width[] = "width";
static char workload_nodes__msg__WorkloadMsg__FIELD_NAME__height[] = "height";
static char workload_nodes__msg__WorkloadMsg__FIELD_NAME__element_size[] = "element_size";
static char workload_nodes__msg__WorkloadMsg__FIELD_NAME__payload[] = "payload";

static rosidl_runtime_c__type_description__Field workload_nodes__msg__WorkloadMsg__FIELDS[] = {
  {
    {workload_nodes__msg__WorkloadMsg__FIELD_NAME__seq, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {workload_nodes__msg__WorkloadMsg__FIELD_NAME__profile, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {workload_nodes__msg__WorkloadMsg__FIELD_NAME__encoding, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {workload_nodes__msg__WorkloadMsg__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {workload_nodes__msg__WorkloadMsg__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {workload_nodes__msg__WorkloadMsg__FIELD_NAME__element_size, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {workload_nodes__msg__WorkloadMsg__FIELD_NAME__payload, 7, 7},
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
workload_nodes__msg__WorkloadMsg__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {workload_nodes__msg__WorkloadMsg__TYPE_NAME, 30, 30},
      {workload_nodes__msg__WorkloadMsg__FIELDS, 7, 7},
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
workload_nodes__msg__WorkloadMsg__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {workload_nodes__msg__WorkloadMsg__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 105, 105},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
workload_nodes__msg__WorkloadMsg__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *workload_nodes__msg__WorkloadMsg__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
