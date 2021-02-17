/*!
 * \file BattleIntroScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "BattleIntroScreen.hpp"
#include <fmt/core.h>

namespace mon {

BattleIntroScreen::BattleIntroScreen(Application& app,
                                     const Trainer& trainer,
                                     const Monster& playerMonster,
                                     const Monster& trainerMonster,
                                     loki::gui::EventTextBoxController& textBox)
: BaseScreen(app)
, textBox(textBox) {
  auto str = fmt::format(
      "Welcome, {0}!\n"
      "Trainer {1} wants to battle!\n\n"
      "Trainer {1} sends {2}!\n\n"
      "Go, {3}!",
      getPlayer().getName(),
      trainer.getName(),
      trainerMonster.getName(),
      playerMonster.getName());
  textBox.setString(str);
}

bool BattleIntroScreen::update(sf::Time delta) {
  textBox.handleInputs();
  if (textBox.hasEnded()) {
    closeThisState();
  }
  return false;
}

bool BattleIntroScreen::updateView(sf::Time delta) {
  return true;
}

bool BattleIntroScreen::render(sf::RenderTarget& target,
                                    sf::RenderStates states) const {
  return true;
}

}
