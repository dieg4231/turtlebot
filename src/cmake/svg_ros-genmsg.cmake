# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "svg_ros: 0 messages, 7 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(svg_ros_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/MVServ.srv" NAME_WE)
add_custom_target(_svg_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svg_ros" "/home/savage/catkin_ws/src/svg_ros/srv/MVServ.srv" ""
)

get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/ReadySrv.srv" NAME_WE)
add_custom_target(_svg_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svg_ros" "/home/savage/catkin_ws/src/svg_ros/srv/ReadySrv.srv" ""
)

get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/InputsSrv.srv" NAME_WE)
add_custom_target(_svg_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svg_ros" "/home/savage/catkin_ws/src/svg_ros/srv/InputsSrv.srv" ""
)

get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/InputsPlannerSrv.srv" NAME_WE)
add_custom_target(_svg_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svg_ros" "/home/savage/catkin_ws/src/svg_ros/srv/InputsPlannerSrv.srv" ""
)

get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/LightSrv.srv" NAME_WE)
add_custom_target(_svg_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svg_ros" "/home/savage/catkin_ws/src/svg_ros/srv/LightSrv.srv" ""
)

get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/OverSrv.srv" NAME_WE)
add_custom_target(_svg_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svg_ros" "/home/savage/catkin_ws/src/svg_ros/srv/OverSrv.srv" ""
)

get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/SensorSrv.srv" NAME_WE)
add_custom_target(_svg_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svg_ros" "/home/savage/catkin_ws/src/svg_ros/srv/SensorSrv.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/MVServ.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
)
_generate_srv_cpp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/ReadySrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
)
_generate_srv_cpp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/InputsSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
)
_generate_srv_cpp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/InputsPlannerSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
)
_generate_srv_cpp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/LightSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
)
_generate_srv_cpp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/OverSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
)
_generate_srv_cpp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/SensorSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
)

### Generating Module File
_generate_module_cpp(svg_ros
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(svg_ros_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(svg_ros_generate_messages svg_ros_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/MVServ.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_cpp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/ReadySrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_cpp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/InputsSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_cpp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/InputsPlannerSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_cpp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/LightSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_cpp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/OverSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_cpp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/SensorSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_cpp _svg_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(svg_ros_gencpp)
add_dependencies(svg_ros_gencpp svg_ros_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS svg_ros_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/MVServ.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
)
_generate_srv_lisp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/ReadySrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
)
_generate_srv_lisp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/InputsSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
)
_generate_srv_lisp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/InputsPlannerSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
)
_generate_srv_lisp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/LightSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
)
_generate_srv_lisp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/OverSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
)
_generate_srv_lisp(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/SensorSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
)

### Generating Module File
_generate_module_lisp(svg_ros
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(svg_ros_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(svg_ros_generate_messages svg_ros_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/MVServ.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_lisp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/ReadySrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_lisp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/InputsSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_lisp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/InputsPlannerSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_lisp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/LightSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_lisp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/OverSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_lisp _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/SensorSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_lisp _svg_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(svg_ros_genlisp)
add_dependencies(svg_ros_genlisp svg_ros_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS svg_ros_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/MVServ.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
)
_generate_srv_py(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/ReadySrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
)
_generate_srv_py(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/InputsSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
)
_generate_srv_py(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/InputsPlannerSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
)
_generate_srv_py(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/LightSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
)
_generate_srv_py(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/OverSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
)
_generate_srv_py(svg_ros
  "/home/savage/catkin_ws/src/svg_ros/srv/SensorSrv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
)

### Generating Module File
_generate_module_py(svg_ros
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(svg_ros_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(svg_ros_generate_messages svg_ros_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/MVServ.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_py _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/ReadySrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_py _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/InputsSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_py _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/InputsPlannerSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_py _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/LightSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_py _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/OverSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_py _svg_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/savage/catkin_ws/src/svg_ros/srv/SensorSrv.srv" NAME_WE)
add_dependencies(svg_ros_generate_messages_py _svg_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(svg_ros_genpy)
add_dependencies(svg_ros_genpy svg_ros_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS svg_ros_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svg_ros
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(svg_ros_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svg_ros
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(svg_ros_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svg_ros
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(svg_ros_generate_messages_py std_msgs_generate_messages_py)
