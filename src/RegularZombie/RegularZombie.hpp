//
//  RegularZombie.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef RegularZombie_hpp
#define RegularZombie_hpp

#include "Zombie.hpp"
#include "utils.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class RegularZombie : public Zombie, public std::enable_shared_from_this<RegularZombie> {
public:
  using std::enable_shared_from_this<RegularZombie>::shared_from_this;
  RegularZombie(pGameWorld, int, int initial_X=WINDOW_WIDTH - 1, int velocity_X=ZOMBIE_VELOCITY_REGULAR);
  virtual void UpdateZombieState()override{};
  virtual ~RegularZombie() = default;
private:
};

#endif /* RegularZombie_hpp */
