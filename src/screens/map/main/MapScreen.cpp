/*!
 * \file MapScreen.cpp.c
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "MapScreen.hpp"
#include <screens/map/player/PlayerController.hpp>
#include "core/path.hpp"

namespace mon {

MapScreen::MapScreen(LokimonApplication& app, std::string mapName)
    : BaseScreen(app),
      mapName(std::move(mapName)),
      playerSprite(getViewData().getPlayerSpriteData(), "idle_down") {}

void MapScreen::init() {
#if 0
  mapData.load(DATA_PATH / "maps" / (mapName + ".json"),
               [this](const std::filesystem::path& tilesetPath) {
                 tilesetData.load(DATA_PATH / "maps" / tilesetPath);
                 return &tilesetData;
               });
  view.setMapData(mapData);
  playerSpriteData.load(DATA_PATH / "sprites" / "player.json");
  view.setPlayerSpriteData(playerSpriteData);
  pushState<PlayerScreen>(mapData, view);
  Screen::init();
#endif
}

bool MapScreen::update(sf::Time delta) {
  return false;
}

bool MapScreen::render(sf::RenderTarget& target,
                       sf::RenderStates states) const {
  target.draw(playerSprite, states);
  return false;
}

}  // namespace mon
