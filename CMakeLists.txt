cmake_minimum_required(VERSION 3.30)
project(employee_db)

set(CMAKE_CXX_STANDARD 20)

add_executable(employee_db main.cpp
        Employee.cppm
        Employee.cpp
)
