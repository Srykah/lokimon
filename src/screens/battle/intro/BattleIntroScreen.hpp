/*!
 * \file BattleIntroScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/gui/textBox/TextBoxController.hpp>
#include <screens/base/BaseScreen.hpp>
#include <models/gameplay/Trainer.hpp>

namespace mon {

class BattleIntroScreen : public BaseScreen {
 public:
  BattleIntroScreen(Application& app,
                    const Trainer& trainer,
                    const Monster& playerMonster,
                    const Monster& trainerMonster,
                    loki::gui::TextBoxController& textBox);
  ~BattleIntroScreen() override = default;

  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  loki::gui::TextBoxController& textBox;
};

}  // namespace mon
