project(common_lib LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME}
    PUBLIC
        include/tomato/SmartPointer.h
        SharedCounter.cc
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
)

enable_testing()
include(../cmake_conf/gtest.cmake)
tomato_lib_test("test/SmartPointerTest.cc")