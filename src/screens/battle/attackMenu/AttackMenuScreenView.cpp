/*!
 * \file AttackMenuScreenView.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackMenuScreenView.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace mon {

AttackMenuScreenView::AttackMenuScreenView(const ViewData& viewData,
                                           const Monster& monster)
    : cursor(5.f, 3),
      introText("What will " + monster.getName() + " do?",
                viewData.getDefaultFont(),
                20) {
  introText.setPosition(50.f, 250.f);
  cursor.setFillColor(sf::Color::White);
  cursor.setOrigin(5.f, 5.f);
  cursor.setRotation(90.f);
  cursor.setPosition(30.f, 320.f);
  for (int i{0}; i < MOVESET_SIZE; ++i) {
    auto atk = monster.getAttack(i);
    if (atk) {
      menu.emplace_back(std::to_string(i + 1) + ". " + atk->names.at("en"),
                        viewData.getDefaultFont(), 15);
      menu.back().setPosition(50.f, 20.f * i + 280.f);
      menu.back().setFillColor(sf::Color::White);
    }
  }
}

void AttackMenuScreenView::draw(sf::RenderTarget& target,
                                sf::RenderStates states) const {
  target.draw(introText, states);
  target.draw(cursor, states);
  for (const auto& line : menu) {
    target.draw(line, states);
  }
}

void AttackMenuScreenView::update(sf::Time time) {}

}  // namespace mon
