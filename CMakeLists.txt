cmake_minimum_required(VERSION 3.12)

project(vector-random-generator)

set (SOURCE main.cpp)

include_directories(scr)

add_subdirectory(scr/vector_random_generator)

target_link_libraries(main)



