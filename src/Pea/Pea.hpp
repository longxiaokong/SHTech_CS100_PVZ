//
//  Pea.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef Pea_hpp
#define Pea_hpp
#include "Projectile.hpp"
class Pea : public Projectile
{
public:
  Pea (pGameWorld pWorld, int initial_x, int initial_y);
  virtual ~Pea () = default;

private:
};

#endif /* Pea_hpp */
