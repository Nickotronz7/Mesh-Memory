cmake_minimum_required(VERSION 3.6)
project(Mesh_Memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Application/main.cpp Application/base64.cpp Application/base64.h "Mesh Mem Manager/server.h" "Mesh Mem Manager/server.cpp" "Mesh Mem Client/client.cpp" "Mesh Mem Client/client.h" "API/Mesh_Mem_API.cpp" "API/Mesh_Mem_API.h" API/xReference.h)
add_executable(Mesh_Memory ${SOURCE_FILES})

set(TREADS_PREFERED_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Mesh_Memory Threads::Threads)