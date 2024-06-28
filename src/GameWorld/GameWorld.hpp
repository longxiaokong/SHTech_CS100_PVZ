#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"

#include "utils.hpp"

class Background;
class Plant;
class Seed;
class CoolDownMask;
class TextBase;
class GameObject;
class NaturalSun;
class ProducedSun;
class Timer;

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;
  
  bool TryHoldSeed(const Seed*);
  
  void ClickAtPlant(Plant *);
  
  void ShovelPlant(Plant *);
  
  bool PlantAt(Plant*);
  
  bool HasCoolDown(std::shared_ptr<GameObject>) const;
  
  unsigned getSunCnt() const {return m_sunCnt;}
  
  void setSunCnt(unsigned new_cnt);
  
  void addSunCnt(int delta);
  
  void spawnNaturalSun(int worth=SUN_VALUE_DEFAULT);
                         
  void spawnProducedSunAt(int x, int y, int worth=SUN_VALUE_DEFAULT);
  
  void spawnZombieAt(int row_y, int x=WINDOW_WIDTH - 1, ZombieType type=ZombieType::ZOMBIE_REGULAR);
  
  void PlantAtPos(int x, int y, PlantType type);
  
  bool GetHoldingShovel() {return m_holding_shovel;}
  
  void SetHoldingShovel() {
    m_holdingPlant = PlantType::PLANT_NONE;
    m_holdingFromSlot = -1;
    m_currentCoolDownMask = nullptr;
    m_holding_shovel = true;
  }
  
  bool areColliding(std::shared_ptr<GameObject>, std::shared_ptr<GameObject>);
  
  bool anyZombieOnRow(int row){return m_row_zombie_cnt[row] > 0;}
  
  void UpdateZombieState();
  
private:
  std::list<std::shared_ptr<GameObject> > m_object_list;
  std::shared_ptr<Background> m_background = nullptr;
  PlantType m_holdingPlant = PlantType::PLANT_NONE;
  std::size_t m_holdingFromSlot = -1;
  unsigned m_sunCnt = 100;
  std::shared_ptr<TextBase> m_sunText = nullptr;
  std::shared_ptr<CoolDownMask> m_currentCoolDownMask;
  std::shared_ptr<Timer> m_natural_sun_timer;
  std::list<std::list<std::shared_ptr<GameObject> >::iterator> m_zombie_it_list;
  int m_row_zombie_cnt[6] = {0};
  bool m_holding_shovel;
};

#endif // !GAMEWORLD_HPP__
