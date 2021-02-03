cmake_minimum_required(VERSION 3.18)
project(lokimon)

set(CMAKE_CXX_STANDARD 17)

set(fmt_ROOT "" CACHE PATH "fmt root directory. Leave blank for system default.")
find_package(fmt 7 REQUIRED CONFIG)
if (NOT fmt_FOUND)
    message(FATAL_ERROR "fmt not found; You should set fmt_ROOT to the fmt lib path")
endif ()

add_subdirectory("${loki_src_root}" "${CMAKE_CURRENT_BINARY_DIR}/loki")

add_executable(lokimon src/main.cpp)
add_subdirectory(src/core)
add_subdirectory(src/models)
add_subdirectory(src/screens)

target_include_directories(lokimon PRIVATE src)
target_link_libraries(lokimon fmt::fmt loki::input loki::gui loki::screens loki::sprites loki::tiles loki::window)
