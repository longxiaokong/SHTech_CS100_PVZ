//
//  CoolDownMask.cpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#include "CoolDownMask.hpp"
#include "Slot.hpp"
CoolDownMask::CoolDownMask (pGameWorld pWorld, int slot, PlantType type)
    : Slot (pWorld, slot, type, LAYER_COOLDOWN_MASK, IMGID_COOLDOWN_MASK),
      m_timer (seedCoolDown[static_cast<std::size_t> (type)])
{
  m_timer.StartTimer ();
}
