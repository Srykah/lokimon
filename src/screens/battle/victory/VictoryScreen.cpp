/*!
 * \file VictoryScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "VictoryScreen.hpp"

namespace mon {

VictoryScreen::VictoryScreen(Application& app, BattleContext& ctx) : BaseScreen(app) {}

bool VictoryScreen::update(sf::Time delta) {
  closeThisScreen();
  return false;
}

bool VictoryScreen::render(sf::RenderTarget& target,
                           sf::RenderStates states) const {
  return true;
}

}  // namespace mon
