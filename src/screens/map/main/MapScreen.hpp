/*!
 * \file MapScreen.hpp.h
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <screens/base/BaseScreen.hpp>
#include "MapScreenView.hpp"

namespace mon {

class MapScreen : public BaseScreen {
 public:
  MapScreen(Application& app, std::string mapName);
  ~MapScreen() override = default;
  void init() override;

  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  MapScreenView view;
  std::string mapName;
  loki::tiles::TilesetData tilesetData;
  loki::tiles::MapData mapData;
  loki::sprites::SpriteData playerSpriteData;
};

}  // namespace mon
