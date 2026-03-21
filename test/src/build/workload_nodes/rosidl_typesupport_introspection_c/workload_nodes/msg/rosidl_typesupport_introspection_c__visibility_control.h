// generated from
// rosidl_typesupport_introspection_c/resource/rosidl_typesupport_introspection_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef WORKLOAD_NODES__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_
#define WORKLOAD_NODES__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_workload_nodes __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_workload_nodes __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_workload_nodes __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_workload_nodes __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_INTROSPECTION_C_BUILDING_DLL_workload_nodes
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_workload_nodes ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_workload_nodes
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_workload_nodes ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_workload_nodes
  #endif
#else
  #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_workload_nodes __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_workload_nodes
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_workload_nodes __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_workload_nodes
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // WORKLOAD_NODES__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_
