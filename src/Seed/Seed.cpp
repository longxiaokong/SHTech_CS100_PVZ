//
//  Seed.cpp
//  Seed
//
//  Created by lxk on 2024/6/27.
//

#include "Seed.hpp"
#include "utils.hpp"
#include "GameWorld.hpp"

Seed::Seed(pGameWorld pWorld,int slot, PlantType type)
: Slot(pWorld, slot, type, LAYER_UI, seedImageID[static_cast<std::size_t>(type)]) {}

void Seed::OnClick() {
  getGameWorld() -> TryHoldSeed(this);
}
