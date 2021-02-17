/*!
 * \file AttackScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackScreen.hpp"
#include <loki/common/Random.hpp>

namespace mon {

AttackScreen::AttackScreen(Application& app,
                           Monster& playerMonster,
                           const Attack& playerMove,
                           Monster& opponentMonster,
                           const Attack& opponentMove,
                           loki::gui::EventTextBoxController& textBox,
                           BattleScreenView& parentView)
    : BaseScreen(app),
      textBox(textBox),
      parentView(parentView),
      playerMonster(playerMonster),
      playerMove(playerMove),
      opponentMonster(opponentMonster),
      opponentMove(opponentMove) {
  damageStep();
}

bool AttackScreen::update(sf::Time delta) {
  textBox.handleInputs();
  if (textBox.hasEnded()) {
    closeThisState();
  }
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
  if (playerMove.speed > opponentMove.speed ||
      playerMonster.getStats().speed >= opponentMonster.getStats().speed) {
    // player attack first
    computeAndPrintDamage(playerMonster, playerMove, opponentMonster);
    if (opponentMonster.getCurrentHP() > 0) {
      computeAndPrintDamage(opponentMonster, opponentMove, playerMonster);
    }
  } else {
    // opponent attack first
    computeAndPrintDamage(opponentMonster, opponentMove, playerMonster);
    if (playerMonster.getCurrentHP() > 0) {
      computeAndPrintDamage(playerMonster, playerMove, opponentMonster);
    }
  }
  parentView.updateHPTexts();
}

void AttackScreen::computeAndPrintDamage(Monster& attacker,
                                         const Attack& attack,
                                         Monster& defender) {
  int atk = 0;
  int def = 0;
  Effectiveness effectiveness = Effectiveness::NORMAL;
  int atkPower = 0;
  int atkCrit = 0;
  int atkFail = 0;
  if (std::holds_alternative<PhysicalEffect>(attack.effects[0])) {
    const auto& physicalEffect = std::get<PhysicalEffect>(attack.effects[0]);
    atk = attacker.getStats().atk;
    def = defender.getStats().def;
    effectiveness =
        getEffectiveness(physicalEffect.family, defender.getFamily());
    atkPower = physicalEffect.power;
    atkCrit = physicalEffect.crit;
    atkFail = physicalEffect.fail;
  } else if (std::holds_alternative<ElementalEffect>(attack.effects[0])) {
    const auto& elementalEffect = std::get<ElementalEffect>(attack.effects[0]);
    atk = attacker.getStats().elemAtk;
    def = defender.getStats().elemDef;
    effectiveness =
        getEffectiveness(elementalEffect.element, defender.getElement());
    atkPower = elementalEffect.power;
    atkCrit = elementalEffect.crit;
    atkFail = elementalEffect.fail;
  }

  bool fail = loki::common::roll0to100(atkFail);
  if (fail) {
    printFailedAttack(attacker, attack);
  } else {
    bool crit = loki::common::roll0to100(atkCrit);
    if (crit) {
      def = 0;
    }
    int damage = std::max((100 + 2 * atk - def) * atkPower *
                          (100 + static_cast<int>(effectiveness) * 20) /
                          (2 * 100 * 100),
                          1);
    defender.loseHP(damage);

    printAttack(attacker, defender, attack, damage, crit, effectiveness);
  }
}

void AttackScreen::printFailedAttack(const Monster& attacker,
                                     const Attack& attack) {
  textBox.setString(getShownName(attacker) + " uses " + attack.names.at("en") +
                    "!\n\nBut it failed...");
}

void AttackScreen::printAttack(const Monster& attacker,
                               const Monster& defender,
                               const Attack& attack,
                               int damage,
                               bool crit,
                               Effectiveness effectiveness) {
  sf::String str;
  str += getShownName(attacker) + " uses " + attack.names.at("en") + "!\n\n";
  if (crit) {
    str += "It's a critical hit!\n\n";
  }
  switch (effectiveness) {
    case Effectiveness::WORST:
      str += "It's really ineffective...\n\n";
      break;

    case Effectiveness::BAD:
      str += "It is not very effective...\n\n";
      break;

    case Effectiveness::GOOD:
      str += "It is very effective!\n\n";
      break;

    case Effectiveness::BEST:
      str += "It is extremely effective!\n\n";
      break;

    default:
      break;
  }
  str += getShownName(defender) + " looses " + std::to_string(damage) + " HP!";

  textBox.setString(str);
}

std::string AttackScreen::getShownName(const Monster& monster) {
  if (!monster.isAlly()) {
    return "Opponent " + monster.getName();
  } else {
    return monster.getName();
  }
}

}  // namespace mon
