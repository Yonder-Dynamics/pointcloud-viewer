cmake_minimum_required(VERSION 2.8.11)
project(rosply)

find_package(catkin REQUIRED COMPONENTS
	roscpp
)

include_directories(${catkin_INCLUDE_DIRS})
include_directories(${roscpp_INCLUDE_DIRS})

find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_definitions(
	-Wall
	#-std=c++11
	#-std=c++0x
	-O0
	-g
)

set(ALL_LIBS
  ${CATKIN_LIBRARIES}
	${roscpp_LIBRARIES}
	${PCL_LIBRARIES}
)

add_executable(rosply src/main.cpp)
target_link_libraries(rosply ${ALL_LIBS})
