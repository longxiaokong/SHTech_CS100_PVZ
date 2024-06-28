//
//  Zombie.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "Zombie.hpp"
#include "MovingObject.hpp"

Zombie::Zombie(pGameWorld pWorld, ZombieType type, int row_y, int initial_x, int velocity_x): MovingObject(pWorld, ZombieImgID[static_cast<std::size_t>(type)], initial_x, gridToPixelY(row_y), LAYER_ZOMBIES, ZOMBIE_WIDTH, ZOMBIE_HEIGHT, ANIMID_WALK_ANIM, velocity_x, 0, 0, 0), m_type(type), m_is_eating(false), m_health(ZombieHealth[static_cast<std::size_t>(type)]), m_original_velocity(velocity_x){}

void Zombie::UpdateArbitrary(){
  if(m_is_eating) SetVelocityX(0);
  else SetVelocityX(m_original_velocity);
}
