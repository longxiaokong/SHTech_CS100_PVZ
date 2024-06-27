//
//  Seed.cpp
//  Seed
//
//  Created by lxk on 2024/6/27.
//

#include "Seed.hpp"
#include "utils.hpp"

Seed::Seed(int slot, PlantType type)
: GameObject(seedImageID[static_cast<std::size_t>(type)], Seed::slotToPixelX(slot), SEED_SLOT_ROW_CENTER, LAYER_UI, SEED_SLOT_WIDTH, SEED_SLOT_HEIGHT, ANIMID_NO_ANIMATION) {}
