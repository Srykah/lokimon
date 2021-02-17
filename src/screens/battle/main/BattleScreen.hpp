/*!
 * \file BattleState.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/gui/textBox/EventTextBoxController.hpp>
#include <models/gameplay/Trainer.hpp>
#include <screens/base/BaseScreen.hpp>
#include <screens/battle/main/BattleScreenView.hpp>

namespace mon {

class BattleScreen : public BaseScreen {
 public:
  explicit BattleScreen(Application& app, Trainer opponent);
  ~BattleScreen() override = default;
  void init() override;

  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  void chooseOpponentAttack();
  bool onIntroClose();
  bool onAttackMenuMove(unsigned int index);
  bool onAttackClose();

 private:
  BattleScreenView view;
  Trainer opponent;
  Monster* playerMonster = nullptr;
  Monster* opponentMonster = nullptr;
  const Attack* playerMove = nullptr;
  const Attack* opponentMove = nullptr;
  const Screen* childScreen = nullptr;
  loki::gui::EventTextBoxController textBox;
};

}  // namespace mon
