//
//  Wallnut.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "Wallnut.hpp"
#include "Plant.hpp"
#include "utils.hpp"

Wallnut::Wallnut (pGameWorld pWorld, int grid_x, int grid_y)
    : Plant (pWorld, PlantType::PLANT_WALLNUT, grid_x, grid_y),
      m_cracked (false)
{
}

void
Wallnut::Update ()
{
  if (m_cracked
      && 3 * getHealth ()
             > plantHealth[static_cast<size_t> (PlantType::PLANT_WALLNUT)])
    {
      m_cracked = false;
      ChangeImage (IMGID_WALLNUT);
    }
  if (!m_cracked
      && 3 * getHealth ()
             <= plantHealth[static_cast<size_t> (PlantType::PLANT_WALLNUT)])
    {
      m_cracked = true;
      ChangeImage (IMGID_WALLNUT_CRACKED);
    }
  //  addHealth(-20);
}
