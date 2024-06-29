cmake_minimum_required(VERSION 3.16)

add_library(
  RegularZombie
  STATIC
  RegularZombie.hpp
  RegularZombie.cpp
)

target_link_libraries(
  RegularZombie
  Zombie
  Framework
)

target_include_directories(
  RegularZombie
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Zombie/
  ${CMAKE_SOURCE_DIR}/src/RegularZombie/
)

