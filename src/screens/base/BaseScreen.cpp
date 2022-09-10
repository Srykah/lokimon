#include "BaseScreen.hpp"

#include <loki/system/screens/ScreenStack.hpp>

namespace mon {

BaseScreen::BaseScreen(LokimonApplication& app) : app(app) {}

const Player& BaseScreen::getPlayer() const {
  return app.player;
}

Player& BaseScreen::getPlayer() {
  return app.player;
}

const GameData& BaseScreen::getGameData() const {
  return app.gameData;
}

const ViewData& BaseScreen::getViewData() const {
  return app.viewData;
}

const loki::system::InputManager& BaseScreen::getEventHandler() const {
  return app.eventHandler;
}

}  // namespace mon
