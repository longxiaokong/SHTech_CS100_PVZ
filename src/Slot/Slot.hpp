//
//  Slot.hpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#ifndef Slot_hpp
#define Slot_hpp

#include "GameObject.hpp"
#include "utils.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class Slot : public GameObject, public std::enable_shared_from_this<Slot> {
public:
  using std::enable_shared_from_this<Slot>::shared_from_this;
  Slot(pGameWorld pWorld, int slot, ImageID img);
  virtual ~Slot() = default;
  static int slotToPixelX(int slot) {return SEED_SLOT_FIRST_COL_CENTER + (slot - 1) * (SEED_SLOT_WIDTH + SEED_SLOT_SPACING);}
private:
  
};

#endif /* Slot_hpp */
