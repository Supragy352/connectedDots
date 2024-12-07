cmake_minimum_required(VERSION 3.2)
project(dots)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

set(SOURCES
    ./src/main.c
)

# set(HEADERS
#     ./src/animation/script.h
# )

add_executable(dots ${SOURCES} ${HEADERS})

target_link_libraries(dots raylib winmm gdi32 kernel32)

add_custom_target(build_and_run
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target dots
    COMMAND dots
    DEPENDS dots
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(run
    COMMAND dots
    DEPENDS dots
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)