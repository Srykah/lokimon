/*!
 * \file BattleIntroScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/gui/elements/textBox/TextBox.hpp>
#include <loki/strings/tpl/TemplateEngine.hpp>
#include <models/gameplay/Trainer.hpp>
#include <screens/base/BaseScreen.hpp>

namespace mon {

class BattleIntroScreen : public BaseScreen {
 public:
  BattleIntroScreen(Application& app,
                    const Trainer& trainer,
                    const Monster& playerMonster,
                    const Monster& trainerMonster,
                    loki::tpl::TemplateEngine& tpl,
                    loki::gui::TextBox& textBox);
  ~BattleIntroScreen() override = default;

  bool update(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  loki::gui::TextBox& textBox;
};

}  // namespace mon
