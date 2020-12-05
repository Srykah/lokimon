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

  void load(const nlohmann::json& statsData);
};

}  // namespace mon
