//
//  BucketHeadZombie.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "BucketHeadZombie.hpp"
#include "Zombie.hpp"
#include "utils.hpp"

BucketHeadZombie::BucketHeadZombie(pGameWorld pWorld, int row_y, int initial_x, int velocity_X): Zombie(pWorld, ZombieType::ZOMBIE_BUCKET, row_y), m_with_bucket(true){}

void BucketHeadZombie::UpdateZombieState(){
  if(m_with_bucket && getHealth() <= ZombieHealth[static_cast<std::size_t>(ZombieType::ZOMBIE_REGULAR)])
  {
    ChangeImage(IMGID_REGULAR_ZOMBIE);
    m_with_bucket = false;
  }
}
