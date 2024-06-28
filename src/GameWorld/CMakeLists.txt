cmake_minimum_required(VERSION 3.16)

add_library(
  GameWorld
  STATIC
  GameWorld.hpp
  GameWorld.cpp
)

target_link_libraries(
  GameWorld
  GameObject
  Background
  Plant
  Seed
  CoolDownMask
  Sun
  Sunflower
  Wallnut
  Shovel
  Zombie
  ZombieRegular
  Pea
  Shooter
  CherryBomb
)

target_include_directories(
  GameWorld
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/Background/
  ${CMAKE_SOURCE_DIR}/src/Plant/
  ${CMAKE_SOURCE_DIR}/src/CoolDownMask/
  ${CMAKE_SOURCE_DIR}/src/Seed/
  ${CMAKE_SOURCE_DIR}/src/Sun/
  ${CMAKE_SOURCE_DIR}/src/Sunflower/
  ${CMAKE_SOURCE_DIR}/src/Wallnut/
  ${CMAKE_SOURCE_DIR}/src/Shovel/
  ${CMAKE_SOURCE_DIR}/src/Zombie/
  ${CMAKE_SOURCE_DIR}/src/ZombieRegular/
  ${CMAKE_SOURCE_DIR}/src/Pea/
  ${CMAKE_SOURCE_DIR}/src/Shooter/
  ${CMAKE_SOURCE_DIR}/src/CherryBomb/
)
