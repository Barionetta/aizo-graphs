cmake_minimum_required(VERSION 3.5.0)
project(aizo-graphs VERSION 0.1.0)

add_executable(aizo_2_263953_program)
target_sources(aizo_2_263953_program PRIVATE "main.cpp")
target_include_directories(aizo_2_263953_program PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(aizo_2_263953_program -static)
add_subdirectory("algorithms")
add_subdirectory("core")
add_subdirectory("graphs")
add_subdirectory("structures")