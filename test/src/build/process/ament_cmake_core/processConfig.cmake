# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_process_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED process_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(process_FOUND FALSE)
  elseif(NOT process_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(process_FOUND FALSE)
  endif()
  return()
endif()
set(_process_CONFIG_INCLUDED TRUE)

# output package information
if(NOT process_FIND_QUIETLY)
  message(STATUS "Found process: 0.0.0 (${process_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'process' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT process_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(process_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${process_DIR}/${_extra}")
endforeach()
