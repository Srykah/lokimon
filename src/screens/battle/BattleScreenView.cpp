#include "BattleScreenView.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <fmt/core.h>

#if 0
namespace mon {

const loki::gfx::ShapeStyle BattleScreenView::FRAME_STYLE{
    nullptr, sf::IntRect{}, sf::Color::Blue, sf::Color::White, -3.f};

BattleScreenView::BattleScreenView(const ViewData& viewData)
    : playerMonsterShape({25.f, 25.f}),
      opponentMonsterShape({25.f, 25.f}),
      textBox(sf::Vector2f{300.f, 60.f},
              5.f,
              2,
              FRAME_STYLE,
              viewData.getTextStylesheet()) {
  playerMonsterShape.setFillColor(sf::Color::Red);
  playerMonsterShape.setPosition({50.f, 75.f});

  opponentMonsterShape.setFillColor(sf::Color::Blue);
  opponentMonsterShape.setPosition({225.f, 25.f});

  textBox.setPosition({10.f, 110.f});

  viewData.getDefaultTextStyle().applyTo(playerMonsterHPText);
  playerMonsterHPText.setPosition({50.f, 60.f});

  viewData.getDefaultTextStyle().applyTo(opponentMonsterHPText);
  opponentMonsterHPText.setPosition({225.f, 10.f});
}

void BattleScreenView::setPlayerMonster(const Monster* _playerMonster) {
  this->playerMonster = _playerMonster;
}

void BattleScreenView::setOpponentMonster(const Monster* _opponentMonster) {
  this->opponentMonster = _opponentMonster;
}

void BattleScreenView::draw(sf::RenderTarget& target,
                            sf::RenderStates core) const {
  target.draw(playerMonsterShape, core);
  target.draw(opponentMonsterShape, core);
  target.draw(playerMonsterHPText, core);
  target.draw(opponentMonsterHPText, core);
  target.draw(textBox, core);
}

void BattleScreenView::updateHPTexts() {
  playerMonsterHPText.setString(fmt::format(
      "{}/{} HP", playerMonster->getCurrentHP(), playerMonster->getStats().HP));
  opponentMonsterHPText.setString(fmt::format("{}/{} HP",
                                              opponentMonster->getCurrentHP(),
                                              opponentMonster->getStats().HP));
}

void BattleScreenView::update(sf::Time delta) {}

loki::gui::TextBoxView& BattleScreenView::getTextBox() {
  return textBox;
}

}  // namespace mon
#endif
