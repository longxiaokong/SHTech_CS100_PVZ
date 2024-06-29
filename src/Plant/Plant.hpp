//
//  Plant.hpp
//  Plant
//
//  Created by lxk on 2024/6/27.
//

#ifndef Plant_hpp
#define Plant_hpp
#include "GameObject.hpp"
#include "utils.hpp"
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;
// Used to create empty grids. Strange, but a way to rest.
class Plant : public GameObject
{
public:
  Plant (pGameWorld pWorld, PlantType type, int x, int y);
  ~Plant ();
  virtual void Update () override {};
  virtual void OnClick () override;
  virtual bool
  isDead () override
  {
    return m_type != PlantType::PLANT_NONE && m_health <= 0;
  }
  [[deprecated (
      "A function only switching image. Planting now handled by GameWorld.")]]
  void switchTo (PlantType);
  int
  getHealth ()
  {
    return m_health;
  }
  void
  setHealth (int new_health)
  {
    m_health = new_health;
  }
  void
  addHealth (int delta) override
  {
    m_health += delta;
  }
  PlantType
  getPlantType ()
  {
    return m_type;
  }
  static int
  gridToPixelX (int x)
  {
    return FIRST_COL_CENTER + (x - 1) * LAWN_GRID_WIDTH;
  }
  static int
  gridToPixelY (int y)
  {
    return FIRST_ROW_CENTER + (y - 1) * LAWN_GRID_HEIGHT;
  }

private:
  PlantType m_type;
  int m_health;
};

#endif /* Plant_hpp */
