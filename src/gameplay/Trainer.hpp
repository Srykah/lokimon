/*!
 * \file Trainer.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <string>
#include <vector>
#include "Monster.hpp"

namespace mon {

struct Trainer {
 public:
  Trainer(std::string name, std::vector<Monster> monsters);

  [[nodiscard]] const std::string& getName() const { return name; }
  [[nodiscard]] Monster& getMonster(unsigned int index) { return monsters.at(index); }
  [[nodiscard]] std::size_t getMonsterCount() const { return monsters.size(); }

 private:
  std::string name;
  std::vector<Monster> monsters;
};

}
