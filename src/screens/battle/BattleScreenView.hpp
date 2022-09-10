#pragma once

#if 0
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>
#include <core/ViewData.hpp>
#include <data/Elements.hpp>
#include <gameplay/Monster.hpp>
#include <gameplay/Player.hpp>
#include <gameplay/Trainer.hpp>

#include <loki/gui/widgets/textBox/TextBoxView.hpp>

namespace mon {

class BattleScreenView : public sf::Drawable {
 public:
  explicit BattleScreenView(const ViewData& viewData);

  void setPlayerMonster(const Monster* playerMonster);
  void setOpponentMonster(const Monster* opponentMonster);

  void update(sf::Time delta);
  void draw(sf::RenderTarget& target, sf::RenderStates core) const override;

  void updateHPTexts();

  [[nodiscard]] loki::gui::TextBoxView& getTextBox();

 private:
  static const loki::gfx::ShapeStyle FRAME_STYLE;

  const Monster* playerMonster = nullptr;
  const Monster* opponentMonster = nullptr;
  sf::RectangleShape playerMonsterShape, opponentMonsterShape;
  sf::Text playerMonsterHPText, opponentMonsterHPText;
  loki::gui::TextBoxView textBox;
};

}
#endif
