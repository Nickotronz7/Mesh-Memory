cmake_minimum_required(VERSION 3.6)
project(Mesh_Memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Headers/json.h Servidor/socketServer.cpp Servidor/socketServer.h Cliente/socketClient.cpp Cliente/socketClient.h)
add_executable(Mesh_Memory ${SOURCE_FILES} Headers/json.h Cliente/socketClient.cpp Cliente/socketClient.h)

set(TREADS_PREFERED_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Mesh_Memory Threads::Threads)