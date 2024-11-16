# 设置最低 CMake 版本要求
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS "-mwindows")

include_directories(./include)
link_directories(./lib)


# 设置项目名称
project(TangledWarfare)

# 设置 C++ 标准（例如，C++17）
set(CMAKE_CXX_STANDARD 17)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRCS_DIR)
# 添加源代码文件
add_executable(TangledWarfare ${SRCS_DIR})

target_link_libraries(TangledWarfare libglad.a libglfw3.a libglfw3dll.a)