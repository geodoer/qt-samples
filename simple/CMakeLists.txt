cmake_minimum_required(VERSION 2.8.12)
project(qtsamples-simple)

#conan会把Find*.cmake文件放置build目录下
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

file(GLOB cmakelists_files "${CMAKE_CURRENT_SOURCE_DIR}/*/CMakeLists.txt")
foreach(file ${cmakelists_files})
    get_filename_component(subdir ${file} DIRECTORY)

    message(STATUS "[add_subdirectory] ${subdir}")
    add_subdirectory(${subdir})
endforeach()

# 打开工程目录
set_property(GLOBAL PROPERTY USE_FOLDERS ON)