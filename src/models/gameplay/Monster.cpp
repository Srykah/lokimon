/*!
 * \file Monster.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "Monster.hpp"
#include "models/data/GameData.hpp"

namespace mon {

Monster::Monster(std::string name, mon::SpeciesIndex index, bool isAlly, const GameData& gameData)
: name(std::move(name))
, speciesIndex(index)
, ally(isAlly)
, stats(gameData.getSpecies(index).baseStats)
, battleData({ stats.HP })
, gameData(gameData) {
  for (auto& attack : attacks) {
    attack = AttackIndex::NONE;
  }
}

const Attack* Monster::getAttack(unsigned int index) const {
  if (attacks[index] == AttackIndex::NONE) {
    return nullptr;
  }
  return &gameData.getAttack(attacks[index]);
}

Element Monster::getElement() const {
  return gameData.getSpecies(speciesIndex).element;
}

Family Monster::getFamily() const {
  return gameData.getSpecies(speciesIndex).family;
}

void Monster::loseHP(int i) {
  battleData.HP -= i;
  if (battleData.HP < 0) {
    battleData.HP = 0;
  }
}

}
