//
//  MovingObject.hpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#ifndef MovingObject_hpp
#define MovingObject_hpp
#include "GameObject.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class MovingObject : public GameObject
{
public:
  MovingObject (pGameWorld, ImageID, int, int, LayerID, int, int, AnimID, int,
                int, int, int);
  virtual void Update () override;
  virtual void UpdateArbitrary () = 0;
  virtual ~MovingObject () = default;
  int
  GetVelocityX ()
  {
    return m_velocity_x;
  }
  int
  GetVelocityY ()
  {
    return m_velocity_y;
  }
  int
  GetAccelerationX ()
  {
    return m_acceleration_x;
  }
  int
  GetAccelerationY ()
  {
    return m_acceleration_y;
  }
  void
  SetVelocityX (int vx)
  {
    m_velocity_x = vx;
  }
  void
  SetVelocityY (int vy)
  {
    m_velocity_y = vy;
  }
  void
  SetAccelerationX (int ax)
  {
    m_acceleration_x = ax;
  }
  void
  SetAccelerationY (int ay)
  {
    m_acceleration_y = ay;
  }

private:
  int m_velocity_x, m_velocity_y;
  int m_acceleration_x, m_acceleration_y;
};

#endif /* MovingObject_hpp */
