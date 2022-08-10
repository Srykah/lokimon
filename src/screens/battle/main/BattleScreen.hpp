/*!
 * \file BattleState.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "screens/base/BaseScreen.hpp"
#include "screens/battle/main/BattleScreenView.hpp"

#include "gameplay/BattleContext.hpp"

namespace mon {

class BattleScreen : public BaseScreen {
 public:
  explicit BattleScreen(LokimonApplication& app, Trainer opponent);
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
  BattleContext ctx;
  const Screen* childScreen = nullptr;
};

}  // namespace mon
