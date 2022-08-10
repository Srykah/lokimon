/*!
 * \file Stats.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <nlohmann/json.hpp>

namespace mon {

struct Stats {
  int HP;
  int atk;
  int def;
  int elemAtk;
  int elemDef;
  int speed;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Stats, HP, atk, def, elemAtk, elemDef, speed)

}  // namespace mon
