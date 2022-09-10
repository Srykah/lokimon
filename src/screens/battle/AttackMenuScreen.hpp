#pragma once

#include <functional>

#include <loki/core/tpl/TemplateEngine.hpp>
#include <loki/gui/containers/Grid.hpp>
#include <loki/gui/elements/TextBox.hpp>

#include "AttackMenuScreenView.hpp"
#include "data/Attack.hpp"
#include "gameplay/BattleContext.hpp"
#include "gameplay/Monster.hpp"
#include "screens/base/BaseScreen.hpp"

namespace mon {

class AttackMenuScreen : public BaseScreen {
 public:
  AttackMenuScreen(LokimonApplication& app, BattleContext& ctx);
  ~AttackMenuScreen() override = default;

  bool update(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  BattleContext& ctx;
  bool introDone = false;
  loki::gui::Grid menu;
};

}  // namespace mon
