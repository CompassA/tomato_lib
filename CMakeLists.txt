cmake_minimum_required(VERSION 3.16)
project(tomato_lib)

set(CMAKE_CXX_STANDARD 11)

add_library(tomato_lib SHARED MutexLock.cpp MutexLock.h MutexLockGuard.cpp MutexLockGuard.h Condition.cpp Condition.h CountDownLatch.cpp CountDownLatch.h Singleton.h)