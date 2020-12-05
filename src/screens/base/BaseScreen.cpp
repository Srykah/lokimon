/*!
 * \file BaseScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "BaseScreen.hpp"
#include <loki/screens/ScreenStack.hpp>

namespace mon {

BaseScreen::BaseScreen(Application& app) : Screen(app.stack), app(app) {}

Player& BaseScreen::getPlayer() const {
  return app.player;
}

void BaseScreen::clearStates() {
  stack.clear();
}

const GameData& BaseScreen::getGameData() const {
  return app.gameData;
}

const ViewData& BaseScreen::getViewData() const {
  return app.viewData;
}

loki::input::EventHandler& BaseScreen::getEventHandler() {
  return app.eventHandler;
}

void BaseScreen::sendSignal(const std::string& signalName) {
  stack.sendSignal({this, signalName});
}

void BaseScreen::closeState(const loki::screens::Screen* screen) {
  stack.close(screen);
}

void BaseScreen::closeStatesAbove() {
  stack.closeAbove(this);
}

void BaseScreen::closeThisState() {
  stack.close(this);
}

}