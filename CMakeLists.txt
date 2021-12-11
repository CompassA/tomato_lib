cmake_minimum_required(VERSION 3.19.2)
project(tomato_lib)

set(CMAKE_CXX_FLAGS 
        "${CAMKE_CXX_FLAGS}   \
        -std=c++11            \
        -g                    \
        -Wall                 \
        -Wextra               \
        -Wconversion          \
        -Wno-unused-parameter \
        -Wold-style-cast      \
        -Woverloaded-virtual  \
        -Wpointer-arith       \
        -Wshadow              \
        -Wwrite-strings       \
        -march=native         \
        -rdynamic             \
        -pthread")

add_subdirectory(test)
add_subdirectory(exe)
add_subdirectory(static_lib)
add_subdirectory(thread_lib)
add_subdirectory(third_party/googletest)