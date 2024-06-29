//
//  Zombie.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef Zombie_hpp
#define Zombie_hpp

#include "MovingObject.hpp"
#include "utils.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class Zombie : public MovingObject, public std::enable_shared_from_this<Zombie> {
public:
  using std::enable_shared_from_this<Zombie>::shared_from_this;
  Zombie(pGameWorld, ZombieType type, int, int initial_X=WINDOW_WIDTH - 1, int velocity_X=ZOMBIE_VELOCITY_REGULAR);
  virtual void UpdateArbitrary() override;
  virtual void UpdateZombieState() = 0;
  virtual void OnClick() override{};
  
  bool getIsEating()const{return m_is_eating;}
  void setIsEating(bool flag) {
    m_is_eating = flag;
  }
  
  int getOriginalVelocity()const{return m_original_velocity;}
  void setOriginalVelocity(int v) {m_original_velocity = v;}
  
  ZombieType getZombieType()const{return m_type;}
  void setZombieType(ZombieType type) {m_type = type;}
  
  int getHealth()const{return m_health;}
  void setHealth(int health){m_health = health;}
  void addHealth(int delta)override{m_health += delta;}
  
  bool isDead() override{return m_health <= 0;}
  
  int getHarm() override{return -ZOMBIE_HARM_REGULAR;}

  virtual ~Zombie() = default;
  virtual bool is_zombie()override{return true;};
  static int gridToPixelY(int y) {return FIRST_ROW_CENTER + (y - 1) * LAWN_GRID_HEIGHT;}
private:
  ZombieType m_type;
  bool m_is_eating;
  int m_health, m_original_velocity;
};

#endif /* Zombie_hpp */
