#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this;
  GameObject(pGameWorld pWorld,ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);
  virtual ~GameObject() = default;
  virtual bool isDead() = 0;
  virtual int getHarm() {return 0;}
  virtual void addHealth(int){}
  pGameWorld getGameWorld(){return m_pWorld;}
  int GetGridX() {return (GetX() - FIRST_COL_CENTER) / LAWN_GRID_WIDTH + 1;}
  int GetGridY() {return (GetY() - FIRST_ROW_CENTER) / LAWN_GRID_HEIGHT + 1;}
  virtual bool is_plant(){return false;}
  virtual bool is_zombie(){return false;}
  virtual bool is_projectile(){return false;}
private:
  pGameWorld m_pWorld;
};


#endif // !GAMEOBJECT_HPP__
