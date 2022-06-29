/*!
 * \file GameData.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "GameData.hpp"

namespace mon {

void GameData::load() {
  attackList.load();
  speciesList.load();
}

const Species& GameData::getSpecies(std::string id) const {
  return speciesList.getSpecies(id);
}

const Attack& GameData::getAttack(std::string id) const {
  return attackList.getAttack(id);
}

}  // namespace mon
