//
//  Repeater.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef Repeater_hpp
#define Repeater_hpp

#include "Plant.hpp"
#include "Timer.hpp"
class Repeater : public Plant
{
public:
  Repeater (pGameWorld pWorld, int x, int y);
  virtual ~Repeater () = default;
  virtual void Update () override;
  virtual bool
  is_plant () override
  {
    return true;
  }

private:
  Timer m_shoot_timer, m_bullet_timer;
};

#endif /* Repeater_hpp */
