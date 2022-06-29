/*!
 * \file GameOverScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "GameOverScreen.hpp"

namespace mon {

GameOverScreen::GameOverScreen(Application& app, BattleContext& ctx) : BaseScreen(app) {}

bool GameOverScreen::update(sf::Time delta) {
  closeThisScreen();
  return false;
}

bool GameOverScreen::render(sf::RenderTarget& target,
                            sf::RenderStates states) const {
  return true;
}

}  // namespace mon
