//
//  CherryBomb.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef CherryBomb_hpp
#define CherryBomb_hpp

#include "Plant.hpp"
#include "Timer.hpp"
class CherryBomb : public Plant
{
public:
  CherryBomb (pGameWorld pWorld, int x, int y);
  virtual ~CherryBomb ();
  virtual void Update () override;
  virtual bool isDead () override;
  virtual bool
  is_plant () override
  {
    return true;
  }

private:
  Timer m_lifetime_timer;
};

#endif /* CherryBomb_hpp */
