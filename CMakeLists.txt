cmake_minimum_required(VERSION 3.0.2)
project(robot_info)

find_package(catkin REQUIRED COMPONENTS
  robotinfo_msgs
  roscpp
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
   INCLUDE_DIRS include
   LIBRARIES robot_info_class agv_robot_info_class
#  CATKIN_DEPENDS robotinfo_msgs roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(robot_info_class
   src/robot_info_class.cpp
)

add_library(agv_robot_info_class
   src/agv_robot_info_class.cpp
   src/hydraulic_system_monitor.cpp
)
target_link_libraries(agv_robot_info_class robot_info_class)

add_executable(robot_info_node src/robot_info_main.cpp)
add_dependencies(robot_info_node ${robot_info_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(robot_info_node ${catkin_LIBRARIES} robot_info_class)

add_executable(agv_robot_info_node src/agv_robot_info_node.cpp)
add_dependencies(agv_robot_info_node ${agv_robot_info_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(agv_robot_info_node ${catkin_LIBRARIES} agv_robot_info_class)

#############
## Install ##
#############
install(TARGETS 
			robot_info_class
			agv_robot_info_class
			robot_info_node
			agv_robot_info_node
   		ARCHIVE 
   			DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   		LIBRARY 
   			DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   		RUNTIME
			DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
