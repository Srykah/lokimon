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

BattleScreen::BattleScreen(Application& app, Trainer _opponent)
    : BaseScreen(app),
      opponent(std::move(_opponent)),
      playerMonster(&getPlayer().getPartyMonster(0)),
      opponentMonster(&opponent.getMonster(0)),
      textBox(getEventHandler(), "ok") {
  // view.setPlayerMonster(playerMonster);
  // view.setOpponentMonster(opponentMonster);

  tpl.addRef("playerName", getPlayer().getName());
  tpl.addRef("playerMonster", playerMonster->getName());
  tpl.addRef("trainerName", opponent.getName());
  tpl.addRef("trainerMonster", opponentMonster->getName());
}

void BattleScreen::init() {
  Screen::init();

  // view.updateHPTexts();

  childScreen = pushScreen<BattleIntroScreen>(app, opponent, *playerMonster,
                                              *opponentMonster, tpl, textBox);
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
  opponentMove = &opponentMonster->getAttack(0);
}

bool BattleScreen::onIntroClose() {
  removeSignalHandler({childScreen, "close"});
  childScreen = pushScreen<AttackMenuScreen>(app, *playerMonster, tpl, textBox);
  registerSignalHandler({childScreen, "move"},
                        [this](unsigned int i) { return onAttackMenuMove(i); });
  return false;
}

bool BattleScreen::onAttackMenuMove(unsigned int index) {
  removeSignalHandler({childScreen, "move"});
  playerMove = &playerMonster->getAttack(index);
  chooseOpponentAttack();
  childScreen = pushScreen<AttackCutsceneScreen>(app, *playerMonster,
                                                 *playerMove, *opponentMonster,
                                                 *opponentMove, textBox);
  registerSignalHandler({childScreen, "close"},
                        [this]() { return onAttackClose(); });
  return false;
}

bool BattleScreen::onAttackClose() {
  removeSignalHandler({childScreen, "close"});
  if (playerMonster->getCurrentHP() <= 0) {
    childScreen = pushScreen<GameOverScreen>(app);
    registerSignalHandler({childScreen, "close"}, [this]() {
      closeThisScreen();
      return false;
    });
  } else if (opponentMonster->getCurrentHP() <= 0) {
    childScreen = pushScreen<VictoryScreen>(app);
    registerSignalHandler({childScreen, "close"}, [this]() {
      closeThisScreen();
      return false;
    });
  } else {
    childScreen =
        pushScreen<AttackMenuScreen>(app, *playerMonster, tpl, textBox);
    registerSignalHandler({childScreen, "move"}, [this](unsigned int i) {
      return onAttackMenuMove(i);
    });
  }
  return false;
}

}  // namespace mon
