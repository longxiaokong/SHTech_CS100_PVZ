//
//  Slot.cpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#include "Slot.hpp"
#include "utils.hpp"

Slot::Slot (pGameWorld pWorld, unsigned slot, PlantType type, LayerID layer,
            ImageID img)
    : GameObject (pWorld, img, Slot::slotToPixelX (slot), SEED_SLOT_ROW_CENTER,
                  layer, SEED_SLOT_WIDTH, SEED_SLOT_HEIGHT,
                  ANIMID_NO_ANIMATION),
      m_slot_num (slot), m_type (type)
{
}
