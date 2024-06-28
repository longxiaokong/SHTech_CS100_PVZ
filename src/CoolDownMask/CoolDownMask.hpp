//
//  CoolDownMask.hpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#ifndef CoolDownMask_hpp
#define CoolDownMask_hpp
#include "Slot.hpp"
#include "Timer.hpp"
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class CoolDownMask : public Slot, public std::enable_shared_from_this<CoolDownMask> {
public:
  using std::enable_shared_from_this<CoolDownMask>::shared_from_this;
  CoolDownMask(pGameWorld pWorld, int slot, PlantType type);
  virtual ~CoolDownMask() = default;
  virtual void Update() override{m_timer.Update();}
  virtual void OnClick() override{}
  virtual bool isDead() override{return m_timer.isTimingEnded();}
private:
  Timer m_timer;
};

#endif /* CoolDownMask_hpp */
