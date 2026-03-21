// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from workload_nodes:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "workload_nodes/msg/workload_msg.hpp"


#ifndef WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__BUILDER_HPP_
#define WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "workload_nodes/msg/detail/workload_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace workload_nodes
{

namespace msg
{

namespace builder
{

class Init_WorkloadMsg_payload
{
public:
  explicit Init_WorkloadMsg_payload(::workload_nodes::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  ::workload_nodes::msg::WorkloadMsg payload(::workload_nodes::msg::WorkloadMsg::_payload_type arg)
  {
    msg_.payload = std::move(arg);
    return std::move(msg_);
  }

private:
  ::workload_nodes::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_element_size
{
public:
  explicit Init_WorkloadMsg_element_size(::workload_nodes::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_payload element_size(::workload_nodes::msg::WorkloadMsg::_element_size_type arg)
  {
    msg_.element_size = std::move(arg);
    return Init_WorkloadMsg_payload(msg_);
  }

private:
  ::workload_nodes::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_height
{
public:
  explicit Init_WorkloadMsg_height(::workload_nodes::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_element_size height(::workload_nodes::msg::WorkloadMsg::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_WorkloadMsg_element_size(msg_);
  }

private:
  ::workload_nodes::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_width
{
public:
  explicit Init_WorkloadMsg_width(::workload_nodes::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_height width(::workload_nodes::msg::WorkloadMsg::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_WorkloadMsg_height(msg_);
  }

private:
  ::workload_nodes::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_encoding
{
public:
  explicit Init_WorkloadMsg_encoding(::workload_nodes::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_width encoding(::workload_nodes::msg::WorkloadMsg::_encoding_type arg)
  {
    msg_.encoding = std::move(arg);
    return Init_WorkloadMsg_width(msg_);
  }

private:
  ::workload_nodes::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_profile
{
public:
  explicit Init_WorkloadMsg_profile(::workload_nodes::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_encoding profile(::workload_nodes::msg::WorkloadMsg::_profile_type arg)
  {
    msg_.profile = std::move(arg);
    return Init_WorkloadMsg_encoding(msg_);
  }

private:
  ::workload_nodes::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_seq
{
public:
  Init_WorkloadMsg_seq()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WorkloadMsg_profile seq(::workload_nodes::msg::WorkloadMsg::_seq_type arg)
  {
    msg_.seq = std::move(arg);
    return Init_WorkloadMsg_profile(msg_);
  }

private:
  ::workload_nodes::msg::WorkloadMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::workload_nodes::msg::WorkloadMsg>()
{
  return workload_nodes::msg::builder::Init_WorkloadMsg_seq();
}

}  // namespace workload_nodes

#endif  // WORKLOAD_NODES__MSG__DETAIL__WORKLOAD_MSG__BUILDER_HPP_
