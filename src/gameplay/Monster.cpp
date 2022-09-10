#include "Monster.hpp"

#include <fmt/format.h>

#include "data/GameData.hpp"

namespace mon {

Monster::Monster(std::string name,
                 std::string speciesId,
                 bool isAlly,
                 const GameData& gameData)
    : name(std::move(name)),
      speciesId(std::move(speciesId)),
      ally(isAlly),
      level(5),
      stats(gameData.getSpecies(this->speciesId).baseStats),
      battleData({stats.HP}),
      gameData(gameData) {}

void Monster::setAttack(unsigned int movesetIndex, std::string attackId) {
  moveset.at(movesetIndex) = std::move(attackId);
}

const Attack& Monster::getAttack(unsigned int movesetIndex) const {
  const auto& attackId = moveset.at(movesetIndex);
  if (attackId.empty()) {
    throw std::out_of_range(
        fmt::format("Moveset slot n°{} is empty", movesetIndex));
  }
  return gameData.getAttack(attackId);
}

Element Monster::getElement() const {
  return gameData.getSpecies(speciesId).element;
}

Family Monster::getFamily() const {
  return gameData.getSpecies(speciesId).family;
}

void Monster::loseHP(int i) {
  battleData.HP -= i;
  if (battleData.HP < 0) {
    battleData.HP = 0;
  }
}

}  // namespace mon
