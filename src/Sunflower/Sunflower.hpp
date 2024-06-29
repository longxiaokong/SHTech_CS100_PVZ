//
//  Sunflower.hpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#ifndef Sunflower_hpp
#define Sunflower_hpp

#include "Plant.hpp"
#include "Timer.hpp"

class Sunflower : public Plant
{
public:
  Sunflower (pGameWorld pWorld, int x, int y);
  virtual ~Sunflower () = default;
  virtual void Update () override;
  virtual bool
  is_plant () override
  {
    return true;
  }

private:
  Timer m_produce_timer;
};
#endif /* Sunflower_hpp */
