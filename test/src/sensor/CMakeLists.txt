cmake_minimum_required(VERSION 3.8)
project(sensor)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/WorkloadMsg.msg"
)

add_executable(sensor_source src/sensor_source.cpp)
ament_target_dependencies(sensor_source rclcpp)

rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(sensor_source "${cpp_typesupport_target}")

install(TARGETS
  sensor_source
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

ament_export_dependencies(rosidl_default_runtime rclcpp)

ament_package()
