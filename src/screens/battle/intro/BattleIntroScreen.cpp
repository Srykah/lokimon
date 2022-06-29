/*!
 * \file BattleIntroScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "BattleIntroScreen.hpp"
#include <fmt/core.h>

namespace mon {

BattleIntroScreen::BattleIntroScreen(Application& app, BattleContext& ctx)
    : BaseScreen(app), ctx(ctx) {
  ctx.textBox.setAnnotatedString(ctx.tpl.fill(
      getViewData().getI18nStr("/messages/battle/intro"_json_pointer)));
}

bool BattleIntroScreen::update(sf::Time delta) {
  ctx.textBox.update(delta);
  if (ctx.textBox.isActive()) {
    closeThisScreen();
  }
  return false;
}

bool BattleIntroScreen::render(sf::RenderTarget& target,
                               sf::RenderStates states) const {
  return true;
}

}  // namespace mon
