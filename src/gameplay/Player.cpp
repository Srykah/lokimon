#include "Player.hpp"

#include <fmt/format.h>

namespace mon {

Player::Player(const GameData& gameData) : name("Srykah"), gameData(gameData) {}

void Player::load() {
  box.emplace_back("Coucou", "FireBird", true, gameData);
  box.back().setAttack(0, "BeakHit");
  box.back().setAttack(1, "FireAsh");
  for (auto& index : party) {
    index = -1;
  }
  party[0] = 0;
  mapStatus.mapName = "test";
  mapStatus.pos = sf::Vector2i{8, 6};
  mapStatus.facing = Direction::DOWN;
}

Monster& Player::getPartyMonster(unsigned int index) {
  auto boxIndex = party.at(index);
  if (boxIndex == -1) {
    throw std::out_of_range(fmt::format("Party slot n°{} is empty", index));
  } else {
    return box.at(boxIndex);
  }
}

}  // namespace mon
