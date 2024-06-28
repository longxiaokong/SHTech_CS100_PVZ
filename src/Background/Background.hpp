//
//  Background.hpp
//  Background
//
//  Created by lxk on 2024/6/27.
//

#ifndef Background_hpp
#define Background_hpp
#include "GameObject.hpp"
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class Background : public GameObject, public std::enable_shared_from_this<Background> {
public:
  using std::enable_shared_from_this<Background>::shared_from_this;
  Background(pGameWorld pWorld);
  virtual ~Background() = default;
  virtual void Update() override{}
  virtual void OnClick() override{}
private:

};

#endif /* Background_hpp */
