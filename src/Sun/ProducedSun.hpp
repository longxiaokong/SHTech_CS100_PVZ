//
//  ProducedSun.hpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#ifndef ProducedSun_hpp
#define ProducedSun_hpp

#include "Sun.hpp"
#include "Timer.hpp"

class ProducedSun : public Sun,
                    public std::enable_shared_from_this<ProducedSun>
{
public:
  using std::enable_shared_from_this<ProducedSun>::shared_from_this;
  ProducedSun (pGameWorld, int, int, int);
  virtual void UpdateMoveStatus () override;
  virtual ~ProducedSun () = default;

private:
  Timer m_movement_timer;
};

#endif /* ProducedSun_hpp */
