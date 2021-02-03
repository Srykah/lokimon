/*!
 * \file Player.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <vector>
#include "Monster.hpp"
#include "PlayerMapStatus.hpp"
#include "models/data/Constants.hpp"

namespace mon {

class Player {
 public:
  Player();

  void load(const GameData& gameData);
  [[nodiscard]] const std::string& getName() const { return name; }
  [[nodiscard]] Monster* getPartyMonster(unsigned int index);
  [[nodiscard]] PlayerMapStatus& getMapStatus() { return mapStatus; }

 private:
  std::string name;
  std::vector<Monster> box;
  int party[PARTY_SIZE];
  PlayerMapStatus mapStatus;
};

}  // namespace mon
