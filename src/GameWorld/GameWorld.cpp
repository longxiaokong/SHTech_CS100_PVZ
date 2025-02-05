#include "GameWorld.hpp"
#include "Background.hpp"
#include "BucketHeadZombie.hpp"
#include "CherryBomb.hpp"
#include "CoolDownMask.hpp"
#include "NaturalSun.hpp"
#include "Pea.hpp"
#include "PeaShooter.hpp"
#include "Plant.hpp"
#include "Pow.hpp"
#include "ProducedSun.hpp"
#include "RegularZombie.hpp"
#include "Repeater.hpp"
#include "Seed.hpp"
#include "Shovel.hpp"
#include "Sunflower.hpp"
#include "TextBase.hpp"
#include "Timer.hpp"
#include "Wallnut.hpp"
#include "Zombie.hpp"
#include "utils.hpp"
#include <memory>

GameWorld::GameWorld () {}

GameWorld::~GameWorld () {}

void
GameWorld::Init ()
{
  // Step 1: create background.
  m_background = std::make_shared<Background> (shared_from_this ());
  m_object_list.push_back (m_background);

  // Step 2: create shovel.
  m_object_list.push_back (std::make_shared<Shovel> (shared_from_this ()));

  // Step 3: create empty grids.
  for (int j = 1; j <= GAME_ROWS; j++)
    {
      for (int i = 1; i <= GAME_COLS; i++)
        m_object_list.push_back (std::make_shared<Plant> (
            shared_from_this (), PlantType::PLANT_NONE, i, j));
      m_row_zombie_cnt[j] = 0;
    }

  // Step 4: create seed slots.
  for (int i = 1; i <= MAX_SEED_SLOT_CNT; i++)
    m_object_list.push_back (
        std::make_shared<Seed> (shared_from_this (), i, slotPlant[i]));

  // Step 5: init the CoolDownMask of the plant held by hand
  m_currentCoolDownMask = nullptr;

  // Step 6: init sun counter
  m_sunCnt = 5000;
  m_sunText = std::make_shared<TextBase> (
      SUN_CNT_COL_CENTER, SUN_CNT_ROW_CENTER, std::to_string (m_sunCnt));

  // Step 7: init sun generator
  m_natural_sun_timer = std::make_shared<Timer> (NATUAL_SUN_DROP_INITIAL);
  m_natural_sun_timer->StartTimer ();

  // Step 8: init wave counter
  m_wave = 0;
  m_wave_timer = std::make_shared<Timer> (INITIAL_WAVE);
  m_wave_timer->StartTimer ();
  m_waveText = nullptr;
}

LevelStatus
GameWorld::Update ()
{
  // Step 1: drop natual sun.
  m_natural_sun_timer->Update ();
  if (m_natural_sun_timer->isTimingEnded ())
    {
      spawnNaturalSun ();
      m_natural_sun_timer->SetTimer (NATUAL_SUN_DROP_INTERVAL);
    }
  // Step 2: generate wave if possible
  m_wave_timer->Update ();
  if ((m_wave && m_zombie_it_list.empty ()) || m_wave_timer->isTimingEnded ())
    {
      m_wave++;
      m_wave_timer->SetTimer (std::max (150, 600 - 20 * m_wave));
      int zombie_cnt = (15 + m_wave) / 10;
      for (int i = 1; i <= zombie_cnt; i++)
        {
          spawnZombieAt (
              randInt (1, 5), randInt (WINDOW_WIDTH - 40, WINDOW_WIDTH - 1),
              randInt (1, 3 * std::max (0, m_wave - 15) + P_REGULAR_ZOMBIE)
                      <= P_REGULAR_ZOMBIE
                  ? ZombieType::ZOMBIE_REGULAR
                  : ZombieType::ZOMBIE_BUCKET);
        }
    }

  // Step 3: update all objects.
  for (auto &gameObject : m_object_list)
    gameObject->Update ();

  // Step 4: update zombie collision states.
  UpdateZombieState ();

  // Step 5: remove all dead objects.
  for (auto it = m_object_list.begin (); it != m_object_list.end ();)
    {
      if ((*it)->isDead ())
        {
          //      std::cerr << "erased when ref count is " << (*it).use_count()
          //      << std::endl;
          if ((*it)->is_zombie ())
            {
              m_row_zombie_cnt[(*it)->GetGridY ()]--;
              m_zombie_it_list.remove (it);
            }
          it = m_object_list.erase (it);
        }
      else
        ++it;
    }

  //  Step 6: detect if losing.
  for (auto &zombie_it : m_zombie_it_list)
    {
      if ((*zombie_it)->GetX () < 0)
        {
          m_waveText = std::make_shared<TextBase> (
              WAVE_TEXT_X, WAVE_TEXT_Y, std::to_string (m_wave - 1), 1, 1, 1);
          return LevelStatus::LOSING;
        }
    }
  return LevelStatus::ONGOING;
}

void
GameWorld::CleanUp ()
{
  //  Step 1: remove the sun producing timer.
  m_natural_sun_timer = nullptr;
  //  Step 2: remove all items from object list.
  m_object_list.clear ();
  m_object_list.clear (); // twice because when plants are deconstructed, they
                          // would automatically push in an empty grid.
  //  Step 3: reset current holding plant.
  m_currentCoolDownMask = nullptr;
  m_holdingPlant = PlantType::PLANT_NONE;
  m_holdingFromSlot = -1;
  //  Step 4: clear the zombie iterator list.
  m_zombie_it_list.clear ();
  //  Step 5: remove the background.
  m_background = nullptr;
  //  Step 6: clear up the timer.
  m_wave_timer = nullptr;
  //  Step 7: reset the wave text.
  m_waveText = nullptr;
}

bool
GameWorld::TryHoldSeed (const Seed *pSeed)
{
  if (m_sunCnt < pSeed->getCost ())
    return false;
  m_holding_shovel = false;
  m_holdingPlant = pSeed->getPlantType ();
  m_holdingFromSlot = pSeed->getSlotNum ();
  m_currentCoolDownMask = std::make_shared<CoolDownMask> (
      shared_from_this (), m_holdingFromSlot,
      slotPlant[static_cast<std::size_t> (m_holdingPlant)]);
  return true;
}

void
GameWorld::ShovelPlant (Plant *plant)
{
  if (plant->getPlantType () != PlantType::PLANT_NONE)
    m_object_list.remove_if ([plant] (std::shared_ptr<GameObject> &x) {
      return x.get () == plant;
    });
  m_holding_shovel = false;
}

bool
GameWorld::PlantAt (Plant *plant)
{
  if (m_holdingPlant == PlantType::PLANT_NONE)
    return true;
  // wallnut healing: only work for wallnut, so direct judgement rather than
  // some functions.
  if (plant->getPlantType () == PlantType::PLANT_WALLNUT
      && m_holdingPlant == PlantType::PLANT_WALLNUT)
    {
      plant->setHealth (
          plantHealth[static_cast<std::size_t> (PlantType::PLANT_WALLNUT)]);
      m_currentCoolDownMask = nullptr;
      m_holdingPlant = PlantType::PLANT_NONE;
      m_holdingFromSlot = -1;
      return true;
    }
  if (plant->getPlantType () != PlantType::PLANT_NONE)
    {
      m_currentCoolDownMask = nullptr;
      m_holdingPlant = PlantType::PLANT_NONE;
      m_holdingFromSlot = -1;
      return false;
    }

  if (m_sunCnt < seedCost[static_cast<size_t> (m_holdingPlant)])
    return false;
  m_object_list.push_back (m_currentCoolDownMask);
  m_currentCoolDownMask = nullptr;
  m_sunCnt -= seedCost[static_cast<size_t> (m_holdingPlant)];
  m_sunText->SetText (std::to_string (m_sunCnt));
  int x = plant->GetGridX (), y = plant->GetGridY ();
  m_object_list.remove_if (
      [plant] (std::shared_ptr<GameObject> &x) { return x.get () == plant; });
  m_object_list.remove_if ([&x, &y] (std::shared_ptr<GameObject> &obj) {
    return obj->GetGridX () == x && obj->GetGridY () == y && obj->is_plant ();
  });
  PlantAtPos (x, y, m_holdingPlant);
  m_holdingPlant = PlantType::PLANT_NONE;
  m_holdingFromSlot = -1;
  return true;
}

void
GameWorld::ClickAtPlant (Plant *plant)
{
  if (m_holding_shovel)
    ShovelPlant (plant);
  else
    PlantAt (plant);
}

bool
GameWorld::HasCoolDown (std::shared_ptr<GameObject> pGameObject) const
{
  return typeid (pGameObject) == typeid (std::shared_ptr<CoolDownMask>);
}

void
GameWorld::spawnNaturalSun (int worth)
{
  m_object_list.push_back (std::make_shared<NaturalSun> (
      shared_from_this (),
      randInt (FIRST_COL_CENTER,
               FIRST_COL_CENTER + (GAME_COLS - 1) * LAWN_GRID_WIDTH),
      randInt (FIRST_ROW_CENTER,
               FIRST_ROW_CENTER + (GAME_ROWS - 1) * LAWN_GRID_HEIGHT),
      worth));
}

void
GameWorld::spawnProducedSunAt (int x, int y, int worth)
{
  m_object_list.push_back (
      std::make_shared<ProducedSun> (shared_from_this (), x, y, worth));
}

void
GameWorld::setSunCnt (unsigned int new_cnt)
{
  m_sunCnt = new_cnt;
  m_sunText->SetText (std::to_string (m_sunCnt));
}

void
GameWorld::addSunCnt (int delta)
{
  m_sunCnt += delta;
  m_sunText->SetText (std::to_string (m_sunCnt));
}

void
GameWorld::PlantAtPos (int x, int y, PlantType type)
{
  switch (type)
    {
    case PlantType::PLANT_NONE:
      m_object_list.push_back (std::make_shared<Plant> (
          shared_from_this (), PlantType::PLANT_NONE, x, y));
      break;
    case PlantType::PLANT_SUNFLOWER:
      m_object_list.push_back (
          std::make_shared<Sunflower> (shared_from_this (), x, y));
      break;
    case PlantType::PLANT_WALLNUT:
      m_object_list.push_back (
          std::make_shared<Wallnut> (shared_from_this (), x, y));
      break;
    case PlantType::PLANT_PEASHOOTER:
      m_object_list.push_back (
          std::make_shared<PeaShooter> (shared_from_this (), x, y));
      break;
    case PlantType::PLANT_REPEATER:
      m_object_list.push_back (
          std::make_shared<Repeater> (shared_from_this (), x, y));
      break;
    case PlantType::PLANT_CHERRY_BOMB:
      m_object_list.push_back (
          std::make_shared<CherryBomb> (shared_from_this (), x, y));
      break;
    default:
      break;
    }
}

bool
GameWorld::areColliding (std::shared_ptr<GameObject> obj1,
                         std::shared_ptr<GameObject> obj2)
{
  return (2 * std::abs (obj1->GetX () - obj2->GetX ())
          < obj1->GetWidth () + obj2->GetWidth ())
         && (2 * std::abs (obj1->GetY () - obj2->GetY ())
             < obj1->GetHeight () + obj2->GetHeight ());
}

/*
 Zombie Collision Detection
 */
void
GameWorld::UpdateZombieState ()
{
  for (auto &zombie_it : m_zombie_it_list)
    {
      bool flag = false;
      auto zombie_ptr = std::dynamic_pointer_cast<Zombie> (*zombie_it);
      for (auto &obj : m_object_list)
        {
          if (obj->is_projectile () && !obj->isDead ()
              && areColliding (obj, *zombie_it))
            {
              (*zombie_it)->addHealth (obj->getHarm ());
              obj->addHealth (
                  -1); // not a magic number, just let the health reduce by 1;
            }
          else if (obj->is_plant () && areColliding (obj, *zombie_it))
            {
              flag = true;
              obj->addHealth ((*zombie_it)->getHarm ());
            }
        }
      if (!flag && zombie_ptr->getIsEating ())
        {
          zombie_ptr->PlayAnimation (ANIMID_WALK_ANIM);
          zombie_ptr->setIsEating (flag);
        }
      else if (flag && !zombie_ptr->getIsEating ())
        {
          zombie_ptr->PlayAnimation (ANIMID_EAT_ANIM);
          zombie_ptr->setIsEating (flag);
        }
    }
}

void
GameWorld::spawnZombieAt (int row_y, int x, ZombieType type)
{
  m_row_zombie_cnt[row_y]++;
  switch (type)
    {
    case ZombieType::ZOMBIE_REGULAR:
      m_object_list.push_back (
          std::make_shared<RegularZombie> (shared_from_this (), row_y, x));
      m_zombie_it_list.push_back (std::prev (m_object_list.end ()));
      break;
    case ZombieType::ZOMBIE_BUCKET:
      m_object_list.push_back (
          std::make_shared<BucketHeadZombie> (shared_from_this (), row_y, x));
      m_zombie_it_list.push_back (std::prev (m_object_list.end ()));
      break;
    default:
      break;
    }
}

void
GameWorld::spawnProjectileAt (int x, int y, ProjectileType type)
{
  switch (type)
    {
    case ProjectileType::PROJ_PEA:
      m_object_list.push_back (
          std::make_shared<Pea> (shared_from_this (), x, y));
      break;
    case ProjectileType::PROJ_POW:
      m_object_list.push_back (
          std::make_shared<Pow> (shared_from_this (), x, y));
      break;
    default:
      break;
    }
}
