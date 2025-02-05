cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "PvZ")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

########### MAGIC THAT YOU DO NOT NEED TO MODIFY #############
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

IF(APPLE)
    add_definitions(-DGL_SILENCE_DEPRECATION)
ENDIF()

add_subdirectory(
  "${CMAKE_CURRENT_LIST_DIR}/third_party/SOIL/"
  "${CMAKE_CURRENT_BINARY_DIR}/SOIL"
  EXCLUDE_FROM_ALL
)

IF (APPLE)
ELSE()
  add_subdirectory(
    "${CMAKE_CURRENT_LIST_DIR}/third_party/freeglut/"
    "${CMAKE_CURRENT_BINARY_DIR}/freeglut"
    EXCLUDE_FROM_ALL
  )
  set(FREEGLUT_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/freeglut/include")
ENDIF()

##############################################################


#↓↓↓↓↓↓↓↓↓↓↓ ADD YOUR SUBDIRECTORIES HERE ↓↓↓↓↓↓↓↓↓↓↓↓
add_subdirectory(src/Framework/)
add_subdirectory(src/GameObject/)
add_subdirectory(src/GameWorld/)
add_subdirectory(src/Background/)
add_subdirectory(src/Plant/)
add_subdirectory(src/CoolDownMask/)
add_subdirectory(src/Slot/)
add_subdirectory(src/Seed/)
add_subdirectory(src/Sun/)
add_subdirectory(src/MovingObject/)
add_subdirectory(src/Sunflower/)
add_subdirectory(src/Wallnut/)
add_subdirectory(src/Shovel/)
add_subdirectory(src/Zombie/)
add_subdirectory(src/RegularZombie/)
add_subdirectory(src/Projectile/)
add_subdirectory(src/Pea/)
add_subdirectory(src/Pow/)
add_subdirectory(src/Shooter/)
add_subdirectory(src/CherryBomb/)
add_subdirectory(src/BucketHeadZombie/)
#↑↑↑↑↑↑↑↑↑↑↑ ADD YOUR SUBDIRECTORIES HERE ↑↑↑↑↑↑↑↑↑↑↑↑↑

add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  src/utils.hpp
)

target_link_libraries(
  ${PROJECT_NAME}
  Framework
  GameWorld
)

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC 
  src/
  src/Framework/
  src/GameWorld/
)
