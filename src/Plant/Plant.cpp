//
//  Plant.cpp
//  Plant
//
//  Created by lxk on 2024/6/27.
//

#include "Plant.hpp"
#include "utils.hpp"
#include "GameWorld.hpp"

Plant::Plant(pGameWorld pWorld,PlantType type, int x, int y)
: GameObject(pWorld, plantImageID[static_cast<std::size_t>(type)], Plant::gridToPixelX(x), Plant::gridToPixelY(y), LAYER_UI, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM), m_type(type), m_health(plantHealth[static_cast<std::size_t>(type)]){}

void Plant::OnClick(){
  getGameWorld() -> PlantAt(this);
}

void Plant::Update(){
  if(m_type != PlantType::PLANT_NONE && m_health <= 0)
  {
    m_health = 0;
    m_type = PlantType::PLANT_NONE;
    ChangeImage(plantImageID[static_cast<std::size_t>(PlantType::PLANT_NONE)]);
  }
  UpdateArbitrary();
}

void Plant::switchTo(PlantType type)
{
  m_type = type;
  m_health = plantHealth[static_cast<std::size_t>(type)];
  ChangeImage(plantImageID[static_cast<std::size_t>(type)]);
}
