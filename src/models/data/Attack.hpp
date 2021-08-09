/*!
 * \file Attack.hpp
 * \author Srykah
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/System/String.hpp>
#include <map>
#include <nlohmann/json.hpp>
#include <string>
#include <variant>
#include <vector>
#include "Elements.hpp"
#include "models/other/TranslatedString.hpp"

namespace mon {

struct OffensiveEffect {
  int power = 0;
  int crit = 0;
  int fail = 0;
};

struct PhysicalEffect : public OffensiveEffect {
  Family family = Family::NONE;
};

struct ElementalEffect : public OffensiveEffect {
  Element element = Element::NONE;
};

struct Attack {
  using Effect = std::variant<PhysicalEffect, ElementalEffect>;
  enum class Range { SELF, ALLY, ALL_ALLIES, ENEMY, ALL_ENEMIES, ANY, ALL };

  void load(const nlohmann::json& attackData);

  TranslatedString names;
  TranslatedString descriptions;
  std::vector<Effect> effects;
  Range range = Range::ENEMY;
  int cost = 1;
  int speed = 0;
};

}  // namespace mon
