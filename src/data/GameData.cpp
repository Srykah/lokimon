#include "GameData.hpp"

namespace mon {

void GameData::load() {
  attackList.load();
  speciesList.load();
}

const Species& GameData::getSpecies(const std::string& id) const {
  return speciesList.getSpecies(id);
}

const Attack& GameData::getAttack(const std::string& id) const {
  return attackList.getAttack(id);
}

}  // namespace mon
