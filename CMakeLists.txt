cmake_minimum_required(VERSION 3.16)
project(tomato_lib)

set(CMAKE_CXX_STANDARD 11)

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