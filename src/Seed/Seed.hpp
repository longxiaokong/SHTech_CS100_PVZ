//
//  Seed.hpp
//  Seed
//
//  Created by lxk on 2024/6/27.
//

#ifndef Seed_hpp
#define Seed_hpp
#include "GameObject.hpp"
#include "utils.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

const ImageID seedImageID[static_cast<int>(PlantType::PLANT_TYPE_CNT)] = {
  IMGID_PEA,
  IMGID_SEED_SUNFLOWER,
  IMGID_SEED_PEASHOOTER,
  IMGID_SEED_WALLNUT,
  IMGID_SEED_CHERRY_BOMB,
  IMGID_SEED_REPEATER
};

class Seed : public GameObject, public std::enable_shared_from_this<Seed> {
public:
  using std::enable_shared_from_this<Seed>::shared_from_this;
  Seed(int slot, PlantType type);
  virtual ~Seed() = default;
  virtual void Update() override{};
  virtual void OnClick() override{};
  static int slotToPixelX(int slot) {return SEED_SLOT_FIRST_COL_CENTER + (slot - 1) * SEED_SLOT_WIDTH;}
private:
  
};

#endif /* Background_hpp */
