/*!
 * \file Player.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <vector>
#include "Monster.hpp"
#include "models/data/Constants.hpp"

namespace mon {

class Player {
 public:
  explicit Player(const GameData& gameData);

  void load();
  [[nodiscard]] const std::string& getName() const { return name; }
  [[nodiscard]] Monster* getPartyMonster(unsigned int index);

 private:
  std::string name;
  std::vector<Monster> box;
  int party[PARTY_SIZE];
  const GameData& gameData;
};

}  // namespace mon
