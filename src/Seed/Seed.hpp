//
//  Seed.hpp
//  Seed
//
//  Created by lxk on 2024/6/27.
//

#ifndef Seed_hpp
#define Seed_hpp
#include "Slot.hpp"
#include "utils.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class Seed : public Slot, public std::enable_shared_from_this<Seed>
{
public:
  using std::enable_shared_from_this<Seed>::shared_from_this;
  Seed (pGameWorld pWorld, int slot, PlantType type);
  virtual ~Seed () = default;
  virtual void Update () override {};
  virtual void OnClick () override;
  virtual bool
  isDead () override
  {
    return false;
  }
  unsigned
  getCost () const
  {
    return seedCost[static_cast<std::size_t> (m_type)];
  }

private:
};

#endif /* Background_hpp */
