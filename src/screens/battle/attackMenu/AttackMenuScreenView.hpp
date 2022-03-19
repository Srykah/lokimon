/*!
 * \file AttackMenuScreenView.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#if 0

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>
#include <loki/gui/menu/grid/GridMenuView.hpp>
#include "core/ViewData.hpp"
#include "models/gameplay/Monster.hpp"

namespace mon {

class AttackMenuScreenView : public sf::Drawable {
 public:
  explicit AttackMenuScreenView(const ViewData& viewData,
                                const Monster& monster);
  void draw(sf::RenderTarget& target,
            sf::RenderStates states = sf::RenderStates()) const override;

  void showMenu() { menu.unhide(); }

  loki::gui::GridMenuView& getMenuView() { return menu; }

  void update(sf::Time time);

 private:
  loki::gui::GridMenuView menu;
};

}

#endif
