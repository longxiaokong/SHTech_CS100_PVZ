//
//  Projectile.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include "MovingObject.hpp"
#include "utils.hpp"

class Projectile : public MovingObject,
                   public std::enable_shared_from_this<Projectile>
{
public:
  using std::enable_shared_from_this<Projectile>::shared_from_this;
  Projectile (pGameWorld pWorld, int initial_x, int initial_y,
              ProjectileType type);
  virtual void OnClick () override {};
  virtual bool
  isDead () override
  {
    return m_health < 0;
  }
  virtual void
  addHealth (int delta) override
  {
    m_health += delta;
  }
  virtual int
  getHarm () override
  {
    return -ProjectileHarm[static_cast<std::size_t> (m_type)];
  }
  virtual void
  UpdateArbitrary () override
  {
  }
  virtual bool
  is_projectile () override
  {
    return true;
  }
  virtual ~Projectile () = default;

private:
  int m_health;
  ProjectileType m_type;
};
#endif /* Projectile_hpp */
