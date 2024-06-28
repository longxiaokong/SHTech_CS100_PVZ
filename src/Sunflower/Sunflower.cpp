//
//  Sunflower.cpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#include "Sunflower.hpp"
#include "GameWorld.hpp"
#include "utils.hpp"

Sunflower::Sunflower(pGameWorld pWorld, int x, int y)
: Plant(pWorld, PlantType::PLANT_SUNFLOWER, x, y), m_produce_timer(randInt(30, 600)){m_produce_timer.StartTimer();}

void Sunflower::UpdateArbitrary(){
  m_produce_timer.Update();
  if(m_produce_timer.isTimingEnded())
  {
    m_produce_timer.SetTimer(PRODUCE_SUN_INTERVAL);
    getGameWorld() -> spawnProducedSunAt(GetX(), GetY());
  }
};
