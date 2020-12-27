/*!
 * \file AttackScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/gui/textBox/TextBoxController.hpp>
#include <screens/base/BaseScreen.hpp>
#include <screens/battle/main/BattleScreenView.hpp>
namespace mon {

class AttackScreen : public BaseScreen {
 public:
  AttackScreen(Application& app,
               Monster& playerMonster,
               const Attack& playerMove,
               Monster& opponentMonster,
               const Attack& opponentMove,
               loki::gui::TextBoxController& textBox,
               BattleScreenView& parentView);
  ~AttackScreen() override = default;

  bool update(sf::Time delta) override;
  bool updateView(sf::Time delta) override;
  bool render(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  void damageStep();
  void computeAndPrintDamage(Monster& attacker,
                             const Attack& attack,
                             Monster& defender);
  void printFailedAttack(const Monster& attacker, const Attack& attack);
  void printAttack(const Monster& attacker,
                   const Monster& defender,
                   const Attack& attack,
                   int damage,
                   bool crit,
                   Effectiveness effectiveness);
  static std::string getShownName(const Monster& monster);

 private:
  loki::gui::TextBoxController& textBox;
  BattleScreenView& parentView;
  Monster& playerMonster;
  const Attack& playerMove;
  Monster& opponentMonster;
  const Attack& opponentMove;
};

}  // namespace mon
