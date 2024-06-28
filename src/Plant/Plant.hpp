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

class Plant : public GameObject, public std::enable_shared_from_this<Plant> {
public:
  using std::enable_shared_from_this<Plant>::shared_from_this;
  Plant(pGameWorld pWorld, PlantType type, int x, int y);
  virtual ~Plant() = default;
  virtual void Update() override{
    if(m_type != PlantType::PLANT_NONE && m_health <= 0)
    {
      m_health = 0;
      m_type = PlantType::PLANT_NONE;
      ChangeImage(plantImageID[static_cast<std::size_t>(PlantType::PLANT_NONE)]);
    }
  }
  virtual void OnClick() override;
  void switchTo(PlantType);
  static int gridToPixelX(int x) {return FIRST_COL_CENTER + (x - 1) * LAWN_GRID_WIDTH;}
  static int gridToPixelY(int y) {return FIRST_ROW_CENTER + (y - 1) * LAWN_GRID_HEIGHT;}
private:
  PlantType m_type;
  unsigned m_health;
};

#endif /* Plant_hpp */
