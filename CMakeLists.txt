cmake_minimum_required(VERSION 3.10.2)
PROJECT(myShell)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./)
INCLUDE_DIRECTORIES(./src)
add_subdirectory(./src/library)
add_executable(myshell
 ./src/main.cpp
)
target_link_libraries(myshell mylib)