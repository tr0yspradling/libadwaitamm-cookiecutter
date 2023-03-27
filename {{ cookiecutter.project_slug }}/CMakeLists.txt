cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)

project({{ cookiecutter.pkg_name }} VERSION 1.0)

# variables
set(APPLICATION_ID "{{ cookiecutter.pkg_name }}")
string(REPLACE "." "/" APPLICATION_PREFIX "/${APPLICATION_ID}/")
set(GENERATED_FILES_DIR ${PROJECT_BINARY_DIR}/generated)
set(DATA_DIR ${GENERATED_FILES_DIR}/data)
set(DEPENDENCIES_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/dependencies)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(GENERATED_INCLUDE_DIR ${GENERATED_FILES_DIR}/include)
set(SOURCES_DIR ${GENERATED_FILES_DIR}/src)

# include ./cmake scripts
list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(GlibUtils)
include(GlibCompileSchemas)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)
pkg_check_modules(libadwaitamm REQUIRED IMPORTED_TARGET libadwaitamm-1)

configure_file(cmake/projectdefinitions.h.in ${GENERATED_INCLUDE_DIR}/projectdefinitions.h)

add_subdirectory(data)
add_subdirectory(dependencies)
add_subdirectory(include)
add_subdirectory(src)

FILE(GLOB SRCFILES src/*.cpp src/*.c)
FILE(GLOB UIFILES ${DATA_DIR}/ui/*)

add_executable(
    ${PROJECT_NAME}
    ${DATA_DIR}/resources.c
    ${SRCFILES}
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ${DEPENDENCIES_INCLUDE_DIR}
    ${GENERATED_INCLUDE_DIR}
    ${INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    PkgConfig::GTKMM
    PkgConfig::libadwaitamm
)

# from include(GlibUtils)
compile_resources(
    ${DATA_DIR}/resources.c
    ${UIFILES}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES cmake/uninstall.sh DESTINATION ${PROJECT_BINARY_DIR} PERMISSIONS OWNER_EXECUTE OWNER_READ OWNER_WRITE)
