FILE(GLOB SRCFILES *.cpp *.hpp *.c *.h)
FILE(GLOB UIFILES ${SOURCE_DATA_DIR}/ui/*)

add_executable(
    ${PROJECT_NAME}
    ${GENERATED_SOURCE_DIR}/resources.c
    ${SRCFILES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    PkgConfig::GTKMM
    PkgConfig::libadwaitamm
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ${GENERATED_INCLUDE_DIR}
    ${INCLUDE_DIR}
)

compile_resources(
    ${GENERATED_SOURCE_DIR}/resources.c
    ${UIFILES}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
