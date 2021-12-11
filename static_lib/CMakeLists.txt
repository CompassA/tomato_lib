project(sample_static_lib)

#创建静态库
add_library(${PROJECT_NAME} STATIC)
#静态库的实现文件
target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/tsample.cc
)

#为依赖这个静态库的代码文件添加搜索路径
target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)