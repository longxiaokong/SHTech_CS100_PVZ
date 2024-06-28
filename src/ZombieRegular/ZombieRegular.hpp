//
//  ZombieRegular.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef ZombieRegular_hpp
#define ZombieRegular_hpp

#include "Zombie.hpp"
#include "utils.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class ZombieRegular : public Zombie, public std::enable_shared_from_this<ZombieRegular> {
public:
  using std::enable_shared_from_this<ZombieRegular>::shared_from_this;
  ZombieRegular(pGameWorld, int, int initial_X=WINDOW_WIDTH - 1, int velocity_X=ZOMBIE_VELOCITY_REGULAR);
  
  virtual ~ZombieRegular() = default;
private:
};

#endif /* ZombieRegular_hpp */
