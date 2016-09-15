cmake_minimum_required(VERSION 3.6)
project(Mesh_Memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp base64.cpp base64.h xReference.cpp xReference.h Servidor/server.h Servidor/server.cpp Cliente/client.cpp Cliente/client.h)
add_executable(Mesh_Memory ${SOURCE_FILES})

set(TREADS_PREFERED_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Mesh_Memory Threads::Threads)