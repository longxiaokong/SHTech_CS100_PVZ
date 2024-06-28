cmake_minimum_required(VERSION 3.16)

add_library(
  Sunflower
  STATIC
  Sunflower.hpp
  Sunflower.cpp
)

target_link_libraries(
  Sunflower
  Plant
  Framework
)

target_include_directories(
  Sunflower
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Plant/
  ${CMAKE_SOURCE_DIR}/src/Sunflower/
)
