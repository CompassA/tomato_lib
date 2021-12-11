
set(EXE_TARGET_NAME "sample")

#添加输出名
add_executable(${EXE_TARGET_NAME})
#参与的文件
target_sources(${EXE_TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
)

#依赖静态库
target_link_libraries(${EXE_TARGET_NAME}
    PRIVATE
        sample_static_lib
        thread_lib
)