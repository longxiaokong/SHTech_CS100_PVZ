#include "GameWorld.hpp"
#include "Background.hpp"
#include "Plant.hpp"
#include "Seed.hpp"
#include "CoolDownMask.hpp"
#include "Timer.hpp"
#include "utils.hpp"
#include "NaturalSun.hpp"
#include "ProducedSun.hpp"
#include "TextBase.hpp"
#include "Sunflower.hpp"
#include <memory>

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
  
  m_background = std::make_shared<Background>(shared_from_this());
  m_object_list.push_back(m_background);
  
  for(int i = 1; i <= GAME_COLS; i ++)
    for(int j = 1; j <= GAME_ROWS; j ++)
      m_object_list.push_back(std::make_shared<Plant>(shared_from_this(), PlantType::PLANT_NONE, i, j));
  
  m_object_list.push_back( m_background);
  
  for(int i = 1; i <= MAX_SEED_SLOT_CNT; i ++)
    m_object_list.push_back( std::make_shared<Seed>(shared_from_this(), i, slotPlant[i]));
  
  m_currentCoolDownMask = nullptr;
  
  m_sunCnt = 100;
  m_sunText = std::make_shared<TextBase>(SUN_CNT_COL_CENTER, SUN_CNT_ROW_CENTER, std::to_string(m_sunCnt));
  
  m_natural_sun_timer = std::make_shared<Timer>(NATUAL_SUN_DROP_INITIAL);
  m_natural_sun_timer -> StartTimer();
}

LevelStatus GameWorld::Update() {
  // Step 1: drop natual sun.
  m_natural_sun_timer -> Update();
  if(m_natural_sun_timer -> isTimingEnded())
  {
    spawnNaturalSun();
    m_natural_sun_timer -> SetTimer(NATUAL_SUN_DROP_INTERVAL);
  }
  
  for(const auto& gameObject: m_object_list)
    gameObject -> Update();
  
  for(auto it = m_object_list.begin(); it != m_object_list.end();)
  {
    if((*it) -> isDead())
    {
//      std::cerr << "erased when ref count is " << (*it).use_count() << std::endl;
      it = m_object_list.erase(it);
    }
    else ++it;
  }
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  //  Step 1: remove the sun producing timer.
  m_natural_sun_timer = nullptr;
  //  Step 2: remove all items from object list.
  m_object_list.clear();
  //  Step 3: reset current holding plant.
  m_currentCoolDownMask = nullptr;
  m_holdingPlant = PlantType::PLANT_NONE;
  m_holdingFromSlot = -1;
  //  Step 4: remove the background.
  m_background = nullptr;
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
  // wallnut healing: only work for wallnut, so direct judgement rather than some functions.
  if(plant -> getPlantType() != PlantType::PLANT_NONE &&
     !(plant -> getPlantType() == PlantType::PLANT_WALLNUT &&
       m_holdingPlant == PlantType::PLANT_WALLNUT))
    return false;
  if(m_sunCnt < seedCost[static_cast<size_t>(m_holdingPlant)])
    return false;
  m_object_list.push_back(m_currentCoolDownMask);
  m_currentCoolDownMask = nullptr;
  m_sunCnt -= seedCost[static_cast<size_t>(m_holdingPlant)];
  m_sunText -> SetText(std::to_string(m_sunCnt));
  int x = plant -> GetGridX(), y = plant -> GetGridY();
  m_object_list.remove_if([plant](std::shared_ptr<GameObject> &x){return x.get() == plant;});
  PlantAtPos(x, y, m_holdingPlant);
  m_holdingPlant = PlantType::PLANT_NONE;
  return true;
}

bool GameWorld::HasCoolDown(std::shared_ptr<GameObject> pGameObject) const {
  return typeid(pGameObject) == typeid(std::shared_ptr<CoolDownMask>);
}

void GameWorld::spawnNaturalSun(int worth){
  m_object_list.push_back(std::make_shared<NaturalSun>(shared_from_this(), randInt(FIRST_COL_CENTER, FIRST_COL_CENTER + (GAME_COLS - 1) * LAWN_GRID_WIDTH), randInt(FIRST_ROW_CENTER, FIRST_ROW_CENTER + (GAME_ROWS - 1) * LAWN_GRID_HEIGHT), worth));
}


void GameWorld::spawnProducedSunAt(int x, int y, int worth){
  m_object_list.push_back(std::make_shared<ProducedSun>(shared_from_this(), x, y, worth));
}

void GameWorld::setSunCnt(unsigned int new_cnt){
  m_sunCnt = new_cnt;
  m_sunText -> SetText(std::to_string(m_sunCnt));
}

void GameWorld::addSunCnt(int delta){
  m_sunCnt += delta;
  m_sunText -> SetText(std::to_string(m_sunCnt));
}

void GameWorld::PlantAtPos(int x, int y, PlantType type){
  switch (type) {
    case PlantType::PLANT_NONE:
      m_object_list.push_back(std::make_shared<Plant>(shared_from_this(), PlantType::PLANT_NONE, x, y));
    case PlantType::PLANT_SUNFLOWER:
      m_object_list.push_back(std::make_shared<Sunflower>(shared_from_this(), x, y));
      break;
      
    default:
      break;
  }
}
