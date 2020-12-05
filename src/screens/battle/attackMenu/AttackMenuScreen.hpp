/*!
 * \file AttackSelection.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <functional>
#include <loki/gui/list/ListController.hpp>
#include <models/data/Attack.hpp>
#include <models/gameplay/Monster.hpp>
#include <screens/base/BaseScreen.hpp>
#include <screens/battle/attackMenu/AttackMenuScreenView.hpp>

namespace mon {

class AttackMenuScreen : public BaseScreen {
 public:
  AttackMenuScreen(Application& app,
                        const Monster& monster);
  ~AttackMenuScreen() override = default;

  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  loki::gui::ListController menu;
  AttackMenuScreenView view;
  const Monster& monster;
};

}  // namespace mon
