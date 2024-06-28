//
//  Projectile.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "Projectile.hpp"
#include "MovingObject.hpp"

Projectile::Projectile(pGameWorld pWorld, int initial_x, int initial_y, ProjectileType type): MovingObject(pWorld, ProjectileImgID[static_cast<std::size_t>(type)], initial_x, initial_y, LAYER_PROJECTILES, ProjectileWidth[static_cast<std::size_t>(type)], ProjectileHeight[static_cast<std::size_t>(type)], ANIMID_NO_ANIMATION, ProjectileVelocityX[static_cast<std::size_t>(type)], ProjectileVelocityY[static_cast<std::size_t>(type)], ProjectileAccecerationX[static_cast<std::size_t>(type)], ProjectileAccecerationY[static_cast<std::size_t>(type)]), m_health(0), m_type(type){}
