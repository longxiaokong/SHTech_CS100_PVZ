cmake_minimum_required(VERSION 3.16)

add_library(
  Shooter
  STATIC
  Shooter.hpp
  Shooter.cpp
  PeaShooter.hpp
  PeaShooter.cpp
  Repeater.hpp
  Repeater.cpp
)

target_link_libraries(
  Shooter
  Plant
  Framework
)

target_include_directories(
  Shooter
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Plant/
  ${CMAKE_SOURCE_DIR}/src/Shooter/
)
