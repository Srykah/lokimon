#include "BattleScreen.hpp"
#include "VictoryScreen.hpp"
#include "screens/battle/AttackCutsceneScreen.hpp"
#include "screens/battle/AttackMenuScreen.hpp"
#include "screens/battle/BattleIntroScreen.hpp"
#include "screens/battle/GameOverScreen.hpp"

namespace mon {

BattleScreen::BattleScreen(LokimonApplication& app, Trainer _opponent)
    : BaseScreen(app),
      ctx{.opponent = std::move(_opponent),
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

}

bool BattleScreen::update(sf::Time delta) {
  return false;
}

bool BattleScreen::render(sf::RenderTarget& target,
                          sf::RenderStates states) const {
  // target.draw(view, core);
  return false;
}

void BattleScreen::chooseOpponentAttack() {
  ctx.opponentMove = &ctx.opponentMonster->getAttack(0);
}

bool BattleScreen::onIntroClose() {
  removeSignalHandler({childScreen, "close"});
  return false;
}

bool BattleScreen::onAttackMenuMove(unsigned int index) {
  removeSignalHandler({childScreen, "move"});
  ctx.playerMove = &ctx.playerMonster->getAttack(index);
  chooseOpponentAttack();
  return false;
}

bool BattleScreen::onAttackClose() {
  removeSignalHandler({childScreen, "close"});
  return false;
}

}  // namespace mon
