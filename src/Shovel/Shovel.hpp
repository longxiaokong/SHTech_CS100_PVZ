//
//  Shovel.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef Shovel_hpp
#define Shovel_hpp

#include "GameObject.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class Shovel : public GameObject
{
public:
  Shovel (pGameWorld pWorld);
  virtual ~Shovel () = default;
  virtual void
  Update () override
  {
  }
  virtual void OnClick () override;
  virtual bool
  isDead () override
  {
    return false;
  }

private:
};
#endif /* Shovel_hpp */
