cmake_minimum_required(VERSION 3.16)

add_library(
  Sun
  STATIC
  Sun.hpp
  Sun.cpp
  NaturalSun.hpp
  NaturalSun.cpp
  ProducedSun.hpp
  ProducedSun.cpp
)

target_link_libraries(
  Sun
  Projectile
  Framework
  GameWorld
)

target_include_directories(
  Sun
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Projectile/
  ${CMAKE_SOURCE_DIR}/src/Sun/
)

