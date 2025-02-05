//
//  Wallnut.hpp
//  PvZ
//
//  Created by lxk on 2024/6/29.
//

#ifndef Wallnut_hpp
#define Wallnut_hpp

#include "Plant.hpp"

class Wallnut : public Plant
{
public:
  Wallnut (pGameWorld pWorld, int x, int y);
  virtual ~Wallnut () = default;
  virtual void Update () override;
  virtual bool
  is_plant () override
  {
    return true;
  };

private:
  bool m_cracked;
};

#endif /* Wallnut_hpp */
