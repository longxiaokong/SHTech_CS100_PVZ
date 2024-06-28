cmake_minimum_required(VERSION 3.16)

add_library(
  Slot
  STATIC
  Slot.hpp
  Slot.cpp
)

target_link_libraries(
  Slot
  GameObject
  Framework
)

target_include_directories(
  Slot
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/Slot/
)

