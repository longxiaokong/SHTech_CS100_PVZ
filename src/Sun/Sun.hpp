//
//  Sun.hpp
//  Background
//
//  Created by lxk on 2024/6/28.
//

#ifndef Sun_hpp
#define Sun_hpp
#include "MovingObject.hpp"
#include "Timer.hpp"

class Sun : public MovingObject
{
public:
  Sun (pGameWorld pWorld, int initial_x, int initial_y,
       int worth = SUN_VALUE_DEFAULT, int velocity_x = 0, int velocity_y = 0,
       int acceleration_x = 0, int acceleration_y = 0, int lifetime = 300);
  virtual void OnClick () override;
  virtual bool
  isDead () override
  {
    return m_is_dead;
  }
  virtual void UpdateMoveStatus () = 0;
  virtual void UpdateArbitrary () override;
  void
  StartLifetimeTimer ()
  {
    m_lifetime_timer.StartTimer ();
  }
  bool
  isLifetimeTiming ()
  {
    return m_lifetime_timer.isTiming ();
  }
  virtual ~Sun () = default;

private:
  Timer m_lifetime_timer;
  bool m_is_dead;
  int m_sun_value;
};

#endif /* Sun_hpp */
