cmake_minimum_required(VERSION 3.5)
project(lcm_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp )
add_executable(lcm_talker ${SOURCE_FILES} obset_t.hpp obs_t.hpp point2.hpp)
add_executable(lcm_talker2 talk2.cpp exlcm/example_t.hpp)
add_executable(lcm_listener cpp/listener.cpp point2.hpp obs_t.hpp obset_t.hpp)
add_executable(lcm_listener2 listener2.cpp exlcm/example_t.hpp)
target_link_libraries(lcm_talker -llcm )
target_link_libraries(lcm_talker2 -llcm )
target_link_libraries(lcm_listener -llcm )
target_link_libraries(lcm_listener2 -llcm )