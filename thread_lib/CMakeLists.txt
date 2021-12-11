project(thread_lib)

add_library(${PROJECT_NAME} SHARED)

set(LIB_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_sources(${PROJECT_NAME}
    PRIVATE
        ${LIB_SOURCE_DIR}/Condition.cpp
        ${LIB_SOURCE_DIR}/MutexLockGuard.cpp
        ${LIB_SOURCE_DIR}/MutexLock.cpp
        ${LIB_SOURCE_DIR}/CountDownLatch.cpp
)


target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)