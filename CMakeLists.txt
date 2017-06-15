cmake_minimum_required(VERSION 2.8.12)
project("fastrtps_ros")

find_package(catkin REQUIRED COMPONENTS 
  tf
  geometry_msgs
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES Velocities_fast_lib
)

set(fastcdr_DIR "$ENV{FASTRTPSHOME}/build/install/lib/fastcdr/cmake")
set(fastrtps_DIR "$ENV{FASTRTPSHOME}/build/install/lib/fastrtps/cmake")

find_package(fastrtps REQUIRED)
find_package(fastcdr REQUIRED)

# Set C++11
include(CheckCXXCompilerFlag)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG OR
        CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    check_cxx_compiler_flag(--std=c++11 SUPPORTS_CXX11)
    if(SUPPORTS_CXX11)
        add_compile_options(--std=c++11)
    else()
        message(FATAL_ERROR "Compiler doesn't support C++11")
    endif()
endif()


add_library(Velocities_fast_lib
  src/Velocities.cxx
  src/VelocitiesPubSubTypes.cxx
  src/VelocitiesPublisher.cxx
  src/VelocitiesSubscriber.cxx
)

target_link_libraries(Velocities_fast_lib
  fastrtps
  fastcdr
  ${CMAKE_DL_LIBS}
  ${catkin_LIBRARIES}
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  lib
  include
)

add_executable(dds_bridge 
  src/VelocitiesPubSubMain.cxx
)

target_link_libraries(dds_bridge 
  fastrtps 
  fastcdr
  Velocities_fast_lib
  ${catkin_LIBRARIES}
)

add_executable(odom_sub
  src/odomtest_sub.cpp
)

target_link_libraries(odom_sub
  ${catkin_LIBRARIES}
)

add_executable(odom_pub
  src/odomtest_pub.cpp
)

target_link_libraries(odom_pub
  ${catkin_LIBRARIES}
)
