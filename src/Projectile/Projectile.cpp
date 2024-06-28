//
//  Projectile.cpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#include "Projectile.hpp"

Projectile::Projectile(pGameWorld pWorld, ImageID img, int initial_x, int initial_y, LayerID layer, int width, int height, AnimID animID, int velocity_x=0, int velocity_y=0, int acceleration_x=0, int acceleration_y=0): GameObject(pWorld, img, initial_x, initial_y, layer, width, height, animID), m_velocity_x(velocity_x), m_velocity_y(velocity_y),m_acceleration_x(acceleration_x),m_acceleration_y(acceleration_y){}

void Projectile::Update(){
  MoveTo(GetX() + m_velocity_x, GetY() + m_velocity_y);
  m_velocity_x += m_acceleration_x;
  m_velocity_y += m_acceleration_y;
  UpdateArbitrary();
}
