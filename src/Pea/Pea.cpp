//
//  Pea.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "Pea.hpp"
#include "Projectile.hpp"
#include "utils.hpp"

Pea::Pea(pGameWorld pWorld, int initial_x, int initial_y): Projectile(pWorld, initial_x, initial_y, ProjectileType::PROJ_PEA){}
