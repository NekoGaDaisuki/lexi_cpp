cmake_minimum_required(VERSION 2.8.4)
project(lexi_cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_POSITION_INDEPENDENT_CODE 1)
set(CMAKE_INSTALL_RPATH "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_definitions(-std=c++14 -W -Wall -Wextra)
include_directories(include)
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

add_subdirectory(src)
