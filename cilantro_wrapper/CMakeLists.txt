cmake_minimum_required(VERSION 2.8)
project(cilantro_wrapper_project)

include_directories (.)

#ADD_LIBRARY( cilantro_wrp STATIC cvx_polytope_spatial.cpp cilantro_wrapper.cpp )

file (GLOB TASOURCES  "*.cpp")

add_library( spatial_cilantro ${TASOURCES})

target_include_directories (spatial_cilantro PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


#install(TARGETS spatial_cilantro DESTINATION ${CMAKE_SOURCE_DIR}/..)
