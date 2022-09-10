#pragma once

#include <loki/gui/elements/TextBox.hpp>

#include "gameplay/BattleContext.hpp"
#include "screens/base/BaseScreen.hpp"

namespace loki::gui {
class TextBox;
}

namespace mon {

class AttackCutsceneScreen : public BaseScreen {
 public:
  AttackCutsceneScreen(LokimonApplication& app, BattleContext& ctx);

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
  BattleContext& ctx;
};

}  // namespace mon
