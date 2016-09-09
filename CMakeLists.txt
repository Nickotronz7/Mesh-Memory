cmake_minimum_required(VERSION 3.6)
project(Mesh_Memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Manager.cpp Manager.h base64.cpp base64.h)
add_executable(Mesh_Memory ${SOURCE_FILES})

set(TREADS_PREFERED_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Mesh_Memory Threads::Threads)