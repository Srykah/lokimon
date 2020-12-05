/*!
 * \file AttackScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <screens/base/BaseScreen.hpp>
#include <screens/battle/main/BattleScreenView.hpp>
namespace mon {

class AttackScreen : public BaseScreen {
 public:
  explicit AttackScreen(Application& app);
  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  void damageStep();
  void computeAndPrintDamage(Monster* attacker,
                             const Attack* attack,
                             Monster* defender);

 private:
  BattleScreenView* view = nullptr;
  Monster* playerMonster = nullptr;
  Monster* opponentMonster = nullptr;
  const Attack* playerMove = nullptr;
  const Attack* opponentMove = nullptr;
};

}  // namespace mon
