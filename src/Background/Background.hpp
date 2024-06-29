//
//  Background.hpp
//  Background
//
//  Created by lxk on 2024/6/27.
//

#ifndef Background_hpp
#define Background_hpp
#include "GameObject.hpp"
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class Background : public GameObject
{
public:
  Background (pGameWorld pWorld);
  virtual ~Background () = default;
  virtual void
  Update () override
  {
  }
  virtual void
  OnClick () override
  {
  }
  virtual bool
  isDead () override
  {
    return false;
  }

private:
};

#endif /* Background_hpp */
