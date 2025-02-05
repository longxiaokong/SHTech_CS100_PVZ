//
//  ZombieRegular.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "RegularZombie.hpp"
#include "Zombie.hpp"
#include "utils.hpp"

RegularZombie::RegularZombie (pGameWorld pWorld, int row_y, int initial_x,
                              int velocity_X)
    : Zombie (pWorld, ZombieType::ZOMBIE_REGULAR, row_y)
{
}
