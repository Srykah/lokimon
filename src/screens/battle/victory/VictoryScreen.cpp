/*!
 * \file VictoryScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "VictoryScreen.hpp"

namespace mon {

VictoryScreen::VictoryScreen(Application& app) : BaseScreen(app) {}

bool VictoryScreen::update(sf::Time delta) {
  closeThisState();
  return false;
}

bool VictoryScreen::updateView(sf::Time delta) {
  return true;
}

bool VictoryScreen::render(sf::RenderTarget& target,
                           sf::RenderStates states) const {
  return true;
}

}
