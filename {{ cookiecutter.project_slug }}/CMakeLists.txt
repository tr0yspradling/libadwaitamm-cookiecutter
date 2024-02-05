cmake_minimum_required(VERSION 3.2)
find_package(PkgConfig REQUIRED)

project({{ cookiecutter.pkg_name }} VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wnarrowing -Wold-style-cast -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wnull-dereference -Wunused -Woverloaded-virtual -Wformat=2 -Wconversion -Wsign-conversion -Wdouble-promotion -Wmisleading-indentation -Winfinite-recursion")

# C++23 features
# TODO: Fix building with LLVM libc++
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
#include_directories("/usr/include/c++/v1")

# variables
set(APPLICATION_ID "{{ cookiecutter.pkg_name }}")
string(REPLACE "." "/" APPLICATION_PREFIX "/${APPLICATION_ID}/")

set(SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${SOURCES_DIR}/include)

set(GENERATED_FILES_DIR ${PROJECT_BINARY_DIR}/generated)
set(GENERATED_DATA_DIR ${GENERATED_FILES_DIR}/data)
set(GENERATED_SOURCES_DIR ${GENERATED_FILES_DIR}/src)
set(GENERATED_INCLUDE_DIR ${GENERATED_SOURCES_DIR}/include)
set(GENERATED_PROJECT_DEFINITIONS_HEADER ${GENERATED_INCLUDE_DIR}/projectdefinitions.h)

configure_file(cmake/projectdefinitions.h.in ${GENERATED_PROJECT_DEFINITIONS_HEADER})

# include ./cmake scripts
list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(glib_utils)
include(glib_compile_schemas)
include(find_system_libs)

# ./dependencies/
set(DEPENDENCIES_DIR ${PROJECT_SOURCE_DIR}/dependencies)
set(DEPENDENCIES_INCLUDE_DIR ${DEPENDENCIES_DIR})
add_subdirectory(${DEPENDENCIES_DIR})

add_subdirectory(data)
add_subdirectory(src)
