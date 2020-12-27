/*!
 * \file GameOverScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "GameOverScreen.hpp"

namespace mon {

GameOverScreen::GameOverScreen(Application& app) : BaseScreen(app) {}

bool GameOverScreen::update(sf::Time delta) {
  closeThisState();
  return false;
}
bool GameOverScreen::updateView(sf::Time delta) {
  return true;
}
bool GameOverScreen::render(sf::RenderTarget& target,
                            sf::RenderStates states) const {
  return true;
}

}
