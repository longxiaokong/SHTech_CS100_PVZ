//
//  Background.cpp
//  Background
//
//  Created by lxk on 2024/6/27.
//

#include "Background.hpp"
#include "utils.hpp"

Background::Background()
  : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION) {}
