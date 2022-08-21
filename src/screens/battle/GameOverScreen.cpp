#include "GameOverScreen.hpp"

namespace mon {

GameOverScreen::GameOverScreen(LokimonApplication& app, BattleContext& ctx)
    : BaseScreen(app) {}

bool GameOverScreen::update(sf::Time delta) {
  closeThisScreen();
  return false;
}

bool GameOverScreen::render(sf::RenderTarget& target,
                            sf::RenderStates states) const {
  return true;
}

}  // namespace mon
