project(common_lib)

add_library(${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/SmartPointer.h
)

target_link_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
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

tomato_lib_test("include/SmartPointerTest.cc")