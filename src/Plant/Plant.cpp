//
//  Plant.cpp
//  Plant
//
//  Created by lxk on 2024/6/27.
//

#include "Plant.hpp"
#include "utils.hpp"

Plant::Plant(PlantType type, int x, int y)
: GameObject(plantImageID[static_cast<std::size_t>(type)], Plant::gridToPixelX(x), Plant::gridToPixelY(y), LAYER_UI, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM), m_type(type), m_health(0) {}
