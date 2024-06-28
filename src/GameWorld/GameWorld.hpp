#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"

#include "GameObject.hpp"

#include "TextBase.hpp"
#include "utils.hpp"

class Background;
class Plant;
class Seed;

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;
  
  bool TryHoldSeed(const Seed*);
  
  bool PlantAt(Plant*);

private: 
  std::list<std::shared_ptr<GameObject> > objectList;
  std::shared_ptr<Background> m_background = nullptr;
  PlantType m_holdingPlant = PlantType::PLANT_NONE;
  std::size_t m_holdingFromSlot = -1;
  unsigned m_sunCnt = 100;
  std::shared_ptr<TextBase> m_sunText = nullptr;
};

#endif // !GAMEWORLD_HPP__
