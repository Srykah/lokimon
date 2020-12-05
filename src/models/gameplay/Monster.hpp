/*!
 * \file Monster.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "Stats.hpp"
#include "models/data/AttackList.hpp"
#include "models/data/Constants.hpp"
#include "models/data/Elements.hpp"
#include "models/data/SpeciesList.hpp"
#include "models/gameplay/BattleData.hpp"

namespace mon {

class GameData;

class Monster {
 public:
  Monster(std::string name,
          SpeciesIndex index,
          bool isAlly,
          const GameData& gameData);

  void setAttack(unsigned int index, AttackIndex attack) {
    attacks[index] = attack;
  }

  [[nodiscard]] const std::string& getName() const { return name; }
  [[nodiscard]] bool isAlly() const { return ally; }
  [[nodiscard]] const Attack* getAttack(unsigned int index) const;
  [[nodiscard]] int getCurrentHP() const { return battleData.HP; }
  [[nodiscard]] const Stats& getStats() const { return stats; }
  [[nodiscard]] Element getElement() const;
  [[nodiscard]] Family getFamily() const;

  void loseHP(int i);


 private:
  std::string name;
  SpeciesIndex speciesIndex;
  bool ally;
  Stats stats;
  BattleData battleData;
  AttackIndex attacks[MOVESET_SIZE];
  const GameData& gameData;
};

}  // namespace mon
