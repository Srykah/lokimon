/*!
 * \file BaseScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "BaseScreen.hpp"
#include <loki/system/screens/ScreenStack.hpp>

namespace mon {

BaseScreen::BaseScreen(Application& app) : app(app) {}

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

const loki::input::EventHandler& BaseScreen::getEventHandler() const {
  return app.eventHandler;
}

loki::screens::ScreenStack& BaseScreen::getScreenStack() {
  return app.stack;
}

}  // namespace mon
