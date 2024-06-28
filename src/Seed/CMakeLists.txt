cmake_minimum_required(VERSION 3.16)

add_library(
  Seed
  STATIC
  Seed.hpp
  Seed.cpp
)

target_link_libraries(
  Seed
  Slot
  Framework
)

target_include_directories(
  Seed
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Slot/
  ${CMAKE_SOURCE_DIR}/src/Seed/
)
