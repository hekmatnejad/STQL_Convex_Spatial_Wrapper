cmake_minimum_required(VERSION 2.8)
project(app_project)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

add_executable(spatio main.cpp)

add_library(cilantro_wrp STATIC IMPORTED)

target_link_libraries(myapp ${CMAKE_SOURCE_DIR}/libcilantro_wrp.a libcilantro.so ) 

install(TARGETS spatio DESTINATION bin)
