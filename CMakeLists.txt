cmake_minimum_required(VERSION 3.18)
project(lokimon
  LANGUAGES CXX)

if (loki_src_root)
  add_subdirectory("${loki_src_root}" "${CMAKE_CURRENT_BINARY_DIR}/loki")
else ()
  message(FATAL_ERROR "loki_src_root not found")
endif ()

add_executable(lokimon src/main.cpp)
set_property(TARGET lokimon PROPERTY CXX_STANDARD 17)
add_subdirectory(src/core)
add_subdirectory(src/models)
add_subdirectory(src/screens)
target_include_directories(lokimon PRIVATE src)
target_link_libraries(lokimon PRIVATE loki::all_libs)

#[[
include(CheckIPOSupported)
check_ipo_supported(RESULT lokimon_ipo_supported OUTPUT lokimon_ipo_error)
if(lokimon_ipo_supported)
	if(CMAKE_CXX_COMPILER_ID STREQUAL GNU)
		set(CMAKE_AR gcc-ar)
		set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> qcs <TARGET> <LINK_FLAGS> <OBJECTS>")
		set(CMAKE_CXX_ARCHIVE_FINISH true)
	endif()
	set_property(TARGET lokimon PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
	message(WARNING "IPO is not supported: ${lokimon_ipo_error}")
endif()
#]]
