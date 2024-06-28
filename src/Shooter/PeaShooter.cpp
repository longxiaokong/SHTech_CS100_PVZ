//
//  PeaShooter.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "PeaShooter.hpp"
#include "GameWorld.hpp"
#include "Plant.hpp"
#include "Timer.hpp"
#include "utils.hpp"

PeaShooter::PeaShooter(pGameWorld pWorld, int x, int y): Plant(pWorld, PlantType::PLANT_PEASHOOTER, x, y), m_shoot_timer(SHOOTER_INTERVAL){m_shoot_timer.StartTimer();}

void PeaShooter::Update(){
  if(isDead())
    return;
  if(!m_shoot_timer.isTimingEnded())
    m_shoot_timer.Update();
  if(m_shoot_timer.isTimingEnded() && getGameWorld() -> anyZombieOnRow(GetGridY()))
  {
    m_shoot_timer.SetTimer(SHOOTER_INTERVAL);
    getGameWorld() -> spawnProjectileAt(GetX() + 30, GetY() + 20, ProjectileType::PROJ_PEA);
  }
}
