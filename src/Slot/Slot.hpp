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
  Slot(pGameWorld pWorld, unsigned slot, PlantType type, LayerID layer, ImageID img);
  virtual ~Slot() = default;
  static int slotToPixelX(unsigned slot) {return SEED_SLOT_FIRST_COL_CENTER + (slot - 1) * (SEED_SLOT_WIDTH + SEED_SLOT_SPACING);}
  PlantType getPlantType()const{return m_type;}
  unsigned getSlotNum()const{return m_slot_num;}
protected:
  unsigned m_slot_num;
  PlantType m_type;
};

#endif /* Slot_hpp */
