/*!
 * \file BattleState.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/gui/elements/textBox/TextBox.hpp>
#include <loki/strings/tpl/TemplateEngine.hpp>
#include "models/gameplay/Trainer.hpp"
#include "screens/base/BaseScreen.hpp"
#include "screens/battle/main/BattleScreenView.hpp"

namespace mon {

class BattleScreen : public BaseScreen {
 public:
  explicit BattleScreen(Application& app, Trainer opponent);
  ~BattleScreen() override = default;
  void init() override;

  bool update(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  void chooseOpponentAttack();
  bool onIntroClose();
  bool onAttackMenuMove(unsigned int index);
  bool onAttackClose();

 private:
  // BattleScreenView view;
  Trainer opponent;
  Monster* playerMonster = nullptr;
  Monster* opponentMonster = nullptr;
  const Attack* playerMove = nullptr;
  const Attack* opponentMove = nullptr;
  const Screen* childScreen = nullptr;
  loki::tpl::TemplateEngine tpl;
  loki::gui::TextBox textBox;
};

}  // namespace mon
