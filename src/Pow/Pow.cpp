//
//  Pow.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "Pow.hpp"
#include "Projectile.hpp"
#include "utils.hpp"

Pow::Pow(pGameWorld pWorld, int initial_x, int initial_y): Projectile(pWorld, initial_x, initial_y, ProjectileType::PROJ_POW), m_lifetime_timer(3){
  m_lifetime_timer.StartTimer();
}
bool Pow::isDead(){
  return m_lifetime_timer.isTimingEnded();
}
void Pow::UpdateArbitrary(){
  m_lifetime_timer.Update();
}
