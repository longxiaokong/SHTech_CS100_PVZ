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
class Plant : public GameObject, public std::enable_shared_from_this<Plant> {
public:
  using std::enable_shared_from_this<Plant>::shared_from_this;
  Plant(pGameWorld pWorld, PlantType type, int x, int y);
  virtual ~Plant() = default;
  virtual void UpdateArbitrary(){};
  virtual void Update() override;
  virtual void OnClick() override;
  virtual bool isDead() override {return m_type != PlantType::PLANT_NONE && m_health <= 0;}
  void switchTo(PlantType);
  unsigned getHealth() {return m_health;}
  void setHealth(unsigned new_health) {m_health = new_health;}
  void addHealth(unsigned delta) {m_health += delta;}
  PlantType getPlantType() {return m_type;}
  int GetGridX() {return (GetX() - FIRST_COL_CENTER) / LAWN_GRID_WIDTH + 1;}
  int GetGridY() {return (GetY() - FIRST_ROW_CENTER) / LAWN_GRID_HEIGHT + 1;}
  static int gridToPixelX(int x) {return FIRST_COL_CENTER + (x - 1) * LAWN_GRID_WIDTH;}
  static int gridToPixelY(int y) {return FIRST_ROW_CENTER + (y - 1) * LAWN_GRID_HEIGHT;}
private:
  PlantType m_type;
  unsigned m_health;
};

#endif /* Plant_hpp */
