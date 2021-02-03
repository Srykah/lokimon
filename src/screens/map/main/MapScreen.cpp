/*!
 * \file MapScreen.cpp.c
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "MapScreen.hpp"
#include "core/path.hpp"

namespace mon {

MapScreen::MapScreen(Application& app, std::string mapName)
    : BaseScreen(app), mapName(std::move(mapName)) {}

void MapScreen::init() {
  mapData.load(DATA_PATH / "maps" / (mapName + ".json"),
               [this](const std::filesystem::path& tilesetPath) {
                 tilesetData.load(DATA_PATH / "maps" / tilesetPath);
                 return &tilesetData;
               });
  view.setMapData(mapData);
  playerSpriteData.load(DATA_PATH / "sprites" / "player.json");
  view.setPlayerSpriteData(playerSpriteData);
  Screen::init();
}

bool MapScreen::update(sf::Time delta) {
  return false;
}

bool MapScreen::updateView(sf::Time delta) {
  view.update(delta);
  return false;
}

bool MapScreen::render(sf::RenderTarget& target,
                       sf::RenderStates states) const {
  target.draw(view, states);
  return false;
}

}  // namespace mon
