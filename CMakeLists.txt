cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(QuantumShooter)

set(SRC_FILES
    src/main.cpp

    src/app/app.cpp
    src/app/app.h
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)