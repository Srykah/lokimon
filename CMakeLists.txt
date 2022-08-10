cmake_minimum_required(VERSION 3.18)
project(lokimon
  LANGUAGES CXX)

include(cmake/LoggingHelpers.cmake)

#find_package(loki CONFIG PATHS "${loki_DIR}" NO_DEFAULT_PATH REQUIRED)
add_subdirectory(${loki_DIR} loki)
lokimon_print_variables_with_pattern(loki)

add_executable(lokimon src/main.cpp)
add_subdirectory(src/core)
add_subdirectory(src/data)
add_subdirectory(src/gameplay)
add_subdirectory(src/misc)
add_subdirectory(src/screens)
target_link_libraries(lokimon PRIVATE loki::loki)
target_include_directories(lokimon PRIVATE src)
target_compile_features(lokimon INTERFACE cxx_std_20)
set_target_properties(lokimon PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
  )

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
