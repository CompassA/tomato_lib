project(common_lib LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/tomato/SmartPointer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/test.cc
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

enable_testing()
include(../cmake_conf/gtest.cmake)
tomato_lib_test("test/SmartPointerTest.cc")