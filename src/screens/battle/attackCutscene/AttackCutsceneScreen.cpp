/*!
 * \file AttackCutsceneScreen.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackCutsceneScreen.hpp"
#include <loki/core/utils/Random.hpp>

namespace mon {

AttackCutsceneScreen::AttackCutsceneScreen(Application& app, BattleContext& ctx)
    : BaseScreen(app), ctx(ctx) {
  damageStep();
}

bool AttackCutsceneScreen::update(sf::Time delta) {
  ctx.textBox.update(delta);
  if (ctx.textBox.isActive()) {
    closeThisScreen();
  }
  return false;
}

bool AttackCutsceneScreen::render(sf::RenderTarget& target,
                                  sf::RenderStates states) const {
  return true;
}

void AttackCutsceneScreen::damageStep() {
  if (ctx.playerMove->speed > ctx.opponentMove->speed ||
      ctx.playerMonster->getStats().speed >=
          ctx.opponentMonster->getStats().speed) {
    // player attackCutscene first
    computeAndPrintDamage(*ctx.playerMonster, *ctx.playerMove,
                          *ctx.opponentMonster);
    if (ctx.opponentMonster->getCurrentHP() > 0) {
      computeAndPrintDamage(*ctx.opponentMonster, *ctx.opponentMove,
                            *ctx.playerMonster);
    }
  } else {
    // opponent attackCutscene first
    computeAndPrintDamage(*ctx.opponentMonster, *ctx.opponentMove,
                          *ctx.playerMonster);
    if (ctx.playerMonster->getCurrentHP() > 0) {
      computeAndPrintDamage(*ctx.playerMonster, *ctx.playerMove,
                            *ctx.opponentMonster);
    }
  }
  // parentView.updateHPTexts();
}

void AttackCutsceneScreen::computeAndPrintDamage(Monster& attacker,
                                                 const Attack& attack,
                                                 Monster& defender) {
  float atk = 0.f;
  float def = 0.f;
  Effectiveness effectiveness = Effectiveness::NORMAL;
  float stab = 1.f;
  float pow = 0.f;

  if (std::holds_alternative<PhysicalEffect>(attack.effects[0])) {
    const auto& physEffect = std::get<PhysicalEffect>(attack.effects[0]);
    atk = static_cast<float>(attacker.getStats().atk);
    def = static_cast<float>(defender.getStats().def);
    effectiveness = getEffectiveness(physEffect.family, defender.getFamily());
    if (physEffect.family == attacker.getFamily()) {
      stab = 1.2;
    }
    pow = static_cast<float>(physEffect.power);

  } else if (std::holds_alternative<ElementalEffect>(attack.effects[0])) {
    const auto& elemEffect = std::get<ElementalEffect>(attack.effects[0]);
    atk = static_cast<float>(attacker.getStats().elemAtk);
    def = static_cast<float>(defender.getStats().elemDef);
    effectiveness = getEffectiveness(elemEffect.element, defender.getElement());
    if (elemEffect.element == attacker.getElement()) {
      stab = 1.2;
    }
    pow = static_cast<float>(elemEffect.power);
  }

  float lvl = 0.1f + attacker.getLevel() / 25.f;
  float eff = getEffectivenessMultiplier(effectiveness);
  int damage = std::max(
      static_cast<int>(std::floor(lvl * pow * atk / def * eff * stab)), 1);
  defender.loseHP(damage);

  printAttack(attacker, defender, attack, damage, effectiveness);
}

void AttackCutsceneScreen::printFailedAttack(const Monster& attacker,
                                             const Attack& attack) {
  ctx.textBox.setAnnotatedString(
      getShownName(attacker) + " uses " +
      getViewData().getI18nStr("/attacks/{}/name", attack.id) +
      "!\n\nBut it failed...");
}

void AttackCutsceneScreen::printAttack(const Monster& attacker,
                                       const Monster& defender,
                                       const Attack& attack,
                                       int damage,
                                       Effectiveness effectiveness) {
  sf::String str;
  str += getShownName(attacker) + " uses " +
         getViewData().getI18nStr("/attacks/{}/name", attack.id) + "!\n\n";
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

  ctx.textBox.setAnnotatedString(str);
}

std::string AttackCutsceneScreen::getShownName(const Monster& monster) {
  if (!monster.isAlly()) {
    return "Opponent " + monster.getName();
  } else {
    return monster.getName();
  }
}

}  // namespace mon
