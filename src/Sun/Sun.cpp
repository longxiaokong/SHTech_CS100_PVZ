//
//  Sun.cpp
//  Background
//
//  Created by lxk on 2024/6/28.
//

#include "Sun.hpp"
#include "Timer.hpp"
#include "GameWorld.hpp"
#include "utils.hpp"

Sun::Sun(pGameWorld pWorld, int initial_x, int initial_y, int worth, int velocity_x, int velocity_y, int acceleration_x, int acceleration_y, int lifetime): MovingObject(pWorld, IMGID_SUN, initial_x, initial_y, LAYER_SUN, SUN_WIDTH, SUN_HEIGHT, ANIMID_IDLE_ANIM, velocity_x, velocity_y, acceleration_x, acceleration_y), m_lifetime_timer(lifetime), m_is_dead(false), m_sun_value(worth){}

void Sun::OnClick(){
  if (m_is_dead)
    return;
  m_is_dead = true;
  getGameWorld() -> addSunCnt(m_sun_value);
}

void Sun::UpdateArbitrary(){
  UpdateMoveStatus();
  if(!m_lifetime_timer.isTimingEnded())
    m_lifetime_timer.Update();
  if(m_lifetime_timer.isTimingEnded())
    m_is_dead = true;
}
