/*!
 * \file Species.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <string>
#include <vector>
#include "Attack.hpp"
#include "AttackList.hpp"
#include "Elements.hpp"
#include "models/gameplay/Stats.hpp"

namespace mon {

struct Species {
  TranslatedString names;
  Stats baseStats;
  Element element;
  Family family;
  std::vector<std::pair<unsigned int, AttackIndex>> availableAttacksPerLevel;

  void load(const nlohmann::json& speciesData);
};

}
