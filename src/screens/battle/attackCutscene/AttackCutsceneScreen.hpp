/*!
 * \file AttackScreen.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <loki/gui/elements/textBox/TextBox.hpp>
#include <screens/base/BaseScreen.hpp>
#include <screens/battle/main/BattleScreenView.hpp>

namespace loki::gui {
class TextBox;
}

namespace mon {

class AttackCutsceneScreen : public BaseScreen {
 public:
  AttackCutsceneScreen(Application& app,
                       Monster& playerMonster,
                       const Attack& playerMove,
                       Monster& opponentMonster,
                       const Attack& opponentMove,
                       loki::gui::TextBox& textBox);

  bool update(sf::Time delta) override;
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
                   Effectiveness effectiveness);
  static std::string getShownName(const Monster& monster);

 private:
  loki::gui::TextBox& textBox;
  Monster& playerMonster;
  const Attack& playerMove;
  Monster& opponentMonster;
  const Attack& opponentMove;
};

}  // namespace mon
