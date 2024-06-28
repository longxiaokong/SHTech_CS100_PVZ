//
//  NaturalSun.hpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#ifndef NaturalSun_hpp
#define NaturalSun_hpp

#include "Sun.hpp"
class NaturalSun : public Sun, public std::enable_shared_from_this<NaturalSun> {
public:
  using std::enable_shared_from_this<NaturalSun>::shared_from_this;
  NaturalSun(pGameWorld, int, int, int worth=SUN_VALUE_DEFAULT);
  virtual void UpdateMoveStatus() override;
  virtual ~NaturalSun() = default;
private:
  int m_desc_y;
};

#endif /* NaturalSun_hpp */
