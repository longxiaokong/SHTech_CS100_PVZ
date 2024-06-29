//
//  Shovel.cpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#include "Shovel.hpp"
#include "GameObject.hpp"
#include "GameWorld.hpp"

Shovel::Shovel (pGameWorld pWorld)
    : GameObject (pWorld, IMGID_SHOVEL, SHOVEL_X, SHOVEL_Y, LAYER_UI,
                  SHOVEL_WIDTH, SHOVEL_HEIGHT, ANIMID_NO_ANIMATION)
{
}

void
Shovel::OnClick ()
{
  getGameWorld ()->SetHoldingShovel ();
}
