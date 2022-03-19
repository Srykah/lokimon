/*!
 * \file AttackSelection.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackMenuScreen.hpp"
#include <fmt/format.h>
#include <iostream>
#include <loki/core/utils/IterAdapters.hpp>
#include <loki/gui/elements/label/TextLabel.hpp>

namespace mon {

AttackMenuScreen::AttackMenuScreen(Application& app,
                                   const Monster& monster,
                                   const loki::tpl::TemplateEngine& tpl,
                                   loki::gui::TextBox& textBox)
    : BaseScreen(app),
      monster(monster),
      menu({2u, 2u}),
      tpl(tpl),
      textBox(textBox) {
  for (auto&& [i, atkId] : loki::enumerate(monster.getMoveset())) {
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
  // target.draw(view, states);
  return false;
}

bool AttackMenuScreen::update(sf::Time delta) {
  if (!introDone) {
    textBox.update(delta);
    if (textBox.isActive()) {
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
