cmake_minimum_required(VERSION 3.6)
project(Mesh_Memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Application/main.cpp Application/base64.cpp Application/base64.h
        "Mesh Mem Client/client.cpp" "Mesh Mem Client/client.h" "API/Mesh_Mem_API.cpp"
        API/xReference.h API/Mesh_Mem_API.h)
add_executable(Mesh_Memory ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

find_package(Doxygen)

if(DOXYGEN_FOUND)

    set(DOXYGEN_INPUT ${SOURCE_FILES})
    set(DOXYGEN_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    add_custom_command(
            OUTPUT ${DOXYGEN_OUTPUT}
            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
            COMMAND ${CMAKE_COMMAND} -E echo "Done."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            DEPENDS ${DOXYGEN_INPUT}
    )

    add_custom_target(apidoc ALL DEPENDS ${DOXYGEN_OUTPUT})

    add_custom_target(apidoc_forced
            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
            COMMAND ${CMAKE_COMMAND} -E echo "Done."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            )

endif(DOXYGEN_FOUND)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(Mesh_Memory ${GTK3_LIBRARIES})

target_link_libraries(Mesh_Memory uuid)

set(TREADS_PREFERED_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Mesh_Memory Threads::Threads)