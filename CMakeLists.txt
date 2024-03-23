cmake_minimum_required(VERSION 3.10)
project(TinyThreadPool)
set(${PROJECT_NAME} ThreadPool)

set(SOURCE_DIR .)
set(EXECUTABLE_OUTPUT_PATH ${SOURCE_DIR}/bin)

set(SOURCE_LIST
    maintest.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_LIST})