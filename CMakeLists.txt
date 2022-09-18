cmake_minimum_required(VERSION 3.23)
project(dll_example_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")

add_library(math SHARED src/math.cpp)
add_executable(dll_example_2 src/main.cpp)
add_executable(hello src/other.cpp)

target_link_libraries(dll_example_2 math)

