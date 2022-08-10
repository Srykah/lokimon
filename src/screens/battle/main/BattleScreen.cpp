/*!
 * \file BattleState.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "BattleScreen.hpp"
#include "screens/battle/attackCutscene/AttackCutsceneScreen.hpp"
#include "screens/battle/attackMenu/AttackMenuScreen.hpp"
#include "screens/battle/gameOver/GameOverScreen.hpp"
#include "screens/battle/intro/BattleIntroScreen.hpp"
#include "screens/battle/victory/VictoryScreen.hpp"

namespace mon {

BattleScreen::BattleScreen(LokimonApplication& app, Trainer _opponent)
    : BaseScreen(app), ctx {
      .opponent = std::move(_opponent),
      .playerMonster = &getPlayer().getPartyMonster(0),
      .opponentMonster = &ctx.opponent.getMonster(0),
      .playerMove = nullptr,
      .opponentMove = nullptr,
      .tpl {},
      .textBox{getEventHandler(), "ok"}
    } {
  // view.setPlayerMonster(playerMonster);
  // view.setOpponentMonster(opponentMonster);

  ctx.tpl.addRef("playerName", getPlayer().getName());
  ctx.tpl.addRef("playerMonster", ctx.playerMonster->getName());
  ctx.tpl.addRef("trainerName", ctx.opponent.getName());
  ctx.tpl.addRef("trainerMonster", ctx.opponentMonster->getName());
}

void BattleScreen::init() {
  Screen::init();

  // view.updateHPTexts();

  childScreen = pushScreen<BattleIntroScreen>(app, ctx);
  registerSignalHandler({childScreen, "close"},
                        [this]() { return onIntroClose(); });
}

bool BattleScreen::update(sf::Time delta) {
  return false;
}

bool BattleScreen::render(sf::RenderTarget& target,
                          sf::RenderStates states) const {
  // target.draw(view, states);
  return false;
}

void BattleScreen::chooseOpponentAttack() {
  ctx.opponentMove = &ctx.opponentMonster->getAttack(0);
}

bool BattleScreen::onIntroClose() {
  removeSignalHandler({childScreen, "close"});
  childScreen = pushScreen<AttackMenuScreen>(app, ctx);
  registerSignalHandler({childScreen, "move"},
                        [this](unsigned int i) { return onAttackMenuMove(i); });
  return false;
}

bool BattleScreen::onAttackMenuMove(unsigned int index) {
  removeSignalHandler({childScreen, "move"});
  ctx.playerMove = &ctx.playerMonster->getAttack(index);
  chooseOpponentAttack();
  childScreen = pushScreen<AttackCutsceneScreen>(app, ctx);
  registerSignalHandler({childScreen, "close"},
                        [this]() { return onAttackClose(); });
  return false;
}

bool BattleScreen::onAttackClose() {
  removeSignalHandler({childScreen, "close"});
  if (ctx.playerMonster->getCurrentHP() <= 0) {
    childScreen = pushScreen<GameOverScreen>(app, ctx);
    registerSignalHandler({childScreen, "close"}, [this]() {
      closeThisScreen();
      return false;
    });
  } else if (ctx.opponentMonster->getCurrentHP() <= 0) {
    childScreen = pushScreen<VictoryScreen>(app, ctx);
    registerSignalHandler({childScreen, "close"}, [this]() {
      closeThisScreen();
      return false;
    });
  } else {
    childScreen = pushScreen<AttackMenuScreen>(app, ctx);
    registerSignalHandler({childScreen, "move"}, [this](unsigned int i) {
      return onAttackMenuMove(i);
    });
  }
  return false;
}

}  // namespace mon
