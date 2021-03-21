cmake_minimum_required(VERSION 3.16)
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

add_library(${PROJECT_NAME} SHARED
        src/MutexLock.cpp
        src/MutexLockGuard.cpp
        src/Condition.cpp
        src/CountDownLatch.cpp main.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        header/MutexLock.h
        header/MutexLockGuard.h
        header/Condition.h
        header/CountDownLatch.h
        header/Singleton.h)

add_executable(main main.cpp)

target_link_libraries(main
    PRIVATE
        ${PROJECT_NAME})