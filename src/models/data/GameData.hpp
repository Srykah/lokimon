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
  [[nodiscard]] const Species& getSpecies(SpeciesIndex index) const {
    return speciesList.getSpecies(index);
  }
  [[nodiscard]] const Attack& getAttack(AttackIndex index) const {
    return attackList.getAttack(index);
  }

  void load() {
    attackList.load();
    speciesList.load();
  }

 private:
  SpeciesList speciesList;
  AttackList attackList;
};

}  // namespace mon
