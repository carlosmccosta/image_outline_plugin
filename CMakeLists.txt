cmake_minimum_required(VERSION 2.8.3)
project(image_outline_plugin)



#==============================================================================
# packages
#==============================================================================

find_package(GAZEBO REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

find_package(laser_projector_bridge REQUIRED COMPONENTS image_tracer vector_image_publisher)



#==============================================================================
# includes
#==============================================================================

include_directories(
    include
    ${GAZEBO_INCLUDE_DIRS}
    ${laser_projector_bridge_INCLUDE_DIRS}
)


link_directories(
    ${GAZEBO_LIBRARY_DIRS}
    ${laser_projector_bridge_LIBRARY_DIRS}
)

include(GNUInstallDirs)



#==============================================================================
# libraries
#==============================================================================

add_library(image_outline_plugin SHARED
    src/image_outline_plugin.cpp
)
LIST(APPEND ${PROJECT_NAME}-libraries image_outline_plugin)



#==============================================================================
# library link
#==============================================================================

target_link_libraries(image_outline_plugin
    ${GAZEBO_LIBRARIES}
    CameraPlugin
    ${laser_projector_bridge_LIBRARIES}
    image_tracer
    vector_image_publisher
)



#==================================================================================================
# install
#==================================================================================================

install(TARGETS ${${PROJECT_NAME}-libraries} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib EXPORT ${PROJECT_NAME}-config)
install(DIRECTORY include/${PROJECT_NAME}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME} FILES_MATCHING PATTERN "*.h")
install(EXPORT ${PROJECT_NAME}-config DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
