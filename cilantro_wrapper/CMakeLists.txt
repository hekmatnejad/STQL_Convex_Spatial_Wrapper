cmake_minimum_required(VERSION 2.8)
project(cilantro_wrapper_project)

ADD_LIBRARY( cilantro_wrp STATIC cvx_polytope_spatial.cpp cilantro_wrapper.cpp )


install(TARGETS cilantro_wrp DESTINATION ${CMAKE_SOURCE_DIR}/..)
