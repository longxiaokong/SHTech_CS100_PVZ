cmake_minimum_required(VERSION 3.16)

add_library(
  MovingObject
  STATIC
  MovingObject.hpp
  MovingObject.cpp
)

target_link_libraries(
  MovingObject
  GameObject
  Framework
)

target_include_directories(
  MovingObject
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/MovingObject/
)

