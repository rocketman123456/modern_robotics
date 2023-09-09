cmake_minimum_required(VERSION 3.5)
project(ModernRobotics)

find_package(Eigen3 CONFIG REQUIRED)

include_directories(include)

add_library(modern_robotics SHARED src/modern_robotics.cpp include/modern_robotics.h)
target_link_libraries(modern_robotics PUBLIC Eigen3::Eigen)

add_executable(test main.cpp)
target_link_libraries(test PUBLIC modern_robotics)
