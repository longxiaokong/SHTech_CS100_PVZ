cmake_minimum_required(VERSION 3.16)

add_library(
  BucketHeadZombie
  STATIC
  BucketHeadZombie.hpp
  BucketHeadZombie.cpp
)

target_link_libraries(
  BucketHeadZombie
  Zombie
  Framework
)

target_include_directories(
  BucketHeadZombie
  PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Zombie/
  ${CMAKE_SOURCE_DIR}/src/BucketHeadZombie/
)

