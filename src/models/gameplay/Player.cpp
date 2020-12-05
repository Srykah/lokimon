/*!
 * \file Player.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */

#include "Player.hpp"

namespace mon {

Player::Player(const GameData& gameData) : name("Srykah"), gameData(gameData) {}

void Player::load() {
  box.emplace_back("Coucou", SpeciesIndex {0}, true, gameData);
  box.back().setAttack(0, AttackIndex{0});
  box.back().setAttack(1, AttackIndex{1});
  for (auto& index : party) {
    index = -1;
  }
  party[0] = 0;
}

Monster* Player::getPartyMonster(unsigned int index) {
  auto boxIndex = party[index];
  if (boxIndex == -1) {
    return nullptr;
  } else {
    return &box[boxIndex];
  }
}

}