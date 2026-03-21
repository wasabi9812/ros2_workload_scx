// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from workload_nodes:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice
#include "workload_nodes/msg/detail/workload_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `profile`
// Member `encoding`
#include "rosidl_runtime_c/string_functions.h"
// Member `payload`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
workload_nodes__msg__WorkloadMsg__init(workload_nodes__msg__WorkloadMsg * msg)
{
  if (!msg) {
    return false;
  }
  // seq
  // profile
  if (!rosidl_runtime_c__String__init(&msg->profile)) {
    workload_nodes__msg__WorkloadMsg__fini(msg);
    return false;
  }
  // encoding
  if (!rosidl_runtime_c__String__init(&msg->encoding)) {
    workload_nodes__msg__WorkloadMsg__fini(msg);
    return false;
  }
  // width
  // height
  // element_size
  // payload
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->payload, 0)) {
    workload_nodes__msg__WorkloadMsg__fini(msg);
    return false;
  }
  return true;
}

void
workload_nodes__msg__WorkloadMsg__fini(workload_nodes__msg__WorkloadMsg * msg)
{
  if (!msg) {
    return;
  }
  // seq
  // profile
  rosidl_runtime_c__String__fini(&msg->profile);
  // encoding
  rosidl_runtime_c__String__fini(&msg->encoding);
  // width
  // height
  // element_size
  // payload
  rosidl_runtime_c__uint8__Sequence__fini(&msg->payload);
}

bool
workload_nodes__msg__WorkloadMsg__are_equal(const workload_nodes__msg__WorkloadMsg * lhs, const workload_nodes__msg__WorkloadMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // seq
  if (lhs->seq != rhs->seq) {
    return false;
  }
  // profile
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->profile), &(rhs->profile)))
  {
    return false;
  }
  // encoding
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->encoding), &(rhs->encoding)))
  {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // element_size
  if (lhs->element_size != rhs->element_size) {
    return false;
  }
  // payload
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->payload), &(rhs->payload)))
  {
    return false;
  }
  return true;
}

bool
workload_nodes__msg__WorkloadMsg__copy(
  const workload_nodes__msg__WorkloadMsg * input,
  workload_nodes__msg__WorkloadMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // seq
  output->seq = input->seq;
  // profile
  if (!rosidl_runtime_c__String__copy(
      &(input->profile), &(output->profile)))
  {
    return false;
  }
  // encoding
  if (!rosidl_runtime_c__String__copy(
      &(input->encoding), &(output->encoding)))
  {
    return false;
  }
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  // element_size
  output->element_size = input->element_size;
  // payload
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->payload), &(output->payload)))
  {
    return false;
  }
  return true;
}

workload_nodes__msg__WorkloadMsg *
workload_nodes__msg__WorkloadMsg__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  workload_nodes__msg__WorkloadMsg * msg = (workload_nodes__msg__WorkloadMsg *)allocator.allocate(sizeof(workload_nodes__msg__WorkloadMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(workload_nodes__msg__WorkloadMsg));
  bool success = workload_nodes__msg__WorkloadMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
workload_nodes__msg__WorkloadMsg__destroy(workload_nodes__msg__WorkloadMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    workload_nodes__msg__WorkloadMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
workload_nodes__msg__WorkloadMsg__Sequence__init(workload_nodes__msg__WorkloadMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  workload_nodes__msg__WorkloadMsg * data = NULL;

  if (size) {
    data = (workload_nodes__msg__WorkloadMsg *)allocator.zero_allocate(size, sizeof(workload_nodes__msg__WorkloadMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = workload_nodes__msg__WorkloadMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        workload_nodes__msg__WorkloadMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
workload_nodes__msg__WorkloadMsg__Sequence__fini(workload_nodes__msg__WorkloadMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      workload_nodes__msg__WorkloadMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

workload_nodes__msg__WorkloadMsg__Sequence *
workload_nodes__msg__WorkloadMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  workload_nodes__msg__WorkloadMsg__Sequence * array = (workload_nodes__msg__WorkloadMsg__Sequence *)allocator.allocate(sizeof(workload_nodes__msg__WorkloadMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = workload_nodes__msg__WorkloadMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
workload_nodes__msg__WorkloadMsg__Sequence__destroy(workload_nodes__msg__WorkloadMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    workload_nodes__msg__WorkloadMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
workload_nodes__msg__WorkloadMsg__Sequence__are_equal(const workload_nodes__msg__WorkloadMsg__Sequence * lhs, const workload_nodes__msg__WorkloadMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!workload_nodes__msg__WorkloadMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
workload_nodes__msg__WorkloadMsg__Sequence__copy(
  const workload_nodes__msg__WorkloadMsg__Sequence * input,
  workload_nodes__msg__WorkloadMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(workload_nodes__msg__WorkloadMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    workload_nodes__msg__WorkloadMsg * data =
      (workload_nodes__msg__WorkloadMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!workload_nodes__msg__WorkloadMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          workload_nodes__msg__WorkloadMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!workload_nodes__msg__WorkloadMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
