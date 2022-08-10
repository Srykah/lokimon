/*!
 * \file MapScreen.hpp.h
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/graphics/sprites/Sprite.hpp>
#include <screens/base/BaseScreen.hpp>
#include "MapScreenView.hpp"

namespace mon {

class MapScreen : public BaseScreen {
 public:
  MapScreen(LokimonApplication& app, std::string mapName);
  ~MapScreen() override = default;
  void init() override;

  bool update(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  std::string mapName;
  loki::sprites::Sprite playerSprite;
};

}  // namespace mon
