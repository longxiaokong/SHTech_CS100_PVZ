cmake_minimum_required(VERSION 3.16)

add_library(
  Wallnut
  STATIC
  Wallnut.hpp
  Wallnut.cpp
)

target_link_libraries(
  Wallnut
  Plant
  Framework
)

target_include_directories(
  Wallnut
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Plant/
  ${CMAKE_SOURCE_DIR}/src/Wallnut/
)
