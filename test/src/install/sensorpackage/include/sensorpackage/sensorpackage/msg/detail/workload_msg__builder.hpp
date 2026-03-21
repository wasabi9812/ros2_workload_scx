// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sensorpackage:msg/WorkloadMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensorpackage/msg/workload_msg.hpp"


#ifndef SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__BUILDER_HPP_
#define SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sensorpackage/msg/detail/workload_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sensorpackage
{

namespace msg
{

namespace builder
{

class Init_WorkloadMsg_payload
{
public:
  explicit Init_WorkloadMsg_payload(::sensorpackage::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  ::sensorpackage::msg::WorkloadMsg payload(::sensorpackage::msg::WorkloadMsg::_payload_type arg)
  {
    msg_.payload = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sensorpackage::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_element_size
{
public:
  explicit Init_WorkloadMsg_element_size(::sensorpackage::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_payload element_size(::sensorpackage::msg::WorkloadMsg::_element_size_type arg)
  {
    msg_.element_size = std::move(arg);
    return Init_WorkloadMsg_payload(msg_);
  }

private:
  ::sensorpackage::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_height
{
public:
  explicit Init_WorkloadMsg_height(::sensorpackage::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_element_size height(::sensorpackage::msg::WorkloadMsg::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_WorkloadMsg_element_size(msg_);
  }

private:
  ::sensorpackage::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_width
{
public:
  explicit Init_WorkloadMsg_width(::sensorpackage::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_height width(::sensorpackage::msg::WorkloadMsg::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_WorkloadMsg_height(msg_);
  }

private:
  ::sensorpackage::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_encoding
{
public:
  explicit Init_WorkloadMsg_encoding(::sensorpackage::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_width encoding(::sensorpackage::msg::WorkloadMsg::_encoding_type arg)
  {
    msg_.encoding = std::move(arg);
    return Init_WorkloadMsg_width(msg_);
  }

private:
  ::sensorpackage::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_profile
{
public:
  explicit Init_WorkloadMsg_profile(::sensorpackage::msg::WorkloadMsg & msg)
  : msg_(msg)
  {}
  Init_WorkloadMsg_encoding profile(::sensorpackage::msg::WorkloadMsg::_profile_type arg)
  {
    msg_.profile = std::move(arg);
    return Init_WorkloadMsg_encoding(msg_);
  }

private:
  ::sensorpackage::msg::WorkloadMsg msg_;
};

class Init_WorkloadMsg_seq
{
public:
  Init_WorkloadMsg_seq()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WorkloadMsg_profile seq(::sensorpackage::msg::WorkloadMsg::_seq_type arg)
  {
    msg_.seq = std::move(arg);
    return Init_WorkloadMsg_profile(msg_);
  }

private:
  ::sensorpackage::msg::WorkloadMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sensorpackage::msg::WorkloadMsg>()
{
  return sensorpackage::msg::builder::Init_WorkloadMsg_seq();
}

}  // namespace sensorpackage

#endif  // SENSORPACKAGE__MSG__DETAIL__WORKLOAD_MSG__BUILDER_HPP_
