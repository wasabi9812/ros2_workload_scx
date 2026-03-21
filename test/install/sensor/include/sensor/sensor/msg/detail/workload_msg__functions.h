// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sensor:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor/msg/workload_msg.h"


#ifndef SENSOR__MSG__DETAIL__WORKLOAD_MSG__FUNCTIONS_H_
#define SENSOR__MSG__DETAIL__WORKLOAD_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "sensor/msg/rosidl_generator_c__visibility_control.h"

#include "sensor/msg/detail/workload_msg__struct.h"

/// Initialize msg/WorkloadMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sensor__msg__WorkloadMsg
 * )) before or use
 * sensor__msg__WorkloadMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
bool
sensor__msg__WorkloadMsg__init(sensor__msg__WorkloadMsg * msg);

/// Finalize msg/WorkloadMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
void
sensor__msg__WorkloadMsg__fini(sensor__msg__WorkloadMsg * msg);

/// Create msg/WorkloadMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sensor__msg__WorkloadMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
sensor__msg__WorkloadMsg *
sensor__msg__WorkloadMsg__create(void);

/// Destroy msg/WorkloadMsg message.
/**
 * It calls
 * sensor__msg__WorkloadMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
void
sensor__msg__WorkloadMsg__destroy(sensor__msg__WorkloadMsg * msg);

/// Check for msg/WorkloadMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
bool
sensor__msg__WorkloadMsg__are_equal(const sensor__msg__WorkloadMsg * lhs, const sensor__msg__WorkloadMsg * rhs);

/// Copy a msg/WorkloadMsg message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
bool
sensor__msg__WorkloadMsg__copy(
  const sensor__msg__WorkloadMsg * input,
  sensor__msg__WorkloadMsg * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_sensor
const rosidl_type_hash_t *
sensor__msg__WorkloadMsg__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_sensor
const rosidl_runtime_c__type_description__TypeDescription *
sensor__msg__WorkloadMsg__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_sensor
const rosidl_runtime_c__type_description__TypeSource *
sensor__msg__WorkloadMsg__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_sensor
const rosidl_runtime_c__type_description__TypeSource__Sequence *
sensor__msg__WorkloadMsg__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/WorkloadMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * sensor__msg__WorkloadMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
bool
sensor__msg__WorkloadMsg__Sequence__init(sensor__msg__WorkloadMsg__Sequence * array, size_t size);

/// Finalize array of msg/WorkloadMsg messages.
/**
 * It calls
 * sensor__msg__WorkloadMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
void
sensor__msg__WorkloadMsg__Sequence__fini(sensor__msg__WorkloadMsg__Sequence * array);

/// Create array of msg/WorkloadMsg messages.
/**
 * It allocates the memory for the array and calls
 * sensor__msg__WorkloadMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
sensor__msg__WorkloadMsg__Sequence *
sensor__msg__WorkloadMsg__Sequence__create(size_t size);

/// Destroy array of msg/WorkloadMsg messages.
/**
 * It calls
 * sensor__msg__WorkloadMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
void
sensor__msg__WorkloadMsg__Sequence__destroy(sensor__msg__WorkloadMsg__Sequence * array);

/// Check for msg/WorkloadMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
bool
sensor__msg__WorkloadMsg__Sequence__are_equal(const sensor__msg__WorkloadMsg__Sequence * lhs, const sensor__msg__WorkloadMsg__Sequence * rhs);

/// Copy an array of msg/WorkloadMsg messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_sensor
bool
sensor__msg__WorkloadMsg__Sequence__copy(
  const sensor__msg__WorkloadMsg__Sequence * input,
  sensor__msg__WorkloadMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SENSOR__MSG__DETAIL__WORKLOAD_MSG__FUNCTIONS_H_
