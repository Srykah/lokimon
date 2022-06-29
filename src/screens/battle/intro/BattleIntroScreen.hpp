/*!
 * \file BattleIntroScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/gui/widgets/elements/textBox/TextBox.hpp>
#include <loki/strings/tpl/TemplateEngine.hpp>
#include <models/gameplay/BattleContext.hpp>
#include <models/gameplay/Trainer.hpp>
#include <screens/base/BaseScreen.hpp>

namespace mon {

class BattleIntroScreen : public BaseScreen {
 public:
  BattleIntroScreen(Application& app, BattleContext& ctx);
  ~BattleIntroScreen() override = default;

  bool update(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  BattleContext& ctx;
};

}  // namespace mon
