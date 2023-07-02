cmake_minimum_required(VERSION 3.0.0)
project(sdizo-graphs VERSION 0.1.0)

add_executable(main)
target_sources(main PRIVATE "main.cpp")
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR})
add_subdirectory("algorithms")
add_subdirectory("representations")
add_subdirectory("simulation")
