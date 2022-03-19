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
                                     loki::tpl::TemplateEngine& tpl,
                                     loki::gui::TextBox& textBox)
    : BaseScreen(app), textBox(textBox) {
  textBox.setAnnotatedString(tpl.fill(
      getViewData().getI18nStr("/messages/battle/intro"_json_pointer)));
}

bool BattleIntroScreen::update(sf::Time delta) {
  textBox.update(delta);
  if (textBox.isActive()) {
    closeThisScreen();
  }
  return false;
}

bool BattleIntroScreen::render(sf::RenderTarget& target,
                               sf::RenderStates states) const {
  return true;
}

}  // namespace mon
