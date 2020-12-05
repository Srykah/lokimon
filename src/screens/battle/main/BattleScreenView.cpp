/*!
 * \file BattleScreenView.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "BattleScreenView.hpp"
#include <fmt/core.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include <loki/gui/frame/RectangleShapeFrame.hpp>

namespace mon {

BattleScreenView::BattleScreenView(const ViewData& viewData)
    : playerMonsterShape({50.f, 50.f}),
      opponentMonsterShape({50.f, 50.f}),
      textBox(
          2,
          viewData.getTextStyle(),
          std::make_unique<loki::gui::RectangleShapeFrame>(
              sf::Vector2f{600.f, 120.f},
              10.f,
              loki::styles::ShapeStyle{nullptr, sf::IntRect{}, sf::Color::Blue,
                                       sf::Color::White, -5.f})) {
  playerMonsterShape.setFillColor(sf::Color::Red);
  playerMonsterShape.setPosition({100.f, 150.f});

  opponentMonsterShape.setFillColor(sf::Color::Blue);
  opponentMonsterShape.setPosition({450.f, 50.f});

  textBox.setPosition({20.f, 220.f});

  viewData.getTextStyle().applyTo(playerMonsterHPText);
  playerMonsterHPText.setPosition({100.f, 120.f});

  viewData.getTextStyle().applyTo(opponentMonsterHPText);
  opponentMonsterHPText.setPosition({450.f, 20.f});
}

void BattleScreenView::setPlayerMonster(const Monster* _playerMonster) {
  this->playerMonster = _playerMonster;
}

void BattleScreenView::setOpponentMonster(const Monster* _opponentMonster) {
  this->opponentMonster = _opponentMonster;
}

void BattleScreenView::draw(sf::RenderTarget& target,
                            sf::RenderStates states) const {
  target.draw(playerMonsterShape, states);
  target.draw(opponentMonsterShape, states);
  target.draw(playerMonsterHPText, states);
  target.draw(opponentMonsterHPText, states);
  target.draw(textBox, states);
}

/*void BattleScreenView::printIntro() {
  auto introText = fmt::format(
      "Welcome, {0}!\n"
      "Trainer {1} wants to battle!\n"
      "Trainer {1} sends {2}!\n"
      "Go, {3}!",
      player.getName(), opponent.getName(), opponentMonster->getName(),
      playerMonster->getName());
  log.setString(introText);
}

void BattleScreenView::printEffectiveness(Effectiveness effectiveness) {
  switch (effectiveness) {
    case Effectiveness::WORST:
      cout << "It is not effective at all...\n";
      break;

    case Effectiveness::BAD:
      cout << "It is not very effective...\n";
      break;

    case Effectiveness::GOOD:
      cout << "It is very effective!\n";
      break;

    case Effectiveness::BEST:
      cout << "It is super effective!\n";
      break;

    default:
      break;
  }
}

void BattleScreenView::printFailedAttack(const Monster* attacker,
                                         const Attack* attack) {
  printAttackIntro(attacker, attack);
  cout << "...But it failed!" << endl;
}

void BattleScreenView::printAttack(const Monster* attacker,
                                   const Monster* defender,
                                   const Attack* attack,
                                   int damage,
                                   bool crit,
                                   Effectiveness effectiveness) {
  printAttackIntro(attacker, attack);
  if (crit) {
    cout << "Critical hit!\n";
  }
  printEffectiveness(effectiveness);
  cout << (attacker->isAlly() ? "Opponent " : "") << defender->getName()
       << " looses " << damage << " HP!\n";
  if (defender->getCurrentHP() <= 0) {
    cout << (attacker->isAlly() ? "Opponent " : "") << defender->getName()
         << " has fainted!\n";
  }
}

void BattleScreenView::printVictoryMessage() {
  cout << "Trainer " << opponent.getName() << " is defeated!\n";
  cout << "\"Ha! You got me!\"\n";
  cout << "You win 200$!\n";
  cout << "Thanks for playing!" << endl;
}

void BattleScreenView::printGameOverMessage() {
  cout << "You lose!\n";
  cout << "Try again next time!" << endl;
}

void BattleScreenView::printAttackIntro(const Monster* attacker,
                                        const Attack* attack) {
  cout << (attacker->isAlly() ? "" : "Opponent ") << attacker->getName()
       << " uses " << attack->names.at("en").toAnsiString() << "!\n";
}*/

void BattleScreenView::updateHPTexts() {
  playerMonsterHPText.setString(fmt::format(
      "{}/{} HP", playerMonster->getCurrentHP(), playerMonster->getStats().HP));
  opponentMonsterHPText.setString(fmt::format("{}/{} HP",
                                              opponentMonster->getCurrentHP(),
                                              opponentMonster->getStats().HP));
}

void BattleScreenView::update(sf::Time delta) {}

loki::gui::TextBox* BattleScreenView::getTextBox() {
  return &textBox;
}

}  // namespace mon
