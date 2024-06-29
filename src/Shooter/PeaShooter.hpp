//
//  PeaShooter.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef PeaShooter_hpp
#define PeaShooter_hpp

#include "Plant.hpp"
#include "Timer.hpp"
class PeaShooter : public Plant
{
public:
  PeaShooter (pGameWorld pWorld, int x, int y);
  virtual ~PeaShooter () = default;
  virtual void Update () override;
  virtual bool
  is_plant () override
  {
    return true;
  }

private:
  Timer m_shoot_timer;
};

#endif /* PeaShooter_hpp */
