cmake_minimum_required(VERSION 2.8)
project(STQL_spatial_wrapper_project)
#set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_CXX_COMPILER "g++")

include_directories (cilantro_wrapper)
add_subdirectory (cilantro_wrapper)
set(CMAKE_MACOSX_RPATH ON)

add_executable(spatio main.cpp)

#add_library(cilantro_wrp STATIC IMPORTED)

#target_link_libraries(spatio ${CMAKE_SOURCE_DIR}/libcilantro_wrp.a libcilantro.so ) 
target_link_libraries (spatio LINK_PUBLIC TALIBRARY libcilantro.so)

#install(TARGETS spatio DESTINATION bin)



