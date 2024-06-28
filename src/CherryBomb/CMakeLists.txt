cmake_minimum_required(VERSION 3.16)

add_library(
  CherryBomb
  STATIC
  CherryBomb.hpp
  CherryBomb.cpp
)

target_link_libraries(
  CherryBomb
  Plant
  Framework
)

target_include_directories(
  CherryBomb
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Plant/
  ${CMAKE_SOURCE_DIR}/src/CherryBomb/
)
