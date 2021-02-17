/*!
 * \file PlayerScreen.cpp.c
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "PlayerController.hpp"

using loki::input::InputState;

namespace mon {

PlayerController::PlayerController(
    Player& player,
    const loki::tiles::MapData& mapData,
    const loki::input::EventHandler& eventHandler,
    MapScreenView& view)
    : player(player),
      mapData(mapData),
      eventHandler(eventHandler),
      view(view) {}

void PlayerController::init() {
  view.spawnPlayer(player.getMapStatus().pos, player.getMapStatus().facing);
}

bool PlayerController::update(sf::Time delta) {
  if (eventHandler.getInputState("up").status == InputState::TRIGGERED) {
    player.getMapStatus().pos.y -= 1;
    view.movePlayer(Direction::UP);
  } else if (eventHandler.getInputState("down").status ==
             InputState::TRIGGERED) {
    player.getMapStatus().pos.y += 1;
    view.movePlayer(Direction::DOWN);
  } else if (eventHandler.getInputState("left").status ==
             InputState::TRIGGERED) {
    player.getMapStatus().pos.x -= 1;
    view.movePlayer(Direction::LEFT);
  } else if (eventHandler.getInputState("right").status ==
             InputState::TRIGGERED) {
    player.getMapStatus().pos.x += 1;
    view.movePlayer(Direction::RIGHT);
  }
  return true;
}

bool PlayerController::updateView(sf::Time delta) {
  return true;
}

}  // namespace mon
