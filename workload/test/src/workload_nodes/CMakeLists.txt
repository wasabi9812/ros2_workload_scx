cmake_minimum_required(VERSION 3.8)
project(workload_nodes)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/WorkloadMsg.msg"
)

add_executable(sensor_source src/sensor_source.cpp)
ament_target_dependencies(sensor_source rclcpp std_msgs)

rosidl_target_interfaces(sensor_source
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS
  sensor_source
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()