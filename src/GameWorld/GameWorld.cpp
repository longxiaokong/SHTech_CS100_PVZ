#include "GameWorld.hpp"
#include "Background.hpp"
#include "Plant.hpp"
#include "Seed.hpp"
#include <memory>

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
  
  m_background = std::make_shared<Background>(shared_from_this());
  objectList.insert(objectList.end(), m_background);
  
  for(int i = 1; i <= GAME_COLS; i ++)
    for(int j = 1; j <= GAME_ROWS; j ++)
      objectList.insert(objectList.end(), std::make_shared<Plant>(shared_from_this(), PlantType::PLANT_NONE, i, j));
  
  objectList.insert(objectList.end(), m_background);
  
  objectList.insert(objectList.end(), std::make_shared<Seed>(shared_from_this(), 1, PlantType::PLANT_SUNFLOWER));
  objectList.insert(objectList.end(), std::make_shared<Seed>(shared_from_this(), 2, PlantType::PLANT_PEASHOOTER));
  objectList.insert(objectList.end(), std::make_shared<Seed>(shared_from_this(), 3, PlantType::PLANT_WALLNUT));
  objectList.insert(objectList.end(), std::make_shared<Seed>(shared_from_this(), 4, PlantType::PLANT_CHERRY_BOMB));
  objectList.insert(objectList.end(), std::make_shared<Seed>(shared_from_this(), 5, PlantType::PLANT_REPEATER));
  
  m_sunCnt = 100;
  m_sunText = std::make_shared<TextBase>(SUN_CNT_COL_CENTER, SUN_CNT_ROW_CENTER, std::to_string(m_sunCnt));
}

LevelStatus GameWorld::Update() {
  // YOUR CODE HERE
  for(const auto& gameObject: objectList)
    gameObject -> Update();
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  objectList.clear();
  m_background.reset();
}

bool GameWorld::TryHoldSeed(const Seed* pSeed){
  if(m_sunCnt < pSeed -> getCost())
    return false;
  m_holdingPlant = pSeed -> getPlantType();
  m_holdingFromSlot = pSeed -> getSlotNum();
  return true;
}

bool GameWorld::PlantAt(Plant *plant){
  if(m_holdingPlant == PlantType::PLANT_NONE)
    return true;
  if(m_sunCnt < seedCost[static_cast<size_t>(m_holdingPlant)])
    return false;
  m_sunCnt -= seedCost[static_cast<size_t>(m_holdingPlant)];
  m_sunText -> SetText(std::to_string(m_sunCnt));
  plant -> switchTo(m_holdingPlant);
  m_holdingPlant = PlantType::PLANT_NONE;
  return true;
}
