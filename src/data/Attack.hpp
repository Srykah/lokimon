#pragma once

#include <map>
#include <string>
#include <variant>
#include <vector>

#include <SFML/System/String.hpp>
#include <nlohmann/json.hpp>

#include <loki/core/json/Variant.hpp>

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
