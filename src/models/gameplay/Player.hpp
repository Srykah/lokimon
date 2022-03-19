/*!
 * \file Player.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <array>
#include <vector>
#include "Monster.hpp"
#include "models/data/Constants.hpp"

namespace mon {

class Player {
 public:
  explicit Player(const GameData& gameData);

  void load();
  [[nodiscard]] const std::string& getName() const { return name; }
  [[nodiscard]] Monster& getPartyMonster(unsigned int index);

 private:
  std::string name;
  std::vector<Monster> box;
  std::array<int, PARTY_SIZE> party;
  const GameData& gameData;
};

}  // namespace mon
