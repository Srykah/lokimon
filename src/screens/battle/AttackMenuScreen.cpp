#include "AttackMenuScreen.hpp"

#include <iostream>

#include <fmt/format.h>

#include <loki/core/utils/IterAdapters.hpp>
#include <loki/gui/elements/TextLabel.hpp>

namespace mon {

AttackMenuScreen::AttackMenuScreen(LokimonApplication& app, BattleContext& ctx)
    : BaseScreen(app), ctx(ctx), menu({2u, 2u}) {
  for (auto&& [i, atkId] :
       loki::core::enumerate(ctx.playerMonster->getMoveset())) {
    if (!atkId.empty()) {
      menu.setItem({static_cast<unsigned int>(i % 2ull),
                    static_cast<unsigned int>(i / 2ull)},
                   std::make_unique<loki::gui::TextLabel>(fmt::format(
                       "{}. {}", std::to_string(i + 1),
                       getViewData().getI18nStr("/attacks/{}/name", atkId))));
    }
  }
}

bool AttackMenuScreen::render(sf::RenderTarget& target,
                              sf::RenderStates states) const {
  // target.draw(view, core);
  return false;
}

bool AttackMenuScreen::update(sf::Time delta) {
  if (!introDone) {
    ctx.textBox.update(delta);
    if (ctx.textBox.isActive()) {
      // view.showMenu();
      introDone = true;
    }
  } else {
    menu.update(delta);
    auto selection = -1;  // menu.getSelected();
    if (selection != -1) {
      sendSignal("move", 0u);
      closeThisScreen();
    }
  }

  return true;
}

}  // namespace mon
