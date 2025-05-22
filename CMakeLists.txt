cmake_minimum_required(VERSION 3.10)
project(main)

add_executable(main main.cpp src/ToDoList.cpp)

target_include_directories(main PRIVATE includes)

# File resposive to compile all program.