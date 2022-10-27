cmake_minimum_required(VERSION 3.12)
project(vector-random-generator)

set(SOURCE main.cpp)

set(HEADER vector_random_generator.hpp)

add_executable(main ${SOURCE})
## Collect headers
#file(GLOB_RECURSE HEADERS ${PROJECT_INCLUDE_DIR}/scr/vector_random_generator/*.hpp)




