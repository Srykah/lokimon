#include "AttackMenuScreenView.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <fmt/format.h>

#include <loki/core/utils/IterAdapters.hpp>

#if 0
namespace mon {

namespace {
const loki::gfx::ShapeStyle FRAME_STYLE{
    nullptr, sf::IntRect{}, sf::Color::Blue, sf::Color::White, -3.f};
}

AttackMenuScreenView::AttackMenuScreenView(const ViewData& viewData,
                                           const Monster& monster)
    : menu({300.f, 50.f}, 5.f, FRAME_STYLE, viewData.getDefaultTextStyle()) {
  menu.hide();
}

void AttackMenuScreenView::draw(sf::RenderTarget& target,
                                sf::RenderStates core) const {
  target.draw(menu, core);
}

void AttackMenuScreenView::update(sf::Time time) {
  menu.update(time);
}

}  // namespace mon
#endif
