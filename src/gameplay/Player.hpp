/*!
 * \file Player.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <array>
#include <vector>
#include "Monster.hpp"
#include "PlayerMapStatus.hpp"
#include "data/Constants.hpp"

namespace mon {

class Player {
 public:
  explicit Player(const GameData& gameData);

  void load();
  [[nodiscard]] const std::string& getName() const { return name; }
  [[nodiscard]] Monster& getPartyMonster(unsigned int index);
  [[nodiscard]] PlayerMapStatus& getMapStatus() { return mapStatus; }

 private:
  std::string name;
  std::vector<Monster> box;
  std::array<int, PARTY_SIZE> party;
  PlayerMapStatus mapStatus;
  const GameData& gameData;
};

}  // namespace mon
