## cmake버전
cmake_minimum_required(VERSION 2.8.3)
## 필수
## 프로젝트 이름
project(redbot02_core)

## 필수
## 빌드시 요구되는 구성요소 패키지 ex) roscpp ,std_msgs등등 msg 
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  nav_msgs
  sensor_msgs
  geometry_msgs
  tf
  diagnostic_msgs
  socketcan_interface
  can_msgs
)

## ROS이외의 패키지 사용 / 의존성 패키지를 먼저 설치하게 만드는 옵션
# find_package(Boost REQUIRED COMPONENTS system)

## ROS 파이썬을 사용할때 사용되는 옵션 참고 : http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

## 사용하는 메세지 파일을 추가 FiLES를 사용하면 현재패키지 폴더의 msg폴더안의 .msg를 참조하여 자동으로 헤더파일을 생성
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## 사용하는 서비스 파일을 추가 FiLES를 사용하면 현재패키지 폴더의 srv폴더안의 .srv를 참조하여 자동으로 헤더파일을 생성
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## 의존하는 메세지를 설정하는 옵션
#  generate_messages(
#    DEPENDENCIES
#    std_msgs
#    uvbot_msgs
#  )

## dynamic_reconfigure를 사용할떄 참조하는 설정파일을 불러오는 설정
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

## [INCLUDE_DIRS include]내부폴더 include안의 헤더를 사용하겠다는 뜻 [LIBRARIES 패키지] 패키지의 라이브러리를 사용하겠다는뜻 
## [CATKIN_DEPENDS 의존성패키지] 의존성패키지 지정 [DEPENDS system_lib] 시스템의존패키지를 의미
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES redbot02_core
  CATKIN_DEPENDS roscpp std_msgs 
)

## 필수
## include 폴더를 지정 할 수 있는 옵션 ${catkin_INCLUDE_DIRS}는 패키지안의 include폴더를 의미
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## 빌드후 생성할 라이브러리 선언 
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/redbot02_core.cpp
# )

## 해당 라이브러리 및 실행 파일을 빌드하기에 앞서 생성해야할 의존성이 있는 메세지 및 dynamic reconfigure가 있다면 우선적으로 이를 실행하라는 설정
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## 필수
## 빌드 후 실행 파일에 대한 옵션을 지정 
add_executable(redbot02_core 
  src/redbot02_core.cpp
  src/main.cpp)

## 해당 라이브러리 및 실행 파일을 빌드하기에 앞서 생성해야할 의존성이 있는 메세지 및 dynamic reconfigure가 있다면 우선적으로 이를 실행하라는 설정
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
# add_dependencies(redbot02_core uvbot_msgs_generate_messages_cpp ${catkin_EXPORTED_TARGETS})
## 필수 
## 지정 실행파일을 생성하기에 앞서 링크해야하는 라이브러리와 실행파일을 링크해주는 옵션
target_link_libraries(redbot02_core
  ${catkin_LIBRARIES}
 )



## 기타 ---------------------------------------------------------------------------------------------------------------------------

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_redbot02_core.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
