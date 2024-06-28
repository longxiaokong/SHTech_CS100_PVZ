cmake_minimum_required(VERSION 3.16)

add_library(
  CoolDownMask
  STATIC
  CoolDownMask.hpp
  CoolDownMask.cpp
)

target_link_libraries(
  CoolDownMask
  Slot
  Framework
)

target_include_directories(
    CoolDownMask
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Slot/
  ${CMAKE_SOURCE_DIR}/src/CoolDownMask/
)
