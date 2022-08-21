#pragma once

#include "screens/base/BaseScreen.hpp"
#include "screens/map/MapScreen.hpp"

namespace mon {

class PlayerController {
 public:
  PlayerController(Player& player,
                   const loki::gfx::MapData& mapData,
                   const loki::system::EventHandler& eventHandler,
                   MapScreen& mapScreen);
  void init();

  bool update(sf::Time delta);
  bool updateView(sf::Time delta);

 private:
  Player& player;
  const loki::gfx::MapData& mapData;
  const loki::system::EventHandler& eventHandler;
  MapScreen& mapScreen;
};

}  // namespace mon
