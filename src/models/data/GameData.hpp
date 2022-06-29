/*!
 * \file GameData.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "models/data/AttackList.hpp"
#include "models/data/SpeciesList.hpp"

namespace mon {

class GameData {
 public:
  void load();
  [[nodiscard]] const Species& getSpecies(std::string id) const;
  [[nodiscard]] const Attack& getAttack(std::string id) const;

 private:
  SpeciesList speciesList;
  AttackList attackList;
};

}  // namespace mon
