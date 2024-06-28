//
//  ProducedSun.cpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#include "ProducedSun.hpp"
#include "Timer.hpp"
#include "utils.hpp"

ProducedSun::ProducedSun(pGameWorld pWorld, int x, int y, int worth=SUN_VALUE_DEFAULT): Sun(pWorld, x, y, worth, randInt(0, 1) ? -PRODUCED_SUN_VELOCITY_X : PRODUCED_SUN_VELOCITY_X, PRODUCED_SUN_VELOCITY_Y, 0, PRODUCED_SUN_ACCELERATION_Y), m_movement_timer(12){m_movement_timer.StartTimer();}

void ProducedSun::UpdateMoveStatus(){
  if(!m_movement_timer.isTimingEnded())
    m_movement_timer.Update();
  else return;
  if(m_movement_timer.isTimingEnded())
  {
    SetVelocityX(0);
    SetVelocityY(0);
    SetAccelerationY(0);
    StartLifetimeTimer();
  }
}
