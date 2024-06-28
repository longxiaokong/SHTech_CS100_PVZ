//
//  Repeater.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "Repeater.hpp"
#include "GameWorld.hpp"
#include "Plant.hpp"
#include "Timer.hpp"
#include "utils.hpp"

Repeater::Repeater(pGameWorld pWorld, int x, int y): Plant(pWorld, PlantType::PLANT_REPEATER, x, y), m_shoot_timer(SHOOTER_INTERVAL), m_bullet_timer(0){m_shoot_timer.StartTimer();}

void Repeater::Update(){
  if(isDead())
    return;
  if(!m_shoot_timer.isTimingEnded())
    m_shoot_timer.Update();
  if(!m_bullet_timer.isTimingEnded())
    m_bullet_timer.Update();
  if(m_bullet_timer.isTiming() && m_bullet_timer.isTimingEnded())
  {
    m_bullet_timer.StopTimer();
    getGameWorld() -> spawnProjectileAt(GetX() + 30, GetY() + 20, ProjectileType::PROJ_PEA);
  }
  if(m_shoot_timer.isTimingEnded() && getGameWorld() -> anyZombieOnRow(GetGridY()))
  {
    m_shoot_timer.SetTimer(SHOOTER_INTERVAL);
    m_bullet_timer.SetTimer(BULLET_INTERVAL);
    m_bullet_timer.StartTimer();
    getGameWorld() -> spawnProjectileAt(GetX() + 30, GetY() + 20, ProjectileType::PROJ_PEA);
  }
}
