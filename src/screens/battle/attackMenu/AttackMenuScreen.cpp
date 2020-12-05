/*!
 * \file AttackSelection.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackMenuScreen.hpp"
#include <iostream>

using std::cin, std::cout, std::endl;

namespace mon {

AttackMenuScreen::AttackMenuScreen(Application& app,
                                   const Monster& monster)
    : BaseScreen(app),
      monster(monster),
      view(getViewData(), monster) {}
bool AttackMenuScreen::render(sf::RenderTarget& target,
                              sf::RenderStates states) const {
  target.draw(view, states);
  return false;
}

bool AttackMenuScreen::update(sf::Time delta) {
  sendSignal("move selected", 0);
  closeThisState();
  return true;
}

bool AttackMenuScreen::updateView(sf::Time delta) {
  view.update(delta);
  return true;
}

}  // namespace mon
