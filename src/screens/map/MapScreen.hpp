#pragma once

#include <loki/graphics/sprites/Sprite.hpp>

#include "MapScreenView.hpp"
#include "screens/base/BaseScreen.hpp"

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
  loki::gfx::Sprite playerSprite;
};

}  // namespace mon
