/*!
 * \file PlayerScreen.cpp.c
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "PlayerScreen.hpp"

using loki::input::InputState;

namespace mon {

PlayerScreen::PlayerScreen(Application& app,
                           const loki::tiles::MapData& mapData,
                           MapScreenView& view)
    : BaseScreen(app), mapData(mapData), view(view) {}

void PlayerScreen::init() {
  view.spawnPlayer(getPlayer().getMapStatus().pos,
                   getPlayer().getMapStatus().facing);
}

bool PlayerScreen::update(sf::Time delta) {
  if (getEventHandler().getInputState("up").status == InputState::TRIGGERED) {
    getPlayer().getMapStatus().pos.y -= 1;
    view.movePlayer(Direction::UP);
  } else if (getEventHandler().getInputState("down").status ==
             InputState::TRIGGERED) {
    getPlayer().getMapStatus().pos.y += 1;
    view.movePlayer(Direction::DOWN);
  } else if (getEventHandler().getInputState("left").status ==
             InputState::TRIGGERED) {
    getPlayer().getMapStatus().pos.x -= 1;
    view.movePlayer(Direction::LEFT);
  } else if (getEventHandler().getInputState("right").status ==
             InputState::TRIGGERED) {
    getPlayer().getMapStatus().pos.x += 1;
    view.movePlayer(Direction::RIGHT);
  }
  return true;
}

bool PlayerScreen::updateView(sf::Time delta) {
  return true;
}

bool PlayerScreen::render(sf::RenderTarget& target,
                          sf::RenderStates states) const {
  return true;
}

}  // namespace mon
