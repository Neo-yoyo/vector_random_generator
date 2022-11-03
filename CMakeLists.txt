cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)

project(vector-random-generator)

set (SOURCE main.cpp)

include_directories(scr)

#add_executable(main ${SOURCE_EXE})

##### Includes section ####
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
#include(GNUInstallDirs)
##добавляем функцию FC (чтобы исходники другого проекта были доступны в моем проекте)
#include(FetchContent)

##### Settings section ####
#set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(scr/vector_random_generator)

target_link_libraries(main)



