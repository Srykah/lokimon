/*!
 * \file AttackScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackScreen.hpp"
#include <loki/common/Random.hpp>

namespace mon {

AttackScreen::AttackScreen(Application& app) : BaseScreen(app) {}

bool AttackScreen::update(sf::Time delta) {
  return false;
}

bool AttackScreen::updateView(sf::Time delta) {
  return true;
}

bool AttackScreen::render(sf::RenderTarget& target,
                          sf::RenderStates states) const {
  return true;
}

void AttackScreen::damageStep() {
  if (playerMove->speed > opponentMove->speed ||
      playerMonster->getStats().speed >= opponentMonster->getStats().speed) {
    // player attack first
    computeAndPrintDamage(playerMonster, playerMove, opponentMonster);
    if (opponentMonster->getCurrentHP() > 0) {
      computeAndPrintDamage(opponentMonster, opponentMove, playerMonster);
    }
  } else {
    // opponent attack first
    computeAndPrintDamage(opponentMonster, opponentMove, playerMonster);
    if (playerMonster->getCurrentHP() > 0) {
      computeAndPrintDamage(playerMonster, playerMove, opponentMonster);
    }
  }
  view->updateHPTexts();
}

void AttackScreen::computeAndPrintDamage(Monster* attacker,
                                         const Attack* attack,
                                         Monster* defender) {
  int atk = 0;
  int def = 0;
  Effectiveness effectiveness = Effectiveness::NORMAL;
  int atkPower = 0;
  int atkCrit = 0;
  int atkFail = 0;
  if (std::holds_alternative<PhysicalEffect>(attack->effects[0])) {
    const auto& physicalEffect = std::get<PhysicalEffect>(attack->effects[0]);
    atk = attacker->getStats().atk;
    def = defender->getStats().def;
    effectiveness =
        getEffectiveness(physicalEffect.family, defender->getFamily());
    atkPower = physicalEffect.power;
    atkCrit = physicalEffect.crit;
    atkFail = physicalEffect.fail;
  } else if (std::holds_alternative<ElementalEffect>(attack->effects[0])) {
    const auto& elementalEffect = std::get<ElementalEffect>(attack->effects[0]);
    atk = attacker->getStats().elemAtk;
    def = defender->getStats().elemDef;
    effectiveness =
        getEffectiveness(elementalEffect.element, defender->getElement());
    atkPower = elementalEffect.power;
    atkCrit = elementalEffect.crit;
    atkFail = elementalEffect.fail;
  }

  bool fail = loki::common::roll0to100(atkFail);
  if (fail) {
    //view.printFailedAttack(attacker, attack);
  } else {
    bool crit = loki::common::roll0to100(atkCrit);
    if (crit) {
      def = 0;
    }
    int damage = std::max((100 + 2 * atk - def) * atkPower *
                          (100 + static_cast<int>(effectiveness) * 20) /
                          (2 * 100 * 100),
                          1);
    defender->loseHP(damage);

    //view.printAttack(attacker, defender, attack, damage, crit, effectiveness);
  }
}

}
