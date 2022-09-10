#pragma once

#if 0
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <other/Direction.hpp>

#include <loki/graphics/gfx/All.hpp>

namespace mon {

class MapScreenView : public sf::Drawable {
 public:
  MapScreenView() = default;

  void update(sf::Time delta);
  void draw(sf::RenderTarget& target, sf::RenderStates core) const override;

  void setMapData(const loki::gfx::MapData& data);

  void spawnPlayer(sf::Vector2i pos, Direction facing);
  void movePlayer(Direction dir);

 private:
  loki::gfx::MapView mapView;
  sf::Vector2f tileSize;
};

}  // namespace mon
#endif