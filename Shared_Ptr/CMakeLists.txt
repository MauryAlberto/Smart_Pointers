cmake_minimum_required(VERSION 3.10)
project(Shared_Ptr_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shared_ptr_demo main.cpp)

if (MSVC)
    target_compile_options(shared_ptr_demo PRIVATE /W4 /permissive-)
else()
    target_compile_options(shared_ptr_demo PRIVATE -Wall -Wextra -pedantic)
endif()