/*!
 * \file BattleIntroScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <gameplay/BattleContext.hpp>
#include <gameplay/Trainer.hpp>
#include <loki/core/tpl/TemplateEngine.hpp>
#include <loki/gui/elements/TextBox.hpp>
#include <screens/base/BaseScreen.hpp>

namespace mon {

class BattleIntroScreen : public BaseScreen {
 public:
  BattleIntroScreen(LokimonApplication& app, BattleContext& ctx);
  ~BattleIntroScreen() override = default;

  bool update(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  BattleContext& ctx;
};

}  // namespace mon
