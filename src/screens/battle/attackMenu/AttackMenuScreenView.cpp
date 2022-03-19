/*!
 * \file AttackMenuScreenView.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "AttackMenuScreenView.hpp"
#include <fmt/format.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include <loki/core/utils/IterAdapters.hpp>

#if 0

namespace mon {

namespace {
const loki::styles::ShapeStyle FRAME_STYLE{
    nullptr, sf::IntRect{}, sf::Color::Blue, sf::Color::White, -3.f};
}

AttackMenuScreenView::AttackMenuScreenView(const ViewData& viewData,
                                           const Monster& monster)
    : menu({300.f, 50.f}, 5.f, FRAME_STYLE, viewData.getDefaultTextStyle()) {
  menu.hide();
}

void AttackMenuScreenView::draw(sf::RenderTarget& target,
                                sf::RenderStates states) const {
  target.draw(menu, states);
}

void AttackMenuScreenView::update(sf::Time time) {
  menu.update(time);
}

}  // namespace mon

#endif
