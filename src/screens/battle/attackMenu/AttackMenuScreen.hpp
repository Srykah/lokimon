/*!
 * \file AttackSelection.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <functional>
#include <loki/gui/widgets/containers/grid/Grid.hpp>
#include <loki/gui/widgets/elements/textBox/TextBox.hpp>
#include <loki/strings/tpl/TemplateEngine.hpp>
#include <models/data/Attack.hpp>
#include <models/gameplay/BattleContext.hpp>
#include <models/gameplay/Monster.hpp>
#include <screens/base/BaseScreen.hpp>
#include <screens/battle/attackMenu/AttackMenuScreenView.hpp>

namespace mon {

class AttackMenuScreen : public BaseScreen {
 public:
  AttackMenuScreen(Application& app, BattleContext& ctx);
  ~AttackMenuScreen() override = default;

  bool update(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  BattleContext& ctx;
  bool introDone = false;
  loki::gui::Grid menu;
};

}  // namespace mon
