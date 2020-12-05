/*!
 * \file BattleScreenView.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>
#include <core/ViewData.hpp>
#include <loki/gui/textBox/TextBox.hpp>
#include <models/data/Elements.hpp>
#include <models/gameplay/Monster.hpp>
#include <models/gameplay/Player.hpp>
#include <models/gameplay/Trainer.hpp>

namespace mon {

class BattleScreenView : public sf::Drawable {
 public:
  explicit BattleScreenView(const ViewData& viewData);

  void setPlayerMonster(const Monster* playerMonster);
  void setOpponentMonster(const Monster* opponentMonster);

  void update(sf::Time delta);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void updateHPTexts();

  [[nodiscard]] loki::gui::TextBox* getTextBox();

 private:
  const Monster* playerMonster = nullptr;
  const Monster* opponentMonster = nullptr;
  sf::RectangleShape playerMonsterShape, opponentMonsterShape;
  sf::Text playerMonsterHPText, opponentMonsterHPText;
  loki::gui::TextBox textBox;
};

}
