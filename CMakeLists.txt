cmake_minimum_required(VERSION 2.8.3)
project(image_outline_plugin)



#==============================================================================
# packages
#==============================================================================

find_package(GAZEBO REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

find_package(OpenCV REQUIRED)



#==============================================================================
# includes
#==============================================================================

include_directories(
    include
    ${GAZEBO_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)


link_directories(
    ${GAZEBO_LIBRARY_DIRS}
    ${OpenCV_LIBRARY_DIRS}
)



#==============================================================================
# libraries
#==============================================================================

add_library(image_outline_plugin SHARED
    src/image_outline_plugin.cpp
)



#==============================================================================
# library link
#==============================================================================

target_link_libraries(image_outline_plugin
    ${GAZEBO_LIBRARIES}
    ${OpenCV_LIBRARIES}
    CameraPlugin
)
