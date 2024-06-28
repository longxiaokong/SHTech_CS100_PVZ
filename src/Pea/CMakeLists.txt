cmake_minimum_required(VERSION 3.16)

add_library(
  Pea
  STATIC
  Pea.hpp
  Pea.cpp
)

target_link_libraries(
  Pea
  Projectile
  Framework
)

target_include_directories(
  Pea
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Projectile/
  ${CMAKE_SOURCE_DIR}/src/Pea/
)
