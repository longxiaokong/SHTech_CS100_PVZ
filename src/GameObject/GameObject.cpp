#include "GameObject.hpp"
GameObject::GameObject(pGameWorld pWorld,ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
  : ObjectBase(imageID, x, y, layer, width, height, animID), m_pWorld(pWorld) {}


// Your everything begins from here.
