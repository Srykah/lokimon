/*!
 * \file MapScreenView.cpp.c
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "MapScreenView.hpp"

namespace mon {

void MapScreenView::update(sf::Time delta) {
  mapView.update(delta);
}

void MapScreenView::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const {
  target.draw(*mapView.getLayers()[0], states);
  target.draw(playerSprite, states);
  target.draw(*mapView.getLayers()[1], states);
}

void MapScreenView::setMapData(const loki::tiles::MapData& data) {
  mapView.setData(data);
  tileSize = sf::Vector2f{mapView.getData().tilesets[0]->tileSize};
}

void MapScreenView::setPlayerSpriteData(const loki::sprites::SpriteData& data) {
  playerSprite.setData(data);
}

void MapScreenView::spawnPlayer(sf::Vector2i pos, Direction facing) {
  playerSprite.setPosition((pos.x + 0.5f) * tileSize.x,
                           (pos.y + 0.5f) * tileSize.y);
  playerSprite.setAnim("idle_" + to_string(facing));
}

void MapScreenView::movePlayer(Direction dir) {
  if (dir == Direction::UP) {
    playerSprite.move(0, -tileSize.y);
  } else if (dir == Direction::DOWN) {
    playerSprite.move(0, tileSize.y);
  } else if (dir == Direction::LEFT) {
    playerSprite.move(-tileSize.x, 0);
  } else {
    playerSprite.move(tileSize.x, 0);
  }
  playerSprite.setAnim("idle_" + to_string(dir));
}

}  // namespace mon
