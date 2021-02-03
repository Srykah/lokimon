/*!
 * \file MapScreenView.hpp.h
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <loki/sprites/All.hpp>
#include <loki/tiles/All.hpp>
#include <models/other/Direction.hpp>

namespace mon {

class MapScreenView : public sf::Drawable {
 public:
  MapScreenView() = default;

  void update(sf::Time delta);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void setMapData(const loki::tiles::MapData& data);
  void setPlayerSpriteData(const loki::sprites::SpriteData& data);

  void spawnPlayer(sf::Vector2i pos, Direction facing);
  void movePlayer(Direction dir);

 private:
  loki::tiles::MapView mapView;
  loki::sprites::SpriteView playerSprite;
  sf::Vector2f tileSize;
};

}  // namespace mon
