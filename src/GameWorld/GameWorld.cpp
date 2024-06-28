#include "GameWorld.hpp"
#include "Background.hpp"
#include "Plant.hpp"
#include "Seed.hpp"
#include "CoolDownMask.hpp"
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
  
  for(int i = 1; i <= MAX_SEED_SLOT_CNT; i ++)
    objectList.insert(objectList.end(), std::make_shared<Seed>(shared_from_this(), i, slotPlant[i]));
  
  m_currentCoolDownMask = nullptr;
  
  m_sunCnt = 100;
  m_sunText = std::make_shared<TextBase>(SUN_CNT_COL_CENTER, SUN_CNT_ROW_CENTER, std::to_string(m_sunCnt));
}

LevelStatus GameWorld::Update() {
  // YOUR CODE HERE
  for(const auto& gameObject: objectList)
    gameObject -> Update();
  
  for(auto it = objectList.begin(); it != objectList.end();)
  {
    if((*it) -> isDead())
    {
      std::cerr << "erased when ref count is " << (*it).use_count() << std::endl;
      it = objectList.erase(it);
    }
    else ++it;
  }
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  objectList.clear();
  m_background = nullptr;
  m_currentCoolDownMask = nullptr;
}

bool GameWorld::TryHoldSeed(const Seed* pSeed){
  if(m_sunCnt < pSeed -> getCost())
    return false;
  m_holdingPlant = pSeed -> getPlantType();
  m_holdingFromSlot = pSeed -> getSlotNum();
  m_currentCoolDownMask = std::make_shared<CoolDownMask>(shared_from_this(), m_holdingFromSlot, slotPlant[static_cast<std::size_t>(m_holdingPlant)]);
  return true;
}

bool GameWorld::PlantAt(Plant *plant){
  if(m_holdingPlant == PlantType::PLANT_NONE)
    return true;
  if(m_sunCnt < seedCost[static_cast<size_t>(m_holdingPlant)])
    return false;
  objectList.insert(objectList.end(), m_currentCoolDownMask);
  m_currentCoolDownMask = nullptr;
  m_sunCnt -= seedCost[static_cast<size_t>(m_holdingPlant)];
  m_sunText -> SetText(std::to_string(m_sunCnt));
  plant -> switchTo(m_holdingPlant);
  m_holdingPlant = PlantType::PLANT_NONE;
  return true;
}

bool GameWorld::HasCoolDown(std::shared_ptr<GameObject> pGameObject) const {
  return typeid(pGameObject) == typeid(std::shared_ptr<CoolDownMask>);
}
