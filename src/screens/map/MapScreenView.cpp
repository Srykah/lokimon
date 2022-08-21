#include "MapScreenView.hpp"

#if 0
namespace mon {

void MapScreenView::update(sf::Time delta) {
  mapView.update(delta);
}

void MapScreenView::draw(sf::RenderTarget& target,
                         sf::RenderStates core) const {
  mapView.drawLayer(0, target, core);
  target.draw(playerSprite, core);
  mapView.drawLayer(1, target, core);
}

void MapScreenView::setMapData(const loki::gfx::MapData& data) {
  mapView.setData(data);
  tileSize = sf::Vector2f{mapView.getData().tilesets[0]->tileSize};
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
#endif