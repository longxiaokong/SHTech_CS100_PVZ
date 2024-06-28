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
: Slot(pWorld, slot, seedImageID[static_cast<std::size_t>(type)]), m_slot_num(slot) ,m_type(type), m_cost(seedCost[static_cast<std::size_t>(type)]) {}

void Seed::OnClick() {
  getGameWorld() -> TryHoldSeed(this);
}
