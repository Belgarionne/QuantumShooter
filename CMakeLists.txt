cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(QuantumShooter)

set(SRC_FILES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})