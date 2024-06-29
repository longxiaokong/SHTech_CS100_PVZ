//
//  BucketHeadZombie.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef BucketHeadZombie_hpp
#define BucketHeadZombie_hpp

#include "Zombie.hpp"
#include "utils.hpp"

class BucketHeadZombie : public Zombie,
                         public std::enable_shared_from_this<BucketHeadZombie>
{
public:
  using std::enable_shared_from_this<BucketHeadZombie>::shared_from_this;
  BucketHeadZombie (pGameWorld, int, int initial_X = WINDOW_WIDTH - 1,
                    int velocity_X = ZOMBIE_VELOCITY_REGULAR);
  virtual void UpdateZombieState () override;
  virtual ~BucketHeadZombie () = default;

private:
  bool m_with_bucket;
};

#endif /* BucketHeadZombie_hpp */
