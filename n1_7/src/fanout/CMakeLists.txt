cmake_minimum_required(VERSION 3.8)
project(fanout)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor REQUIRED)

add_executable(n5 src/n5.cpp)
ament_target_dependencies(n5 rclcpp sensor)

add_executable(n6 src/n6.cpp)
ament_target_dependencies(n6 rclcpp sensor)

add_executable(n7 src/n7.cpp)
ament_target_dependencies(n7 rclcpp sensor)

install(TARGETS
  n5
  n6
  n7
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

ament_export_dependencies(rclcpp sensor)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
