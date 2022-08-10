/*!
 * \file Species.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include "Attack.hpp"
#include "AttackList.hpp"
#include "Elements.hpp"
#include "gameplay/Stats.hpp"

namespace mon {

struct Species {
  struct MovepoolEntry {
    std::string id;
    int level;
  };

  std::string id;
  Stats baseStats;
  Element element;
  Family family;
  std::vector<MovepoolEntry> movepool;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Species::MovepoolEntry, id, level)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Species,
                                   baseStats,
                                   element,
                                   family,
                                   movepool)

}  // namespace mon
