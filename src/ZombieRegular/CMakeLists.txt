cmake_minimum_required(VERSION 3.16)

add_library(
  ZombieRegular
  STATIC
  ZombieRegular.hpp
  ZombieRegular.cpp
)

target_link_libraries(
  ZombieRegular
  Zombie
  Framework
)

target_include_directories(
  ZombieRegular
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Zombie/
  ${CMAKE_SOURCE_DIR}/src/ZombieRegular/
)

