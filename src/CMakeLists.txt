# Create a simple LCM publisher for testing
find_package(
  catkin REQUIRED
  COMPONENTS
    roscpp
)

add_executable(example_send_lcm example_send_lcm.cpp)
target_link_libraries( example_send_lcm
    ${LCM_LIBRARY}
    ${catkin_LIBRARIES}
)
add_dependencies(example_send_lcm
    ${${PROJECT_NAME}_EXPORTED_TARGETS} 
    ${catkin_EXPORTED_TARGETS}
)

add_executable(lcm_sim_status_publisher lcm_sim_status_publisher.cpp)
target_link_libraries(lcm_sim_status_publisher
    ${LCM_LIBRARY}
    ${catkin_LIBRARIES}
)
add_dependencies(lcm_sim_status_publisher
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)

add_executable(ros_sim_command_publisher ros_sim_command_publisher.cpp)
target_link_libraries(ros_sim_command_publisher
    ${LCM_LIBRARY}
    ${catkin_LIBRARIES}
)
add_dependencies(ros_sim_command_publisher
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)

