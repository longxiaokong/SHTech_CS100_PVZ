//
//  Pow.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef Pow_hpp
#define Pow_hpp

#include "Projectile.hpp"
#include "Timer.hpp"
class Pow : public Projectile
{
public:
  Pow (pGameWorld pWorld, int initial_x, int initial_y);
  virtual ~Pow () = default;
  virtual bool isDead () override;
  virtual void UpdateArbitrary () override;

private:
  Timer m_lifetime_timer;
};

#endif /* Pow_hpp */
