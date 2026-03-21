// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from workload_nodes:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "workload_nodes/msg/workload_msg.hpp"


#ifndef WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__STRUCT_HPP_
#define WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__workload_nodes__msg__WorkloadMsg __attribute__((deprecated))
#else
# define DEPRECATED__workload_nodes__msg__WorkloadMsg __declspec(deprecated)
#endif

namespace workload_nodes
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WorkloadMsg_
{
  using Type = WorkloadMsg_<ContainerAllocator>;

  explicit WorkloadMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seq = 0ull;
      this->profile = "";
      this->encoding = "";
      this->width = 0ul;
      this->height = 0ul;
      this->element_size = 0ul;
    }
  }

  explicit WorkloadMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : profile(_alloc),
    encoding(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seq = 0ull;
      this->profile = "";
      this->encoding = "";
      this->width = 0ul;
      this->height = 0ul;
      this->element_size = 0ul;
    }
  }

  // field types and members
  using _seq_type =
    uint64_t;
  _seq_type seq;
  using _profile_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _profile_type profile;
  using _encoding_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _encoding_type encoding;
  using _width_type =
    uint32_t;
  _width_type width;
  using _height_type =
    uint32_t;
  _height_type height;
  using _element_size_type =
    uint32_t;
  _element_size_type element_size;
  using _payload_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _payload_type payload;

  // setters for named parameter idiom
  Type & set__seq(
    const uint64_t & _arg)
  {
    this->seq = _arg;
    return *this;
  }
  Type & set__profile(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->profile = _arg;
    return *this;
  }
  Type & set__encoding(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->encoding = _arg;
    return *this;
  }
  Type & set__width(
    const uint32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const uint32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__element_size(
    const uint32_t & _arg)
  {
    this->element_size = _arg;
    return *this;
  }
  Type & set__payload(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->payload = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    workload_nodes::msg::WorkloadMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const workload_nodes::msg::WorkloadMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<workload_nodes::msg::WorkloadMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<workload_nodes::msg::WorkloadMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      workload_nodes::msg::WorkloadMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<workload_nodes::msg::WorkloadMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      workload_nodes::msg::WorkloadMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<workload_nodes::msg::WorkloadMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<workload_nodes::msg::WorkloadMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<workload_nodes::msg::WorkloadMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__workload_nodes__msg__WorkloadMsg
    std::shared_ptr<workload_nodes::msg::WorkloadMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__workload_nodes__msg__WorkloadMsg
    std::shared_ptr<workload_nodes::msg::WorkloadMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WorkloadMsg_ & other) const
  {
    if (this->seq != other.seq) {
      return false;
    }
    if (this->profile != other.profile) {
      return false;
    }
    if (this->encoding != other.encoding) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->element_size != other.element_size) {
      return false;
    }
    if (this->payload != other.payload) {
      return false;
    }
    return true;
  }
  bool operator!=(const WorkloadMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WorkloadMsg_

// alias to use template instance with default allocator
using WorkloadMsg =
  workload_nodes::msg::WorkloadMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace workload_nodes

#endif  // WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__STRUCT_HPP_
