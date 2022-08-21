#include "VictoryScreen.hpp"

namespace mon {

VictoryScreen::VictoryScreen(LokimonApplication& app, BattleContext& ctx)
    : BaseScreen(app) {}

bool VictoryScreen::update(sf::Time delta) {
  closeThisScreen();
  return false;
}

bool VictoryScreen::render(sf::RenderTarget& target,
                           sf::RenderStates states) const {
  return true;
}

}  // namespace mon
