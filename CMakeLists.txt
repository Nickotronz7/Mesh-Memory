cmake_minimum_required(VERSION 3.6)
project(Mesh_Memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Application/main.cpp Application/base64.cpp Application/base64.h "Mesh Mem Manager/server.h" "Mesh Mem Manager/server.cpp" "Mesh Mem Client/client.cpp" "Mesh Mem Client/client.h" "API/Mesh_Mem_API.cpp" "API/Mesh_Mem_API.h" API/xReference.h)
add_executable(Mesh_Memory ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(Mesh_Memory ${GTK3_LIBRARIES})

set(TREADS_PREFERED_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Mesh_Memory Threads::Threads)