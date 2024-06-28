//
//  CherryBomb.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "CherryBomb.hpp"
#include "Timer.hpp"
#include "GameWorld.hpp"

CherryBomb::CherryBomb(pGameWorld pWorld, int x, int y): Plant(pWorld, PlantType::PLANT_CHERRY_BOMB, x, y), m_lifetime_timer(15){m_lifetime_timer.StartTimer();}

void CherryBomb::Update(){
  m_lifetime_timer.Update();
}

bool CherryBomb::isDead(){
  return m_lifetime_timer.isTimingEnded();
}

CherryBomb::~CherryBomb(){
  getGameWorld() -> spawnProjectileAt(GetX(), GetY(), ProjectileType::PROJ_POW);
}
