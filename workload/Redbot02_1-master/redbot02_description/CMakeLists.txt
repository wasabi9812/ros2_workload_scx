cmake_minimum_required(VERSION 2.8.3)
project(redbot02_description)

find_package(catkin REQUIRED COMPONENTS
  urdf
  xacro
  tf
)

catkin_package(
  CATKIN_DEPENDS urdf xacro
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

install(DIRECTORY urdf tf meshes
    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
)