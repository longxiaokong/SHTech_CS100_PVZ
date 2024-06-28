//
//  Seed.hpp
//  Seed
//
//  Created by lxk on 2024/6/27.
//

#ifndef Seed_hpp
#define Seed_hpp
#include "Slot.hpp"
#include "utils.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class Seed : public Slot, public std::enable_shared_from_this<Seed> {
public:
  using std::enable_shared_from_this<Seed>::shared_from_this;
  Seed(pGameWorld pWorld, int slot, PlantType type);
  virtual ~Seed() = default;
  virtual void Update() override{};
  virtual void OnClick() override;
  static int slotToPixelX(int slot) {return SEED_SLOT_FIRST_COL_CENTER + (slot - 1) * (SEED_SLOT_WIDTH + SEED_SLOT_SPACING);}
  std::size_t getSlotNum()const{return m_slot_num;}
  unsigned getCost()const{return m_cost;}
  PlantType getPlantType()const{return m_type;}
private:
  std::size_t m_slot_num;
  PlantType m_type;
  unsigned m_cost;
};

#endif /* Background_hpp */
