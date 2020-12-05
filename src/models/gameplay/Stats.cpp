/*!
 * \file Stats.cpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#include "Stats.hpp"

namespace mon {

void Stats::load(const nlohmann::json& statsData) {
  HP = statsData.at("HP").get<int>();
  atk = statsData.at("atk").get<int>();
  def = statsData.at("def").get<int>();
  elemAtk = statsData.at("elemAtk").get<int>();
  elemDef = statsData.at("elemDef").get<int>();
  speed = statsData.at("speed").get<int>();
}

}