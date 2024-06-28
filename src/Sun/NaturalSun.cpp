//
//  NaturalSun.cpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#include "NaturalSun.hpp"
#include "Sun.hpp"

NaturalSun::NaturalSun(pGameWorld pworld, int initial_x, int desc_y, int worth): Sun(pworld, initial_x, WINDOW_HEIGHT - 1, worth, 0, NATURAL_SUN_VELOCITY_Y), m_desc_y(desc_y){}

void NaturalSun::UpdateMoveStatus(){
  if(!isLifetimeTiming() && GetY() <= m_desc_y)
  {
    SetVelocityY(0);
    StartLifetimeTimer();
  }
}
