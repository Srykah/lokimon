#pragma once

#include "MonsterBattleData.hpp"
#include "Stats.hpp"
#include "data/AttackList.hpp"
#include "data/Constants.hpp"
#include "data/Elements.hpp"
#include "data/SpeciesList.hpp"

namespace mon {

class GameData;

class Monster {
 public:
  using Moveset = std::array<std::string, MOVESET_SIZE>;

 public:
  Monster(std::string name,
          std::string speciesId,
          bool isAlly,
          const GameData& gameData);

  void setAttack(unsigned int movesetIndex, std::string attackId);

  [[nodiscard]] const std::string& getName() const { return name; }
  [[nodiscard]] bool isAlly() const { return ally; }
  [[nodiscard]] int getLevel() const { return level; }
  [[nodiscard]] const Moveset& getMoveset() const { return moveset; }
  [[nodiscard]] const Attack& getAttack(unsigned int movesetIndex) const;
  [[nodiscard]] int getCurrentHP() const { return battleData.HP; }
  [[nodiscard]] const Stats& getStats() const { return stats; }
  [[nodiscard]] Element getElement() const;
  [[nodiscard]] Family getFamily() const;

  void loseHP(int i);

 private:
  std::string name;
  std::string speciesId;
  bool ally;
  int level;
  Stats stats;
  MonsterBattleData battleData;
  Moveset moveset;
  const GameData& gameData;
};

}  // namespace mon
