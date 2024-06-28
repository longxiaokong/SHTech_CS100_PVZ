cmake_minimum_required(VERSION 3.16)

add_library(
  Pow
  STATIC
  Pow.hpp
  Pow.cpp
)

target_link_libraries(
  Pow
  Projectile
  Framework
)

target_include_directories(
  Pow
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Projectile/
  ${CMAKE_SOURCE_DIR}/src/Pow/
)
