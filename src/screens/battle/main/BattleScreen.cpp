/*!
 * \file BattleState.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "BattleScreen.hpp"
#include <screens/battle/attack/AttackScreen.hpp>
#include <screens/battle/gameOver/GameOverScreen.hpp>
#include <screens/battle/intro/BattleIntroScreen.hpp>
#include <screens/battle/victory/VictoryScreen.hpp>
#include <screens/battle/attackMenu/AttackMenuScreen.hpp>

namespace mon {

BattleScreen::BattleScreen(Application& app, Trainer opponent)
    : BaseScreen(app),
      opponent(std::move(opponent)),
      playerMonster(getPlayer().getPartyMonster(0)),
      opponentMonster(this->opponent.getMonster(0)),
      view(getViewData()) {
  view.setPlayerMonster(playerMonster);
  view.setOpponentMonster(opponentMonster);
  view.updateHPTexts();

  textBox.setView(view.getTextBox());

  childScreen = pushState<BattleIntroScreen>(opponent, *playerMonster, *opponentMonster, textBox);
  registerSignalHandler({childScreen, "close"}, [this]() {
    return onIntroClose();
  });
}

bool BattleScreen::update(sf::Time delta) {
  return false;
}

bool BattleScreen::render(sf::RenderTarget& target,
                          sf::RenderStates states) const {
  target.draw(view, states);
  return false;
}

bool BattleScreen::updateView(sf::Time delta) {
  view.update(delta);
  return false;
}

void BattleScreen::chooseOpponentAttack() {
  opponentMove = opponentMonster->getAttack(0);
}

bool BattleScreen::onIntroClose() {
  removeSignalHandler({ childScreen, "close" });
  childScreen = pushState<AttackMenuScreen>(*playerMonster);
  registerSignalHandler({childScreen, "move"}, [this](unsigned int i) {
    return onAttackMenuMove(i);
  });
  return false;
}

bool BattleScreen::onAttackMenuMove(unsigned int index) {
  removeSignalHandler({ childScreen, "move" });
  playerMove = playerMonster->getAttack(index);
  chooseOpponentAttack();
  childScreen = pushState<AttackScreen>();
  registerSignalHandler({childScreen, "close"}, [this]() {
    return onAttackClose();
  });
  return false;
}

bool BattleScreen::onAttackClose() {
  removeSignalHandler({ childScreen, "close" });
  if (playerMonster->getCurrentHP() <= 0) {
    childScreen = pushState<GameOverScreen>();
    registerSignalHandler({childScreen, "close"}, [this]() {
      clearStates();
    });
  } else if (opponentMonster->getCurrentHP() <= 0) {
    childScreen = pushState<VictoryScreen>();
    registerSignalHandler({childScreen, "close"}, [this]() {
      clearStates();
    });
  } else {
    childScreen = pushState<AttackMenuScreen>(*playerMonster);
    registerSignalHandler({childScreen, "move"}, [this](unsigned int i) {
      return onAttackMenuMove(i);
    });
  }
  return false;
}

}  // namespace mon
