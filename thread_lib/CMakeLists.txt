project(thread_lib)

add_library(${PROJECT_NAME} SHARED)

set(LIB_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIB_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(${PROJECT_NAME}
    PRIVATE
        ${LIB_HEADER_DIR}/tomato/Condition.h
        ${LIB_SOURCE_DIR}/Condition.cpp
        ${LIB_HEADER_DIR}/tomato/MutexLockGuard.h
        ${LIB_SOURCE_DIR}/MutexLockGuard.cpp
        ${LIB_HEADER_DIR}/tomato/MutexLock.h
        ${LIB_SOURCE_DIR}/MutexLock.cpp
        ${LIB_HEADER_DIR}/tomato/CountDownLatch.h
        ${LIB_SOURCE_DIR}/CountDownLatch.cpp
        ${LIB_HEADER_DIR}/tomato/Singleton.h
)


target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${LIB_HEADER_DIR}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        gmock
        gtest
)

function(tomato_lib_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)

    add_executable("${test_target_name}")
    target_sources("${test_target_name}"
        PRIVATE
            "${test_file}"
    )
    target_link_libraries("${test_target_name}" ${PROJECT_NAME} gmock gtest)

    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
endfunction(tomato_lib_test)

tomato_lib_test("include/tomato/Singleton_test.cpp")