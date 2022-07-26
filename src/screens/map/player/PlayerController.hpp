/*!
 * \file PlayerScreen.hpp.h
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <screens/base/BaseScreen.hpp>
#include "screens/map/main/MapScreen.hpp"

namespace mon {

class PlayerController {
 public:
  PlayerController(Player& player,
                   const loki::tiles::MapData& mapData,
                   const loki::input::EventHandler& eventHandler,
                   MapScreen& mapScreen);
  void init();

  bool update(sf::Time delta);
  bool updateView(sf::Time delta);

 private:
  Player& player;
  const loki::tiles::MapData& mapData;
  const loki::input::EventHandler& eventHandler;
  MapScreen& mapScreen;
};

}  // namespace mon
