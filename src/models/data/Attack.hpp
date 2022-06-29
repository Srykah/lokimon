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

namespace mon {

struct OffensiveEffect {
  int power = 0;
};

struct PhysicalEffect : public OffensiveEffect {
  Family family = Family::NONE;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(PhysicalEffect, power, family)

struct ElementalEffect : public OffensiveEffect {
  Element element = Element::NONE;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ElementalEffect, power, element)

using Effect = std::variant<PhysicalEffect, ElementalEffect>;

void from_json(const nlohmann::json& j, Effect& e);
void to_json(nlohmann::json& j, const Effect& e);

struct Attack {
  enum class Range { SELF, ALLY, ALL_ALLIES, ENEMY, ALL_ENEMIES, ANY, ALL };

  std::string id;
  Range range = Range::ENEMY;
  int cost = 1;
  int speed = 0;
  std::vector<Effect> effects;
};

NLOHMANN_JSON_SERIALIZE_ENUM(Attack::Range,
                             {
                                 {Attack::Range::SELF, "SELF"},
                                 {Attack::Range::ALLY, "ALLY"},
                                 {Attack::Range::ALL_ALLIES, "ALL_ALLIES"},
                                 {Attack::Range::ENEMY, "ENEMY"},
                                 {Attack::Range::ALL_ENEMIES, "ALL_ENEMIES"},
                                 {Attack::Range::ANY, "ANY"},
                                 {Attack::Range::ALL, "ALL"},
                             })

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Attack, range, cost, speed, effects)

}  // namespace mon
