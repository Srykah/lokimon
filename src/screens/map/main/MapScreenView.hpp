/*!
 * \file MapScreenView.hpp.h
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#if 0

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <loki/graphics/sprites/All.hpp>
#include <loki/graphics/tiles/All.hpp>
#include <other/Direction.hpp>

namespace mon {

class MapScreenView : public sf::Drawable {
 public:
  MapScreenView() = default;

  void update(sf::Time delta);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void setMapData(const loki::tiles::MapData& data);

  void spawnPlayer(sf::Vector2i pos, Direction facing);
  void movePlayer(Direction dir);

 private:
  loki::tiles::MapView mapView;
  sf::Vector2f tileSize;
};

}  // namespace mon

#endif