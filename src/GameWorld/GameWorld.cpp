#include "GameWorld.hpp"
#include "Background.hpp"
#include "Plant.hpp"
#include "Seed.hpp"
#include <memory>

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
  
  background = std::make_shared<Background>();
  objectList.insert(objectList.end(), background);
  
  for(int i = 1; i <= GAME_COLS; i ++)
    for(int j = 1; j <= GAME_ROWS; j ++)
      objectList.insert(objectList.end(), std::make_shared<Plant>(PlantType::PLANT_NONE, i, j));
  
  objectList.insert(objectList.end(), std::make_shared<Seed>(1, PlantType::PLANT_SUNFLOWER));
  objectList.insert(objectList.end(), std::make_shared<Seed>(2, PlantType::PLANT_PEASHOOTER));
}

LevelStatus GameWorld::Update() {
  // YOUR CODE HERE
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  objectList.clear();
  background = nullptr;
}

