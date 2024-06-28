#ifndef UTILS_HPP__
#define UTILS_HPP__

#include <random>
#include <string>

// This relative path on Mac OS is different from that on other OS, because the
// way Xcode organizes the project files is different from others.
// Change it if the program fails to load assets. You may also use an absolute
// path.
#ifdef __APPLE__
static const std::string ASSET_DIR = "../../assets/";
#else
static const std::string ASSET_DIR = "../assets/";
#endif // __APPLE__

// Returns a random integer within [min, max] (inclusive).
inline int randInt(int min, int max) {
  if (max < min)
    std::swap(max, min);
  static std::random_device rd;
  static std::mt19937 generator(rd());
  std::uniform_int_distribution<> distro(min, max);
  return distro(generator);
}

enum class LevelStatus { ONGOING, LOSING };

enum class KeyCode {
  NONE,
  ENTER, // Enter
  QUIT   // Esc
};

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int LAWN_GRID_WIDTH = 80;
const int LAWN_GRID_HEIGHT = 100;

const int FIRST_ROW_CENTER = 75;
const int FIRST_COL_CENTER = 75;
const int GAME_ROWS = 5;
const int GAME_COLS = 9;

const int SEED_SLOT_SPACING = 3;
const int SEED_SLOT_WIDTH = 50;
const int SEED_SLOT_HEIGHT = 70;
const int SEED_SLOT_ROW_CENTER = 555;
const int SEED_SLOT_FIRST_COL_CENTER = 125 + SEED_SLOT_SPACING;
const int MAX_SEED_SLOT_CNT = 5;

const int SHOVEL_X = 600;
const int SHOVEL_Y = WINDOW_HEIGHT - 40;
const int SHOVEL_WIDTH = 50;
const int SHOVEL_HEIGHT = 50;

const int SUN_CNT_ROW_CENTER = 520;
const int SUN_CNT_COL_CENTER = 60;

using ImageID = int;

const ImageID IMGID_NONE = -1;
const ImageID IMGID_BACKGROUND = 0;
const ImageID IMGID_SUN = 1;
const ImageID IMGID_SHOVEL = 2;
const ImageID IMGID_COOLDOWN_MASK = 3;
const ImageID IMGID_SUNFLOWER = 10;
const ImageID IMGID_PEASHOOTER = 11;
const ImageID IMGID_WALLNUT = 12;
const ImageID IMGID_CHERRY_BOMB = 13;
const ImageID IMGID_REPEATER = 14;
const ImageID IMGID_WALLNUT_CRACKED = 15;
const ImageID IMGID_SEED_SUNFLOWER = 20;
const ImageID IMGID_SEED_PEASHOOTER = 21;
const ImageID IMGID_SEED_WALLNUT = 22;
const ImageID IMGID_SEED_CHERRY_BOMB = 23;
const ImageID IMGID_SEED_REPEATER = 24;
const ImageID IMGID_REGULAR_ZOMBIE = 30;
const ImageID IMGID_BUCKET_HEAD_ZOMBIE = 31;
const ImageID IMGID_POLE_VAULTING_ZOMBIE = 32;
const ImageID IMGID_PEA = 40;
const ImageID IMGID_EXPLOSION = 41;
const ImageID IMGID_ZOMBIES_WON = 99;

using AnimID = int;

const AnimID ANIMID_NO_ANIMATION = -1;
const AnimID ANIMID_IDLE_ANIM = 0;
const AnimID ANIMID_WALK_ANIM = 1;
const AnimID ANIMID_EAT_ANIM = 2;
const AnimID ANIMID_RUN_ANIM = 3;
const AnimID ANIMID_JUMP_ANIM = 4;

const int MAX_LAYERS = 7;
using LayerID = int;

const LayerID LAYER_SUN = 0;
const LayerID LAYER_ZOMBIES = 1;
const LayerID LAYER_PROJECTILES = 2;
const LayerID LAYER_PLANTS = 3;
const LayerID LAYER_COOLDOWN_MASK = 4;
const LayerID LAYER_UI = 5;
const LayerID LAYER_BACKGROUND = 6;

const int MS_PER_FRAME = 33;

const int SUN_WIDTH = 80;
const int SUN_HEIGHT = 80;

enum class PlantType{
  PLANT_NONE,
  PLANT_SUNFLOWER,
  PLANT_PEASHOOTER,
  PLANT_WALLNUT,
  PLANT_CHERRY_BOMB,
  PLANT_REPEATER,
  PLANT_TYPE_CNT,
};

const ImageID seedImageID[static_cast<int>(PlantType::PLANT_TYPE_CNT)] = {
  IMGID_PEA,
  IMGID_SEED_SUNFLOWER,
  IMGID_SEED_PEASHOOTER,
  IMGID_SEED_WALLNUT,
  IMGID_SEED_CHERRY_BOMB,
  IMGID_SEED_REPEATER
};

const unsigned seedCost[static_cast<int>(PlantType::PLANT_TYPE_CNT)] = {
  0,
  50,
  100,
  50,
  150,
  200
};

const ImageID plantImageID[static_cast<int>(PlantType::PLANT_TYPE_CNT)] = {
  IMGID_SUN,
  IMGID_SUNFLOWER,
  IMGID_PEASHOOTER,
  IMGID_WALLNUT,
  IMGID_CHERRY_BOMB,
  IMGID_REPEATER
};

const int plantHealth[static_cast<int>(PlantType::PLANT_TYPE_CNT)] = {
  -1,
  300,
  300,
  4000,
  300,
  300
};

const int seedCoolDown[static_cast<int>(PlantType::PLANT_TYPE_CNT)] = {
  0,
  240,
  240,
  900,
  1200,
  240
};

const PlantType slotPlant[static_cast<int>(PlantType::PLANT_TYPE_CNT)] = {
  PlantType::PLANT_NONE,
  PlantType::PLANT_SUNFLOWER,
  PlantType::PLANT_PEASHOOTER,
  PlantType::PLANT_WALLNUT,
  PlantType::PLANT_CHERRY_BOMB,
  PlantType::PLANT_REPEATER
};

const int SUN_VALUE_DEFAULT = 25;
const int NATURAL_SUN_VELOCITY_Y = -2;
const int PRODUCED_SUN_VELOCITY_X = 1;
const int PRODUCED_SUN_VELOCITY_Y = 4;
const int PRODUCED_SUN_ACCELERATION_Y = -1;
const int NATUAL_SUN_DROP_INITIAL = 180;
const int NATUAL_SUN_DROP_INTERVAL = 300;
const int PRODUCE_SUN_INTERVAL = 600;

enum class ZombieType{
  ZOMBIE_REGULAR,
  ZOMBIE_BUCKET,
  ZOMBIE_PULT,
  ZOMBIE_TYPE_CNT
};

const int ZombieHealth[static_cast<std::size_t>(ZombieType::ZOMBIE_TYPE_CNT)] = {
  200,
  1300,
  340
};

const int ZombieImgID[static_cast<std::size_t>(ZombieType::ZOMBIE_TYPE_CNT)] = {
  IMGID_REGULAR_ZOMBIE,
  IMGID_BUCKET_HEAD_ZOMBIE,
  IMGID_POLE_VAULTING_ZOMBIE
};

const int ZOMBIE_VELOCITY_REGULAR = -1;
const int ZOMBIE_VELOCITY_RUNNING = -2;
const int ZOMBIE_WIDTH = 20;
const int ZOMBIE_HEIGHT = 80;
const int ZOMBIE_HARM_REGULAR = 3;

enum class ProjectileType{
  PROJ_PEA,
  PROJ_POW,
  PROJ_TYPE_CNT
};

const int ProjectileImgID[static_cast<std::size_t>(ProjectileType::PROJ_TYPE_CNT)] = {
  IMGID_PEA,
  IMGID_EXPLOSION
};

const int ProjectileHarm[static_cast<std::size_t>(ProjectileType::PROJ_TYPE_CNT)] = {
  20,
  1800,
};

const int ProjectileVelocityX[static_cast<std::size_t>(ProjectileType::PROJ_TYPE_CNT)] = {
  8,
  0,
};

const int ProjectileVelocityY[static_cast<std::size_t>(ProjectileType::PROJ_TYPE_CNT)] = {
  0,
  0,
};

const int ProjectileAccecerationX[static_cast<std::size_t>(ProjectileType::PROJ_TYPE_CNT)] = {
  0,
  0,
};

const int ProjectileAccecerationY[static_cast<std::size_t>(ProjectileType::PROJ_TYPE_CNT)] = {
  0,
  0,
};

const int ProjectileWidth[static_cast<std::size_t>(ProjectileType::PROJ_TYPE_CNT)] = {
  28,
  3 * LAWN_GRID_WIDTH,
};

const int ProjectileHeight[static_cast<std::size_t>(ProjectileType::PROJ_TYPE_CNT)] = {
  28,
  3 * LAWN_GRID_HEIGHT,
};

const int SHOOTER_INTERVAL = 30;
const int BULLET_INTERVAL = 5;

const int CHERRY_BOMB_LIFETIME = 15;

#endif // !UTILS_HPP__
